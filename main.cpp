#include <iostream>
#include <map>
#include "httplib.h"
#include "json.hpp"

using namespace httplib;
using json = nlohmann::json;

struct Student {
    int id;
    std::string name;
    int age;
};

std::map<int, Student> database;

// Convert Student to JSON
json to_json(const Student& s) {
    return {
        {"id", s.id},
        {"name", s.name},
        {"age", s.age}
    };
}

int main() {
    Server svr;

    // GET all students
    svr.Get("/students", [](const Request& req, Response& res) {
        json result = json::array();
        for (auto& [id, student] : database) {
            result.push_back(to_json(student));
        }
        res.set_content(result.dump(), "application/json");
    });

    // GET student by ID
    svr.Get(R"(/students/(\d+))", [](const Request& req, Response& res) {
        int id = std::stoi(req.matches[1]);

        if (database.count(id)) {
            res.set_content(to_json(database[id]).dump(), "application/json");
        } else {
            res.status = 404;
            res.set_content("{\"error\":\"Student not found\"}", "application/json");
        }
    });

    // POST create student
    svr.Post("/students", [](const Request& req, Response& res) {
        auto body = json::parse(req.body);

        Student s;
        s.id = body["id"];
        s.name = body["name"];
        s.age = body["age"];

        database[s.id] = s;

        res.set_content("{\"message\":\"Student added\"}", "application/json");
    });

    // PUT update student
    svr.Put(R"(/students/(\d+))", [](const Request& req, Response& res) {
        int id = std::stoi(req.matches[1]);

        if (!database.count(id)) {
            res.status = 404;
            res.set_content("{\"error\":\"Student not found\"}", "application/json");
            return;
        }

        auto body = json::parse(req.body);

        database[id].name = body["name"];
        database[id].age = body["age"];

        res.set_content("{\"message\":\"Student updated\"}", "application/json");
    });

    // DELETE student
    svr.Delete(R"(/students/(\d+))", [](const Request& req, Response& res) {
        int id = std::stoi(req.matches[1]);

        if (database.erase(id)) {
            res.set_content("{\"message\":\"Student deleted\"}", "application/json");
        } else {
            res.status = 404;
            res.set_content("{\"error\":\"Student not found\"}", "application/json");
        }
    });

    std::cout << "Server running at http://localhost:8080\n";
    svr.listen("0.0.0.0", 8080);
}
