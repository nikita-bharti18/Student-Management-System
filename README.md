# C++ REST API – Student Management System
 
A lightweight REST API built using C++ that performs CRUD operations for managing student data. This project demonstrates backend development in C++ using header-only libraries.

---
 
##  Overview

This API allows you to:
- Create student records
- Retrieve all or specific students
- Update student details
- Delete students

---

##  Tech Stack

- C++ (C++17)
- cpp-httplib (HTTP server)
- nlohmann/json (JSON handling)

---

##  Project Structure

```
project-folder/
│── main.cpp
│── httplib.h
│── json.hpp
│── README.md
```

---

##  Setup & Run

### 1. Clone Repository

```
git clone https://github.com/your-username/cpp-student-api.git
cd cpp-student-api
```

### 2. Add Dependencies

Download and place in project folder:

- httplib.h → https://github.com/yhirose/cpp-httplib
- json.hpp → https://github.com/nlohmann/json

### 3. Compile

```
g++ main.cpp -o server -std=c++17
```

### 4. Run

```
./server
```

Server runs at:
```
http://localhost:8080
```

---

## 📡 API Endpoints

### GET all students
```
GET /students
```

### GET student by ID
```
GET /students/{id}
```

### POST create student
```
POST /students
```

Body:
```
{
  "id": 1,
  "name": "Rishi",
  "age": 20
}
```

### PUT update student
```
PUT /students/{id}
```

Body:
```
{
  "name": "Updated Name",
  "age": 22
}
```

### DELETE student
```
DELETE /students/{id}
```

---

##  Testing with Curl

### Add Student
```
curl -X POST http://localhost:8080/students \
-H "Content-Type: application/json" \
-d '{"id":1,"name":"Rishi","age":20}'
```

### Get All
```
curl http://localhost:8080/students
```

### Update
```
curl -X PUT http://localhost:8080/students/1 \
-H "Content-Type: application/json" \
-d '{"name":"Updated Name","age":22}'
```

### Delete
```
curl -X DELETE http://localhost:8080/students/1
```

---

##  Features

- REST API in pure C++
- Lightweight and fast
- Header-only dependencies
- Easy to setup
- Beginner-friendly

---

##  Limitations

- In-memory database (resets on restart)
- No authentication
- No persistent storage

---

##  Future Improvements

- Add database (SQLite/MySQL)
- Implement JWT authentication
- Add logging system
- Docker support
- Cloud deployment

---

##  Contributing

1. Fork the repo
2. Create branch
3. Commit changes
4. Open pull request

---

##  License

MIT License

---
##  Author
Nikita Bharti
```
GitHub: https://github.com/nikita-bharti18
```
