#pragma once
#include "Person.h"
#include "Client.h"
#include "FilesHelper.h"
#include "Vector.h"

class Employee : public Person
{
protected:
    double salary;
    double MinSalary;
public:
    Employee() :Person() {
        salary = 0;
    }
    Employee(int id, string name, string password, double salary) : Person(id, name, password) {
        set_salary(salary);
    }
    void set_salary(double salary) {
        if (salary >= 5000) {
            this->salary = salary;
        }
        else {
            cout << "Salary must be at least 5000." << endl;
        }
    }
    double getSalary() {
        return salary;
    }
    void displayInfoEmployee() {
        cout << "Employee info: " << endl;
        Person::displayInfoPerson();
        cout << "salary : " << salary << endl;
    }


    void addClient(Client c) {
        FilesHelper::saveClient(c);
    }


    Client* searchClient(int id) {
        Vector<Client> clients = FilesHelper::getClients();
        for (int i = 0; i < clients.size(); i++) {
            if (clients[i].getId() == id) {
                return &clients[i];
            }
        }
        return nullptr;
    }


    void listClient() {
        Vector<Client> clients = FilesHelper::getClients();
        for (int i = 0; i < clients.size(); i++) {
            clients[i].displayInfoClient();
            cout << "-------------------" << endl;
        }
    }


    void editClient(int id, string name, string password, double balance) {
        Vector<Client> clients = FilesHelper::getClients();
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
            FilesHelper::clearClientsFile("Clients.txt", "lastClientId.txt");
            for (int i = 0; i < clients.size(); i++) {
                FilesHelper::saveClient(clients[i]);
            }
            cout << "Client updated successfully." << endl;
        }
        else {
            cout << "Client with ID " << id << " not found." << endl;
        }
    }
};