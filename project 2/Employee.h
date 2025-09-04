#pragma once
#include "Person.h"
#include <string>
#include <iostream>

#include"Vector.h"

class Employee : public Person {
protected:
	double salary;
public:
	Employee() : Person() {
		salary = 0;
	}
	Employee(int id, const string& name, const string& password, double salary)
		: Person(id, name, password), salary(salary) {
		if (!Validation::isSalary(salary)) {
			cout << "Invalid salary! Minimum salary is 5000.\n";
			this->salary = 5000;
		}
	}

	Employee(const Employee& other)
		: Person(other), salary(other.salary) {
	}
	void setSalary(double salary) {
		if (Validation::isSalary(salary)) {
			this->salary = salary;
		}
		else {
			cout << "Salary must be at least 5000." << endl;
		}
	}


	double getSalary()  {
		return salary;
	}
	void displayInfoEmployee() const {
		cout << "Employee info: " << endl;
		Person::displayInfoPerson();
		cout << "salary : " << salary << endl;
	}
	void addClient(Client& client) {
		// Implementation would be in FileManager
		cout << "Client added by employee.\n";
	}

	Client* searchClient(int id) {
		// Implementation would search in files
		cout << "Searching for client with ID: " << id << endl;
		return nullptr;
	}

	void listClients() {
		// Implementation would list all clients from file
		cout << "Listing all clients...\n";
	}

	void editClient(int id, string name, string password, double balance) {
		// Implementation would edit client in file
		cout << "Editing client with ID: " << id << endl;
	}
};

