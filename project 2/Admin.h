#pragma once


#include"Employee.h"
  
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

    void addEmployee(Employee& employee);
    Employee* searchEmployee(int id);
    void listEmployees();
    void editEmployee(int id, const string& name, const string& password, double salary);
    void addClient(Client& client);
    Client* searchClient(int id);
    void listClients();
    void editClient(int id, const std::string& name, const std::string& password, double balance);
 };