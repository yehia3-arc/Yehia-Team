#pragma once
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

class DataSourceInterface {
public:
    virtual void addClient(Client client) = 0;
    virtual void addEmployee(Employee employee) = 0;
    virtual void addAdmin(Admin admin) = 0;
    virtual Vector<Client> getAllClients() = 0;
    virtual Vector<Employee> getAllEmployees() = 0;
    virtual Vector<Admin> getAllAdmins() = 0;
    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeAllAdmins() = 0;
    virtual ~DataSourceInterface() {}
};