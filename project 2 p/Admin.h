#pragma once
#include "Employee.h"
#include"Person.h"
#include "FileManager.h"
class Admin :
    public Employee
{



    
    public:
        Admin() {
            id = 1;
            name = "Unknown";
            password = "0000";
            salary = 5000;
        }

        Admin(int id, const string& name, const string& password, double salary)
            : Employee(id, name, password, salary) {
        }

        void displayInfoAdmin() {
            cout << "Admin [ID: " << getId()
                << ", Name: " << getName()
                << ", Password: " << getPassword()
                << ", Salary: " << getSalary() << "]\n";
        }

        void addClient(Client& client) {
            FileManager fm;
            fm.addClient(client);
        }

        void listClients() {
            FileManager fm;
            Vector<Client> clients = fm.getAllClients();
            for (int i = 0; i < clients.size(); i++) {
                clients[i].displayInfoClient();
                cout << "---------------------\n";
            }
        }

        void editClient(int id, const string& name, const string& password, double balance) {
            FileManager fm;
            Vector<Client> clients = fm.getAllClients();
            bool found = false;

            for (int i = 0; i < clients.size(); i++) {
                if (clients[i].getId() == id) {
                    clients[i].setName(name);
                    clients[i].setPassword(password);
                    clients[i].setBalance(balance);
                    found = true;
                    break;
                }
            }

            if (found) {
                fm.removeAllClients();
                for (int i = 0; i < clients.size(); i++) {
                    fm.addClient(clients[i]);
                }
                cout << "Client updated successfully.\n";
            }
            else {
                cout << "Client not found.\n";
            }
        }

        void addEmployee(Employee& employee) {
            FileManager fm;
            fm.addEmployee(employee);
        }

        void listEmployees() {
            FileManager fm;
            Vector<Employee> employees = fm.getAllEmployees();
            for (int i = 0; i < employees.size(); i++) {
                employees[i].displayInfoEmployee();
                cout << "---------------------\n";
            }
        }

        void editEmployee(int id, const string& name, const string& password, double salary) {
            FileManager fm;
            Vector<Employee> employees = fm.getAllEmployees();
            bool found = false;

            for (int i = 0; i < employees.size(); i++) {
                if (employees[i].getId() == id) {
                    employees[i].setName(name);
                    employees[i].setPassword(password);
                    employees[i].setSalary(salary);
                    found = true;
                    break;
                }
            }

            if (found) {
                fm.removeAllEmployees();
                for (int i = 0; i < employees.size(); i++) {
                    fm.addEmployee(employees[i]);
                }
                cout << "Employee updated successfully.\n";
            }
            else {
                cout << "Employee not found.\n";
            }
        }
    };


