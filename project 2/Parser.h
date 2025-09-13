#pragma once
#include <string>
#include <sstream>
#include "Vector.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

class Parser {
public:
    static Vector<string> split(string line) {
        Vector<string> tokens;
        stringstream ss(line);
       string token;
        while (getline(ss, token, '|')) {
            tokens.push_back(token);
        }
        return tokens;
    }

    static Client parseToClient(string line) {
        Vector<string> tokens = split(line);
        Client c;
        return Client(stoi(tokens[0]), tokens[1], tokens[2], stod(tokens[3]));
    }

    static Employee parseToEmployee(string line) {
        Vector<string> tokens = split(line);
        return Employee(stoi(tokens[0]), tokens[1], tokens[2], stod(tokens[3]));
    }

    static Admin parseToAdmin(string line) {
        Vector<string> tokens = split(line);
        return Admin(stoi(tokens[0]), tokens[1], tokens[2], stod(tokens[3]));
    }
};