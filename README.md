# Student Database Management System

This project is a simple Student Database Management System implemented in C++ using MySQL. The system allows you to perform CRUD (Create, Read, Update, Delete) operations on a `student` database.

## Features

- **Insert Data**: Add a new student record to the database.
- **Delete Data**: Remove an existing student record from the database.
- **Update Data**: Modify the grade of an existing student.
- **Read Data**: Display all student records from the database.

## Concepts Used

- Object-oriented programming (OOP)
- Class, inheritance
- MySQL database integration

## Requirements

- C++ compiler
- MySQL database server

  
**MySQL Database Integration with C++**

**Introduction**
MySQL is a popular relational database management system (RDBMS) used for storing and managing structured data. Integrating MySQL with a C++ project allows you to perform database operations such as querying, inserting, updating, and deleting data from within your C++ application.

**MySQL Connector/C++**
MySQL Connector/C++ is a C++ client library provided by MySQL for connecting C++ applications to MySQL databases. It offers a modern, object-oriented interface for interacting with MySQL databases, making database integration in C++ projects more convenient.

**Key Concepts**
Object-oriented Programming (OOP)
Object-oriented programming (OOP) is a programming paradigm that organizes software design around objects and data rather than actions and logic. In this project, OOP principles are applied to model entities like students as objects, with attributes and behaviors encapsulated within classes.

**Class, Inheritance**
Class ,inheritance is a fundamental concept in OOP where a class (subclass or derived class) inherits properties and behaviors (attributes and methods) from another class (superclass or base class). In this project, class inheritance is used to create specialized classes like AddStudent and DeleteStudent that inherit common attributes and behaviors from the base Student class.

**MySQL Database Integration**
MySQL database integration involves connecting a C++ application to a MySQL database and performing database operations such as querying, inserting, updating, and deleting data. In this project, MySQL Connector/C++ is utilized to establish a connection to the MySQL database and execute SQL queries to interact with student records.

**MySQL Connector/C++ Usage**
MySQL Connector/C++ provides classes and methods for connecting to MySQL databases, executing SQL queries, and handling database operations. Here's a brief overview of how MySQL Connector/C++ is used in this project:

**Establishing Connection:** The mysql_init() function initializes a MySQL object, and mysql_real_connect() establishes a connection to the MySQL database server.
Executing Queries: SQL queries are constructed using string manipulation (e.g., stringstream), and mysql_query() is used to execute these queries on the database.
Handling Results: Results of SELECT queries are retrieved using mysql_store_result() and processed row by row using mysql_fetch_row().
Conclusion
Integrating MySQL with a C++ project using MySQL Connector/C++ allows for efficient and robust database operations within the C++ application. By leveraging OOP principles and class inheritance, along with the capabilities of MySQL Connector/C++, you can build powerful database-driven applications in C++.

This theoretical overview provides insight into the concepts and techniques used to integrate MySQL with C++ project, facilitating effective database management and manipulation.

![WhatsApp Image 2024-07-19 at 2 00 15 PM](https://github.com/user-attachments/assets/09624d23-552f-4a00-b39a-09b346d2988b)

