#pragma once
#include "DataSourceInterface.h"
#include "FileHelper.h"

class FileManager : public DataSourceInterface {
private:
    string clientFile = "Clients.txt";
    string employeeFile = "Employees.txt";


public:
    void addClient(Client client) {
        FilesHelper::saveClient(client);
    }

    void addEmployee(Employee employee) {
        FilesHelper::saveEmployee(employeeFile, "lastEmployeeId.txt", employee);
    }


    Vector<Client> getAllClients() {
        return FilesHelper::getClients();
    }

    Vector<Employee> getAllEmployees() {
        return FilesHelper::getEmployees();
    }

    void removeAllClients() {
        FilesHelper::clearFile(clientFile, "lastClientId.txt");
    }

    void removeAllEmployees() {
        FilesHelper::clearFile(employeeFile, "lastEmployeeId.txt");
    }


};
#include "FileManager.h"
void Employee::addClient(Client& client) {
    FileManager fm;
    fm.addClient(client);
}

Client* Employee::searchClient(int id) {
    FileManager fm;
    Vector<Client> clients = fm.getAllClients();
    for (int i = 0; i < clients.size(); i++) {
        if (clients[i].getId() == id) {
            return &clients[i];
        }
    }
    return nullptr;
}

void Employee::listClients() {
    FileManager fm;
    Vector<Client> clients = fm.getAllClients();
    for (int i = 0; i < clients.size(); i++) {
        clients[i].displayInfoClient();
        cout << "---------------------" << endl;
    }
}

void Employee::editClient(int id, const string& name, const string& password, double balance) {
    FileManager fm;
    Vector<Client> clients = fm.getAllClients();
    for (int i = 0; i < clients.size(); i++) {
        if (clients[i].getId() == id) {
            clients[i].setName(name);
            clients[i].setPassword(password);
            clients[i].setBalance(balance);
            break;
        }
    }
    fm.removeAllClients();
    for (int i = 0; i < clients.size(); i++) {
        fm.addClient(clients[i]);
    }
}
