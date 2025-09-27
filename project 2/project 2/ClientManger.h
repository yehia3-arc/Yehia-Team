#pragma once
#include "Client.h"
#include "FileManager.h"
#include <iostream>
using namespace std;
class ClientManager {
public:
    static void printClientMenu() {
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit " << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Transfer To Another Client" << endl;
        cout << "5. Update Password" << endl;
        cout << "6. Logout"<< endl;
    }
    static void updatePassword(Person* person) {
        string newPassword;
        cout << "Enter new password: ";
        cin >> newPassword;
        person->setPassword(newPassword);
        cout << "Password updated successfully!"<< endl;
    }
    static Client* login(int id, string password) {
        FileManager fm;
        vector<Client> clients = fm.getAllClients();
        for (int i = 0; i < clients.size(); i++) {
            if (clients[i].getId() == id && clients[i].getPassword() == password) {
                return &clients[i];
            }
        }
        return nullptr;
    }
    static bool clientOptions(Client* client) {
        int choice;
        double amount;
        int recipientId;
        Client* recipient;

        do {
            printClientMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                client->checkBalance();
                break;
            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                client->deposit(amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                client->withdraw(amount);
                break;
            case 4:
                cout << "Enter recipient ID: ";
                cin >> recipientId;
                cout << "Enter amount to transfer: ";
                cin >> amount;
                recipient = new Client(recipientId, "", "", 0);
                client->transferTo(amount, *recipient);
                delete recipient;
                break;
            case 5:
                updatePassword(client);
                break;
            case 6:
                return true;
            default:
                cout << "Invalid choice!" <<endl;
            }
        } while (choice != 6);
        return false;
    }
};