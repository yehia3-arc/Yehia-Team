#include <iostream>
#include <string>
#include "FileManager.h"

int main() {
    FileManager fileManager;
    int choice;
    int userType;

    cout << "Welcome to the Bank System" <<endl;
    cout << "1. Client" <<endl;
   cout << "2. Employee" << endl;
    cout << "3. Admin" << endl;
    cout << "Enter your user type: ";
   cin >> userType;

    if (userType == 1) {
        // Client operations
        int clientId;
      cout << "Enter your client ID: ";
       cin >> clientId;

        Vector<Client> clients = fileManager.getAllClients();
        Client* currentClient = nullptr;

        for (int i = 0; i < clients.size(); i++) {
            if (clients[i].getId() == clientId) {
                currentClient = &clients[i];
                break;
            }
        }

        if (currentClient == nullptr) {
           cout << "Client not found!" << endl;
            return 1;
        }

        do {
            cout << "\nClient Menu:" <<endl;
            cout << "1. Check Balance" <<endl;
            cout << "2. Deposit" <<endl;
            cout << "3. Withdraw" << endl;
           cout << "4. Transfer" << endl;
            cout << "5. Display Info" << endl;
           cout << "0. Exit" << endl;
           cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                currentClient->checkBalance();
                break;
            case 2: {
                double amount;
               cout << "Enter amount to deposit: ";
                cin >> amount;
                currentClient->deposit(amount);
                break;
            }
            case 3: {
                double amount;
                cout << "Enter amount to withdraw: ";
               cin >> amount;
                currentClient->withdraw(amount);
                break;
            }
            case 4: {
                double amount;
                int recipientId;
               cout << "Enter amount to transfer: ";
                cin >> amount;
                cout << "Enter recipient ID: ";
                cin >> recipientId;

                Client* recipient = nullptr;
                for (int i = 0; i < clients.size(); i++) {
                    if (clients[i].getId() == recipientId) {
                        recipient = &clients[i];
                        break;
                    }
                }

                if (recipient != nullptr) {
                    currentClient->transferTo(amount, *recipient);
                }
                else {
                  cout << "Recipient not found!" << endl;
                }
                break;
            }
            case 5:
                currentClient->displayInfoClient();
                break;
            case 0:
                cout << "Exiting..." << std::endl;
                break;
            default:
                cout << "Invalid choice!" << std::endl;
            }
        } while (choice != 0);
    }
    else if (userType == 2) {
        // Employee operations
        int employeeId;
        cout << "Enter your employee ID: ";
        cin >> employeeId;

        Vector<Employee> employees = fileManager.getAllEmployees();
        Employee* currentEmployee = nullptr;

        for (int i = 0; i < employees.size(); i++) {
            if (employees[i].getId() == employeeId) {
                currentEmployee = &employees[i];
                break;
            }
        }

        if (currentEmployee == nullptr) {
           cout << "Employee not found!" << endl;
            return 1;
        }

        do {
            cout << "\nEmployee Menu:" <<endl;
            cout << "1. Add Client" << endl;
            cout << "2. Search Client" << endl;
            cout << "3. List Clients" <<endl;
            cout << "4. Edit Client" << endl;
            cout << "5. Display Info" << endl;
            cout << "0. Exit" <<endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1: {
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
                currentEmployee->addClient(newClient);
                break;
            }
            case 2: {
                int id;
               cout << "Enter client ID to search: ";
              cin >> id;

                Client* client = currentEmployee->searchClient(id);
                if (client != nullptr) {
                    client->displayInfoClient();
                }
                else {
                   cout << "Client not found!" << endl;
                }
                break;
            }
            case 3:
                currentEmployee->listClients();
                break;
            case 4: {
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

                currentEmployee->editClient(id, name, password, balance);
                break;
            }
            case 5:
                currentEmployee->displayInfoEmployee();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
               cout << "Invalid choice!" << endl;
            }
        } while (choice != 0);
    }
    else if (userType == 3) {
        // Admin operations
        int adminId;
       cout << "Enter your admin ID: ";
        cin >> adminId;

        Vector<Admin> admins = fileManager.getAllAdmins();
        Admin* currentAdmin = nullptr;

        for (int i = 0; i < admins.size(); i++) {
            if (admins[i].getId() == adminId) {
                currentAdmin = &admins[i];
                break;
            }
        }

        if (currentAdmin == nullptr) {
            std::cout << "Admin not found!" << std::endl;
            return 1;
        }

        do {
           cout << "\nAdmin Menu:" << endl;
           cout << "1. Add Client" << endl;
            cout << "2. Search Client" << endl;
            cout << "3. List Clients" << endl;
            cout << "4. Edit Client" << endl;
            cout << "5. Add Employee" << endl;
            cout << "6. Search Employee" << endl;
           cout << "7. List Employees" << endl;
           cout << "8. Edit Employee" << endl;
            cout << "9. Display Info" << endl;
            cout << "0. Exit" << endl;
           cout << "Enter your choice: ";
           cin >> choice;

            switch (choice) {
            case 1: {
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
                currentAdmin->addClient(newClient);
                break;
            }
            case 2: {
                int id;
               cout << "Enter client ID to search: ";
               cin >> id;

                Client* client = currentAdmin->searchClient(id);
                if (client != nullptr) {
                    client->displayInfoClient();
                }
                else {
                   cout << "Client not found!" <<endl;
                }
                break;
            }
            case 3:
                currentAdmin->listClients();
                break;
            case 4: {
                int id;
                std::string name, password;
                double balance;

               cout << "Enter client ID to edit: ";
               cin >> id;
             cout << "Enter new name: ";
               cin >> name;
               cout << "Enter new password: ";
                cin >> password;
                cout << "Enter new balance: ";
               cin >> balance;

                currentAdmin->editClient(id, name, password, balance);
                break;
            }
            case 5: {
                int id;
                std::string name, password;
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
                currentAdmin->addEmployee(newEmployee);
                break;
            }
            case 6: {
                int id;
               cout << "Enter employee ID to search: ";
                cin >> id;

                Employee* employee = currentAdmin->searchEmployee(id);
                if (employee != nullptr) {
                    employee->displayInfoEmployee();
                }
                else {
                   cout << "Employee not found!" << endl;
                }
                break;
            }
            case 7:
                currentAdmin->listEmployees();
                break;
            case 8: {
                int id;
               string name, password;
                double salary;

               cout << "Enter employee ID to edit: ";
                cin >> id;
                cout << "Enter new name: ";
               cin >> name;
                cout << "Enter new password: ";
                cin >> password;
               cout << "Enter new salary: ";
                cin >> salary;

                currentAdmin->editEmployee(id, name, password, salary);
                break;
            }
            case 9:
                currentAdmin->displayInfoAdmin();
                break;
            case 0:
                cout << "Exiting..." << std::endl;
                break;
            default:
                cout << "Invalid choice!" << std::endl;
            }
        } while (choice != 0);
    }
    else {
       cout << "Invalid user type!" << std::endl;
        return 1;
    }

    return 0;
}