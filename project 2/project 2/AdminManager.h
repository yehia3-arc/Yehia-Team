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

    static bool adminOptions(Admin* admin) {
        int choice;
        do {
            printAdminMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
               
            case 9:
                return true;
            default:
                cout << "Invalid choice!\n";
            }
        } while (choice != 9);
        return false;
    }
};
