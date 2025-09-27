#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
class Validation
{
public:
    static bool isName(string& name) {
        if (name.length() < 5 || name.length() > 20) {
            return false;
        }
        for (int i = 0; i < name.length(); i++) {
            if (name[i] >= 'A' && name[i] <= 'Z' || name[i] >= 'a' && name[i] <= 'z') {
                return true;
            }
            else {
                return false;
            }
        }
    }
    static   bool isPassword(string& p) {
        return p.length() >= 8 && p.length() <= 20;
    }
    static bool isBalance(double balance) {
        return balance >= 1500;
    }
    static bool isSalary(double salary) {
        return salary >= 5000;
    }

};

