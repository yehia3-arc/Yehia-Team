#pragma once
#include "Person.h"
#include "Client.h"
#include <vector>
class FileManager; // Forward declaration

class Employee : public Person {
protected:
    double salary;
public:
    Employee() : Person() {
        salary = 0;
    }
    Employee(int id, const string& name, const string& password, double salary)
        : Person(id, name, password), salary(salary) {
        if (!Validation::isSalary(salary)) {
            cout << "Invalid salary! Minimum salary is 5000.\n";
            this->salary = 5000;
        }
    }
    Employee(const Employee& other)
        : Person(other), salary(other.salary) {
    }
    void setSalary(double salary) {
        if (Validation::isSalary(salary)) {
            this->salary = salary;
        }
        else {
            cout << "Salary must be at least 5000." << endl;
        }
    }
    double getSalary() {
        return salary;
    }
    void displayInfoEmployee() const {
        cout << "Employee info: " << endl;
        Person::displayInfoPerson();
        cout << "salary : " << salary << endl;
    }
    // Client management functions
    void addClient(Client& client);
    Client* searchClient(int id);
    void listClients();
    void editClient(int id, const string& name, const string& password, double balance);
};

