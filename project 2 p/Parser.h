#pragma once
#include <string>
#include <sstream>
#include "Vector.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
class Parser
{
    static Admin parseToAdmin(string line) {
        Vector<string> tokens = split(line);
        return Admin(stoi(tokens[0]), tokens[1], tokens[2], stod(tokens[3]));
    }

};

