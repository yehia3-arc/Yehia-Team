#pragma once
#include "DataSourceInterface.h"
#include "FileHelper.h"
class FileManager : public DataSourceInterface {
private:
   string clientFile = "Clients.txt";
    string employeeFile = "Employees.txt";
    string adminFile = "Admins.txt";

public:
    void addClient(Client client)  {
        FilesHelper::saveClient(client);
    }
    void addEmployee(Employee employee)  {
        FilesHelper::saveEmployee(employeeFile, "lastEmployeeId.txt", employee);
    }
    void addAdmin(Admin admin)  {
        FilesHelper::saveEmployee(adminFile, "lastAdminId.txt", admin);
    }
    vector<Client> getAllClients()  {
        return FilesHelper::getClients();
    }
    vector<Employee> getAllEmployees()  {
        return FilesHelper::getEmployees();
    }
    vector<Admin> getAllAdmins()  {
        return FilesHelper::getAdmins();
    }
    void removeAllClients()  {
        FilesHelper::clearFile(clientFile, "lastClientId.txt");
    }
    void removeAllEmployees()  {
        FilesHelper::clearFile(employeeFile, "lastEmployeeId.txt");
    }
    void removeAllAdmins()  {
        FilesHelper::clearFile(adminFile, "lastAdminId.txt");
    }
};
#include "FileManager.h"
void Employee::addClient(Client& client) {
    FileManager fm;
    fm.addClient(client);
}

Client* Employee::searchClient(int id) {
    FileManager fm;
    vector<Client> clients = fm.getAllClients();
    for (int i = 0; i < clients.size(); i++) {
        if (clients[i].getId() == id) {
            return  new Client(clients [i]);
           
        }
    } 
    return nullptr;
}

void Employee::listClients() {
    FileManager fm;
    vector<Client> clients = fm.getAllClients();
    for (int i = 0; i < clients.size(); i++) {
        clients[i].displayInfoClient();
        cout << "---------------------" << endl;
    }
}

void Employee::editClient(int id, const string& name, const string& password, double balance) {
    FileManager fm;
    vector<Client> clients = fm.getAllClients();
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

// Implement Admin methods that use FileManager
void Admin::addEmployee(Employee& employee) {
    FileManager fm;
    fm.addEmployee(employee);
}

Employee* Admin::searchEmployee(int id) {
    FileManager fm;
    vector<Employee> employees = fm.getAllEmployees();
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].getId() == id) {
            return new Employee(employees[i]);
        }
    }
    return nullptr;
}

void Admin::listEmployees() {
    FileManager fm;
    vector<Employee> employees = fm.getAllEmployees();
    for (int i = 0; i < employees.size(); i++) {
        employees[i].displayInfoEmployee();
        cout << "---------------------" << endl;
    }
}

void Admin::editEmployee(int id, const string& name, const string& password, double salary) {
    FileManager fm;
    vector<Employee> employees = fm.getAllEmployees();
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].getId() == id) {
            employees[i].setName(name);
            employees[i].setPassword(password);
            employees[i].setSalary(salary);
            break;
        }
    }
    fm.removeAllEmployees();
    for (int i = 0; i < employees.size(); i++) {
        fm.addEmployee(employees[i]);
    }
}

void Admin::addClient(Client& client) {
    FileManager fm;
    fm.addClient(client);
}

Client* Admin::searchClient(int id) {
    FileManager fm;
    vector<Client> clients = fm.getAllClients();
    for (int i = 0; i < clients.size(); i++) {
        if (clients[i].getId() == id) {
            return new Client(clients[i]);
        }
    }
    return nullptr;
}

void Admin::listClients() {
    FileManager fm;
    vector<Client> clients = fm.getAllClients();
    for (int i = 0; i < clients.size(); i++) {
        clients[i].displayInfoClient();
        cout << "---------------------" << endl;
    }
}

void Admin::editClient(int id, const string& name, const string& password, double balance) {
    FileManager fm;
    vector<Client> clients = fm.getAllClients();
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
