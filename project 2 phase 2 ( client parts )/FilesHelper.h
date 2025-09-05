#pragma once
#include <fstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"

class FilesHelper {
public:
    static void saveLast(const string& fileName, int id) {
        ofstream file(fileName);
        if (file.is_open()) {
            file << id;
            file.close();
        }
    }

    static int getLast(const string& fileName) {
        ifstream file(fileName);
        int id = 0;
        if (file.is_open()) {
            file >> id;
            file.close();
        }
        return id;
    }

    static void saveClient(Client c) {
        ofstream file("Clients.txt", ios::app);
        if (file.is_open()) {
            file << c.getId() << "|" << c.getName() << "|"
                << c.getPassword() << "|" << c.getBalance() << endl;
            file.close();
        }
        saveLast("lastClientId.txt", c.getId());
    }

    clients.push_back(Parser::parseToClient(line));
}
file.close();
return clients;
    }


    static void clearFile(const string& fileName, const string& lastIdFile) {
        ofstream file(fileName, ios::trunc);
        file.close();
        saveLast(lastIdFile, 0);
    }
};
