#pragma once
#include "ClientManger.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
#include <iostream>
using namespace std;

class Screens {
public:
    static void bankName() {
        cout << "============================="<<endl;
        cout << "      BANK MANAGEMENT SYSTEM"<<endl;
        cout << "============================="<<endl;
    }

    static void welcome() {
        bankName();
        cout << "Welcome to banking system!"<<endl;
    }

    static void loginOptions() {
        cout << "1. Login as Client" << endl;
        cout << "2. Login as Employee"<<endl;
        cout << "3. Login as Admin"<<endl;
        cout << "4. Exit"<<endl;
    }

    static int loginAs() {
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        return choice;
    }

    static void invalid(int c) {
        cout << "Invalid choice: " << c << endl;
    }

    static void logout() {
        cout << "Logging out..." << endl;
    }

    static void loginScreen(int c) {
        int id;
        string password;
        cout << "Enter your ID: ";
        cin >> id;
        cout << "Enter your password: ";
        cin >> password;

        switch (c) {
        case 1: {
            Client* client = ClientManager::login(id, password);
            if (client != nullptr) {
                ClientManager::clientOptions(client);
            }
            else {
                cout << "Invalid credentials!\n";
            }
            break;
        }
        case 2: {
            Employee* employee = EmployeeManager::login(id, password);
            if (employee != nullptr) {
                EmployeeManager::employeeOptions(employee);
            }
            else {
                cout << "Invalid credentials!"<<endl;
            }
            break;
        }
        case 3: {
            Admin* admin = AdminManager::login(id, password);
            if (admin != nullptr) {
                AdminManager::adminOptions(admin);
            }
            else {
                cout << "Invalid credentials!\n";
            }
            break;
        }
        }
    }

    static void runApp() {
        int choice;
        do {
            welcome();
            loginOptions();
            choice = loginAs();

            if (choice >= 1 && choice <= 3) {
                loginScreen(choice);
            }
            else if (choice != 4) {
                invalid(choice);
            }
        } while (choice != 4);
        cout << "goodbye for using bank system , see you later !";
    }
};

