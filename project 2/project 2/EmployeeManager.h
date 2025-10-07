#pragma once
#include "Employee.h"
#include "FileManager.h"
#include <iostream>
using namespace std;

class EmployeeManager {
public:
    static void printEmployeeMenu() {
        cout << "1. Add New Client" << endl;
        cout << "2. List All Clients" << endl;
        cout << "3. Search For Client" << endl;
        cout << "4. Edit Client Info" << endl;
        cout << "5. Logout" << endl;
    }

    static void newClient(Employee* employee) {
        int id;
        string name, password;
        double balance;

        cout << "Enter client ID: ";
        cin >> id;
        cout << "Enter client name: ";
        cin >> name;
        cout << "Enter client password: ";
        cin >> password;
        cout << "Enter client balance: ";
        cin >> balance;

        Client newClient(id, name, password, balance);
        employee->addClient(newClient);
        cout << "Client added successfully!\n";
    }

    static void listAllClients(Employee* employee) {
        employee->listClients();
    }

    static void searchForClient(Employee* employee) {
        int id;
        cout << "Enter client ID to search: ";
        cin >> id;
        Client* client = employee->searchClient(id);
        if (client != nullptr) {
            client->displayInfoClient();
            delete client;
        }
        else {
            cout << "Client not found!"<<endl;
        }
    }

    static void editClientInfo(Employee* employee) {
        int id;
        string name, password;
        double balance;

        cout << "Enter client ID to edit: ";
        cin >> id;
        cout << "Enter new name: ";
        cin >> name;
        cout << "Enter new password: ";
        cin >> password;
        cout << "Enter new balance: ";
        cin >> balance;

        employee->editClient(id, name, password, balance);
        cout << "Client info updated successfully!"<<endl;
    }

    static Employee* login(int id, string password) {
        FileManager fm;
        vector<Employee> employees = fm.getAllEmployees();
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i].getId() == id && employees[i].getPassword() == password) {
                return &employees[i];
            }
        }
        return nullptr;
    }

    static bool employeeOptions(Employee* employee) {
        int choice;
        do {
            printEmployeeMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                newClient(employee);
                break;
            case 2:
                listAllClients(employee);
                break;
            case 3:
                searchForClient(employee);
                break;
            case 4:
                editClientInfo(employee);
                break;
            case 5:
                return true;
            default:
                cout << "Invalid choice!" << endl;
            }
        } while (choice != 5);
        return false;
    }
};

