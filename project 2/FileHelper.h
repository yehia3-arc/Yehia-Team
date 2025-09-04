#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Vector.h"
#include"DataSourceInterface.h"

#include "Admin.h"
#include "Parser.h"
using namespace std;
class FileHelper
{
public:
   static void saveLast(string fileName, int id) {
        ofstream file(fileName);
        if (file.is_open()) {
            file << id;
            file.close();
        }
    }

    static int getLast(string fileName) {
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
            file << c.getId() << "|" << c.getName() << "|" << c.getPassword() << "|" << c.getBalance() << endl;
            file.close();
        }
    }

    static void saveEmployee(string fileName, string lastIdFile, Employee e) {
        ofstream file(fileName, ios::app);
        if (file.is_open()) {
            file << e.getId() << "|" << e.getName() << "|" << e.getPassword() << "|" << e.getSalary() << endl;
            file.close();
            saveLast(lastIdFile, e.getId());
        }
    }
    static void saveAdmin(Admin a) {
        ofstream file("Admins.txt", ios::app);
        if (file.is_open()) {
            file << a.getId() << "|" << a.getName() << "|"
                << a.getPassword() << "|" << a.getSalary() << endl;
            file.close();
            saveLast("LastAdminID.txt", a.getId());
        }
    }
    static void getClients() {
        ifstream file("Clients.txt");
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        }
    }

    static void getEmployees() {
        ifstream file("Employees.txt");
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        }
    }

    static void getAdmins() {
        ifstream file("Admins.txt");
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        }
    }

    static void clearFile(string fileName, string lastIdFile) {
        ofstream file(fileName, ios::trunc);
        file.close();
        saveLast(lastIdFile, 0);
    }
};

