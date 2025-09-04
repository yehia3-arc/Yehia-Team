
#include "Person.h"
#include "Client.h"
#include "Validation.h"
#include "Employee.h"
#include "Admin.h"
#include "Vector.h"
#include "FileHelper.h"
#include "DataSourceInterface.h"
#include "FileManager.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    Vector<Client> clients;
    Vector<Employee> employees;
    Vector<Admin> admins;
    FileManager fileManager;

    int choice;
    do {
        cout << "\n===== Bank System Menu =====\n";
        cout << "1. Client Module\n";
        cout << "2. Employee Module\n";
        cout << "3. Admin Module\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Client Module
            int clientChoice;
            cout << "\n===== Client Module =====\n";
            cout << "1. Login\n";
            cout << "2. Back to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> clientChoice;

            if (clientChoice == 1) {
                int id;
                string password;
                cout << "Enter your ID: ";
                cin >> id;
                cout << "Enter your password: ";
                cin >> password;

                // In a real system, we would validate against stored data
                Client client(id, "Test Client", password, 2000);

                int loggedInChoice;
                do {
                    cout << "\n===== Client Menu =====\n";
                    cout << "1. Deposit\n";
                    cout << "2. Withdraw\n";
                    cout << "3. Check Balance\n";
                    cout << "4. Transfer Money\n";
                    cout << "5. Display Info\n";
                    cout << "6. Logout\n";
                    cout << "Enter your choice: ";
                    cin >> loggedInChoice;

                    switch (loggedInChoice) {
                    case 1: {
                        double amount;
                        cout << "Enter amount to deposit: ";
                        cin >> amount;
                        client.deposit(amount);
                        break;
                    }
                    case 2: {
                        double amount;
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;
                        client.withdraw(amount);
                        break;
                    }
                    case 3:
                        client.checkBalance();
                        break;
                    case 4: {
                        double amount;
                        int recipientId;
                        cout << "Enter amount to transfer: ";
                        cin >> amount;
                        cout << "Enter recipient ID: ";
                        cin >> recipientId;
                        Client recipient(recipientId, "Recipient", "password", 2000);
                        client.transferTo(amount, recipient);
                        break;
                    }
                    case 5:
                        client.displayInfoClient();
                        break;
                    case 6:
                        cout << "Logging out...\n";
                        break;
                    default:
                        cout << "Invalid choice!\n";
                    }
                } while (loggedInChoice != 6);
            }
            break;
        }
        case 2: {
            // Employee Module
            int employeeChoice;
            cout << "\n===== Employee Module =====\n";
            cout << "1. Login\n";
            cout << "2. Back to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> employeeChoice;

            if (employeeChoice == 1) {
                int id;
                string password;
                cout << "Enter your ID: ";
                cin >> id;
                cout << "Enter your password: ";
                cin >> password;

                // In a real system, we would validate against stored data
                Employee employee(id, "Test Employee", password, 6000);

                int loggedInChoice;
                do {
                    cout << "\n===== Employee Menu =====\n";
                    cout << "1. Add New Client\n";
                    cout << "2. Search for Client\n";
                    cout << "3. List All Clients\n";
                    cout << "4. Edit Client Info\n";
                    cout << "5. Display My Info\n";
                    cout << "6. Logout\n";
                    cout << "Enter your choice: ";
                    cin >> loggedInChoice;

                    switch (loggedInChoice) {
                    case 1: {
                        int id;
                        string name, password;
                        double balance;
                        cout << "Enter client ID: ";
                        cin >> id;
                        cout << "Enter client name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter client password: ";
                        cin >> password;
                        cout << "Enter client balance: ";
                        cin >> balance;
                        Client newClient(id, name, password, balance);
                        employee.addClient(newClient);
                        fileManager.addClient(newClient);
                        break;
                    }
                    case 2: {
                        int id;
                        cout << "Enter client ID to search: ";
                        cin >> id;
                        employee.searchClient(id);
                        break;
                    }
                    case 3:
                        employee.listClients();
                        fileManager.getAllClients();
                        break;
                    case 4: {
                        int id;
                        string name, password;
                        double balance;
                        cout << "Enter client ID to edit: ";
                        cin >> id;
                        cout << "Enter new name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter new password: ";
                        cin >> password;
                        cout << "Enter new balance: ";
                        cin >> balance;
                        employee.editClient(id, name, password, balance);
                        break;
                    }
                    case 5:
                        employee.displayInfoEmployee();
                        break;
                    case 6:
                        cout << "Logging out...\n";
                        break;
                    default:
                        cout << "Invalid choice!\n";
                    }
                } while (loggedInChoice != 6);
            }
            break;
        }
        case 3: {
            // Admin Module
            int adminChoice;
            cout << "\n===== Admin Module =====\n";
            cout << "1. Login\n";
            cout << "2. Back to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> adminChoice;

            if (adminChoice == 1) {
                int id;
                string password;
                cout << "Enter your ID: ";
                cin >> id;
                cout << "Enter your password: ";
                cin >> password;

                // In a real system, we would validate against stored data
                Admin admin(id, "Test Admin", password, 8000);

                int loggedInChoice;
                do {
                    cout << "\n===== Admin Menu =====\n";
                    cout << "1. Add New Employee\n";
                    cout << "2. Search for Employee\n";
                    cout << "3. Edit Employee\n";
                    cout << "4. List All Employees\n";
                    cout << "5. Add New Client\n";
                    cout << "6. Search for Client\n";
                    cout << "7. Edit Client\n";
                    cout << "8. List All Clients\n";
                    cout << "9. Display My Info\n";
                    cout << "10. Logout\n";
                    cout << "Enter your choice: ";
                    cin >> loggedInChoice;

                    switch (loggedInChoice) {
                    case 1: {
                        int id;
                        string name, password;
                        double salary;
                        cout << "Enter employee ID: ";
                        cin >> id;
                        cout << "Enter employee name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter employee password: ";
                        cin >> password;
                        cout << "Enter employee salary: ";
                        cin >> salary;
                        Employee newEmployee(id, name, password, salary);
                        admin.addEmployee(newEmployee);
                        fileManager.addEmployee(newEmployee);
                        break;
                    }
                    case 2: {
                        int id;
                        cout << "Enter employee ID to search: ";
                        cin >> id;
                        admin.searchEmployee(id);
                        break;
                    }
                    case 3: {
                        int id;
                        string name, password;
                        double salary;
                        cout << "Enter employee ID to edit: ";
                        cin >> id;
                        cout << "Enter new name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter new password: ";
                        cin >> password;
                        cout << "Enter new salary: ";
                        cin >> salary;
                        admin.editEmployee(id, name, password, salary);
                        break;
                    }
                    case 4:
                        admin.listEmployees();
                        fileManager.getAllEmployees();
                        break;
                    case 5: {
                        int id;
                        string name, password;
                        double balance;
                        cout << "Enter client ID: ";
                        cin >> id;
                        cout << "Enter client name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter client password: ";
                        cin >> password;
                        cout << "Enter client balance: ";
                        cin >> balance;
                        Client newClient(id, name, password, balance);
                        admin.addClient(newClient);
                        fileManager.addClient(newClient);
                        break;
                    }
                    case 6: {
                        int id;
                        cout << "Enter client ID to search: ";
                        cin >> id;
                        admin.searchClient(id);
                        break;
                    }
                    case 7: {
                        int id;
                        string name, password;
                        double balance;
                        cout << "Enter client ID to edit: ";
                        cin >> id;
                        cout << "Enter new name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter new password: ";
                        cin >> password;
                        cout << "Enter new balance: ";
                        cin >> balance;
                        admin.editClient(id, name, password, balance);
                        break;
                    }
                    case 8:
                        admin.listClients();
                        fileManager.getAllClients();
                        break;
                    case 9:
                        admin.displayInfoAdmin();
                        break;
                    case 10:
                        cout << "Logging out...\n";
                        break;
                    default:
                        cout << "Invalid choice!\n";
                    }
                } while (loggedInChoice != 10);
            }
            break;
        }
        case 4:
            cout << "Exiting Bank System. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}