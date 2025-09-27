#pragma once
#include "Admin.h"
#include "FileManager.h"
#include <iostream>
using namespace std;

class AdminManager {
public:
    static void printAdminMenu() {
        cout << "1. Add New Employee" << endl;
        cout << "2. Add New Client" << endl;
        cout << "3. List All Employees" << endl;
        cout << "4. List All Clients" << endl;
        cout << "5. Search For Employee" << endl;
        cout << "6. Search For Client" << endl;
        cout << "7. Edit Employee Info" << endl;
        cout << "8. Edit Client Info" << endl;
        cout << "9. Logout" << endl;
    }

    static Admin* login(int id, string password) {
        FileManager fm;
        vector<Admin> admins = fm.getAllAdmins();
        for (int i = 0; i < admins.size(); i++) {
            if (admins[i].getId() == id && admins[i].getPassword() == password) {
                return &admins[i];
            }
        }
        return nullptr;
    }
    static void newEmployee(Admin* admin) {
        int id;
        string name, password;
        double salary;

        cout << "Enter employee ID: ";
        cin >> id;
        cout << "Enter employee name: ";
        cin >> name;

        cout << "Enter employee password: ";
        cin >> password;
        cout << "Enter employee salary: ";
        cin >> salary;

        Employee newEmployee(id, name, password, salary);
        admin->addEmployee(newEmployee);
        cout << "Employee added successfully!" << endl;
    }

    static void newClient(Admin* admin) {
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
        admin->addClient(newClient);
        cout << "Client added successfully!" << endl;
    }

    static void listAllEmployees(Admin* admin) {
        admin->listEmployees();
    }

    static void listAllClients(Admin* admin) {
        admin->listClients();
    }

    static void searchForEmployee(Admin* admin) {
        int id;
        cout << "Enter employee ID to search: ";
        cin >> id;
        Employee* employee = admin->searchEmployee(id);
        if (employee != nullptr) {
            employee->displayInfoEmployee();
        }
        else {
            cout << "Employee not found!" << endl;
        }
    }

    static void searchForClient(Admin* admin) {
        int id;
        cout << "Enter client ID to search: ";
        cin >> id;
        Client* client = admin->searchClient(id);
        if (client != nullptr) {
            client->displayInfoClient();
        }
        else {
            cout << "Client not found!" << endl;
        }
    }

    static void editEmployeeInfo(Admin* admin) {
        int id;
        string name, password;
        double salary;

        cout << "Enter employee ID to edit: ";
        cin >> id;
        cout << "Enter new name: ";

        getline(cin, name);
        cout << "Enter new password: ";
        cin >> password;
        cout << "Enter new salary: ";
        cin >> salary;

        admin->editEmployee(id, name, password, salary);
        cout << "Employee info updated successfully!" << endl;
    }

    static void editClientInfo(Admin* admin) {
        int id;
        string name, password;
        double balance;

        cout << "Enter client ID to edit: ";
        cin >> id;
        cout << "Enter new name: ";

        getline(cin, name);
        cout << "Enter new password: ";
        cin >> password;
        cout << "Enter new balance: ";
        cin >> balance;

        admin->editClient(id, name, password, balance);
        cout << "Client info updated successfully!" << endl;
    }
    static bool adminOptions(Admin* admin) {
        int choice;
        do {
            printAdminMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                newEmployee(admin);
                break;
            case 2:
                newClient(admin);
                break;
            case 3:
                listAllEmployees(admin);
                break;
            case 4:
                listAllClients(admin);
                break;
            case 5:
                searchForEmployee(admin);
                break;
            case 6:
                searchForClient(admin);
                break;
            case 7:
                editEmployeeInfo(admin);
                break;
            case 8:
                editClientInfo(admin);
                break;
            case 9:
                return true;
            default:
                cout << "Invalid choice!" << endl;
            }
        } while (choice != 9);
        return false;
    }
   
};
