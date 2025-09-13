#pragma once
#include "DataSourceInterface.h"
#include "FileHelper.h"

class FileManager : public DataSourceInterface {
private:
    string clientFile = "Clients.txt";
    string employeeFile = "Employees.txt";


public:
    //***********
    Vector<Admin> getAllAdmins() override {
        return FilesHelper::getAdmins();
    }

    void addAdmin(Admin admin) override {
        FilesHelper::saveAdmin(admin);
    }

    void removeAllAdmins() override {
        FilesHelper::clearAdminsFile();
    }
};
