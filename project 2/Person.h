#pragma once
#include "Validation.h"
class Person 
{
protected:
    int id;
    string name;
    string password;
public:
    Person() {
        id = 0;
        name = " ";
        password = " ";
    }
    Person(int id, string name, string password):id(id) {
       
        Validation::isName(name);
        Validation::isPassword(password);
    }
    
    void setId(int id) {
       this-> id = id; 
    }
    void setName(string name) {
        if (Validation::isName(name)) {
            this->name = name;
        }
        else {
            cout << "Invalid name." << endl;
        }
    }
    void setPassword(string password) {
        if (Validation::isPassword(password)) {
            this ->password = password;
        }
        else {
            cout << "Invalid password." << endl;;
        }
    }
    int getId() {
        return id;
    }
    string getName()  {
        return name;
    }
    string getPassword()  {
        return password;
    }
    virtual void displayInfoPerson() const {
        cout << "id: " << id << endl << "Name: " << name << endl << "Password: " << password << endl;
    }
   
        virtual ~Person(){}
};

