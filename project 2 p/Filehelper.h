#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Parser.h"
#include "Vector.h"
#include "Client.h"
#include "Employee.h"

using namespace std;

class FilesHelper {
public:

    //***********
    static void saveAdmin(Admin a) {
        ofstream file("Admins.txt", ios::app);
        if (file.is_open()) {
            file << a.getId() << "|" << a.getName() << "|"
                << a.getPassword() << "|" << a.getSalary() << endl;
            file.close();
        }
        saveLast("lastAdminId.txt", a.getId());
    }
    static Vector<Admin> getAdmins() {
        Vector<Admin> admins;
        ifstream file("Admins.txt");
        string line;
        while (getline(file, line)) {
            admins.push_back(Parser::parseToAdmin(line));
        }
        file.close();
        return admins;
    }
   
};

