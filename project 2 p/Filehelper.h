#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Parser.h"
#include "Vector.h"
#include "Client.h"
#include "Employee.h"

using namespace std;

class FilesHelper {
public:

    static void saveClient(string fileName, string lastIdFile, Client c) {
        ofstream file(fileName, ios::app);
        if (file.is_open()) {
            file << c.getId() << "|"
                << c.getName() << "|"
                << c.getPassword() << "|"
                << c.getBalance() << endl;
            file.close();
        }
        saveLast(lastIdFile, to_string(c.getId()));
    }

    static Vector<Client> getClients() {
        Vector<Client> clients;
        ifstream file("Clients.txt");
        string line;
        while (getline(file, line)) {
            clients.push_back(Parser::parseToClient(line));
        }
        file.close();
        return clients;
    }

    static void clearClientsFile(string fileName, string lastIdFile) {
        ofstream file(fileName, ios::trunc);
        file.close();
        saveLast(lastIdFile, "0");
    }

    static void saveEmployee(string fileName, string lastIdFile, Employee e) {
        ofstream file(fileName, ios::app);
        if (file.is_open()) {
            file << e.getId() << "|"
                << e.getName() << "|"
                << e.getPassword() << "|"
                << e.getSalary() << endl;
            file.close();
        }
        saveLast(lastIdFile, to_string(e.getId()));
    }

    static Vector<Employee> getEmployees() {
        Vector<Employee> employees;
        ifstream file("Employees.txt");
        string line;
        while (getline(file, line)) {
            employees.push_back(Parser::parseToEmployee(line));
        }
        file.close();
        return employees;
    }

    static void clearEmployeesFile(string fileName, string lastIdFile) {
        ofstream file(fileName, ios::trunc);
        file.close();
        saveLast(lastIdFile, "0");
    }

    static void saveLast(string lastIdFile, string lastId) {
        ofstream file(lastIdFile, ios::trunc);
        if (file.is_open()) {
            file << lastId;
            file.close();
        }
    }

    static string getLast(string lastIdFile) {
        ifstream file(lastIdFile);
        string id = "0";
        if (file.is_open()) {
            file >> id;
            file.close();
        }
        return id;
    }
    static void saveClient(const Client& c) {
        saveClient("Clients.txt", "lastClientId.txt", c);
    }


    static void saveEmployee(const Employee& e) {
        saveEmployee("Employees.txt", "lastEmployeeId.txt", e);
    }
};

