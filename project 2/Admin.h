#pragma once

#include <string>
#include <iostream>

#include"Employee.h"
#include"FileManager.h"
class Admin : public Employee {
    
public:
    Admin() : Employee() {}

    // Parameterized constructor
    Admin(int id, const string& name, const string& password, double salary)
        : Employee(id, name, password, salary) {
    }

    // Copy constructor
    Admin(const Admin& other) : Employee(other) {}

    // Display function
    void displayInfoAdmin()  {
        cout << "Admin - ";
        Employee::displayInfoEmployee();
    }

    void addClient(Client& client) {
        // Implementation would be in FileManager
        cout << "Client added by admin.\n";
    }

    Client* searchClient(int id) {
        // Implementation would search in files
        cout << "Searching for client with ID: " << id << endl;
        return nullptr;
    }

    void listClients() {
        // Implementation would list all clients from file
        cout << "Listing all clients...\n";
    }

    void editClient(int id, string name, string password, double balance) {
        // Implementation would edit client in file
        cout << "Editing client with ID: " << id << endl;
    }

    void addEmployee(Employee& employee) {
        // Implementation would be in FileManager
        cout << "Employee added by admin.\n";
    }

    Employee* searchEmployee(int id) {
        // Implementation would search in files
        cout << "Searching for employee with ID: " << id << endl;
        return nullptr;
    }

    void editEmployee(int id, string name, string password, double salary) {
        // Implementation would edit employee in file
        cout << "Editing employee with ID: " << id << endl;
    }

    void listEmployees() {
        // Implementation would list all employees from file
        cout << "Listing all employees...\n";
    }
 };