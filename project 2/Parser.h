#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include"Admin.h"
#include"FileManager.h"

#include "Vector.h"

using namespace std;
class Parser
{
public:

    static  Vector<string> split(string line) {
        Vector<string> parts;

        stringstream ss(line);
        string token;

        while (getline(ss, token, '|')) {
            parts.push_back(token);
        }
            return parts;
        }

    
    static Client parseToClient(string line) {
        Vector<string> parts = split(line);

        if (parts.size() < 4) {
            return Client();
        }
        int id = stoi(parts[0]); // convert string to int
        string   name = parts[1];
        string  password = parts[2];
        double    balance = stod(parts[3]); // convert string to double

        return Client(id, name, password, balance);

    }

    static Employee parseToEmployee(string line) {
        Vector<string> parts = split(line);

        if (parts.size() != 4) {
            return Employee();
        }

        int id = stoi(parts[0]);
        string name = parts[1];
        string password = parts[2];
        double salary = stod(parts[3]);
        return Employee(id, name, password, salary);

    }


   static Admin parseToAdmin( string line) {
        Vector<string> parts = split(line);
     
        if (parts.size() != 4) {
            return Admin();
        } 
        int id = stoi(parts[0]);  
          string  name = parts[1];
          string  password = parts[2];
         double   salary = stod(parts[3]);
        return Admin(id, name, password, salary);
      
    }
  
   
  
};

