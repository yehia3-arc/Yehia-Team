#pragma once
#include <fstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"

class FilesHelper {
public:
    static void saveLast(const string& fileName, int id) {
        ofstream file(fileName);
        if (file.is_open()) {
            file << id;
            file.close();
        }
    }

    static int getLast(const string& fileName) {
       ifstream file(fileName);
        int id = 0;
        if (file.is_open()) {
            file >> id;
            file.close();
        }
        return id;
    }

    static void saveClient(Client c) {
       ofstream file("Clients.txt", ios::app);
        if (file.is_open()) {
            file << c.getId() << "|" << c.getName() << "|"
                << c.getPassword() << "|" << c.getBalance() << endl;
            file.close();
        }
        saveLast("lastClientId.txt", c.getId());
    }

    static void saveEmployee(const string& fileName, const string& lastIdFile, Employee e) {
     ofstream file(fileName, ios::app);
        if (file.is_open()) {
            file << e.getId() << "|" << e.getName() << "|"
                << e.getPassword() << "|" << e.getSalary() << endl;
            file.close();
        }
        saveLast(lastIdFile, e.getId());
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
    static void saveAdmin(Admin a) {
        ofstream file("Admins.txt", ios::app);
        if (file.is_open()) {
            file << a.getId() << "|" << a.getName() << "|"
                << a.getPassword() << "|" << a.getSalary() << endl;
            file.close();
        }
        saveLast("lastAdminId.txt", a.getId());
    }

    static Vector<Admin> getAdmins() {
        Vector<Admin> admins;
      ifstream file("Admins.txt");
        string line;
        while (getline(file, line)) {
            admins.push_back(Parser::parseToAdmin(line));
        }
        file.close();
        return admins;
    }

    static void clearFile(const string& fileName, const string& lastIdFile) {
      ofstream file(fileName, ios::trunc);
        file.close();
        saveLast(lastIdFile, 0);
    }
};
