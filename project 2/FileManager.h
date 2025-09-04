#pragma once

#include "DataSourceInterface.h"
#include"Vector.h"

#include"FileHelper.h"
#include "Admin.h"


class FileManager : public DataSourceInterface

{

public:
    void addClient(Client client)  {
        FileHelper::saveClient(client);
    }

    void addEmployee(Employee employee)  {
        FileHelper::saveEmployee("Employees.txt", "LastEmployeeID.txt", employee);
    }

    void addAdmin(Admin admin) {
        FileHelper::saveAdmin(admin);
    }

    void getAllClients()  {
        FileHelper::getClients();
    }

    void getAllEmployees()  {
        FileHelper::getEmployees();
    }

    void getAllAdmins() {
        FileHelper::getAdmins();
    }

    void removeAllClients()  {
        FileHelper::clearFile("Clients.txt", "LastClientID.txt");
    }

    void removeAllEmployees()  {
        FileHelper::clearFile("Employees.txt", "LastEmployeeID.txt");
    }

    void removeAllAdmins()  {
        FileHelper::clearFile("Admins.txt", "LastAdminID.txt");
    }
   
};

