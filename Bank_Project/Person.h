#pragma once
#include "Validation.h"
using namespace std;
class Person
{
protected:
	int id;
	string name, password;
public:
	Person() {
		id = 0;
	}
	Person(int id, string name, string password) {
		setId(id);

		setName(name);
		setPassword(password);
	}


	int getId() {
		return id;
	}
	void setId(int id) {
		this->id = id;
	}
	void setName(string name) {
		if (Validation::isNameValid(name)) {
			this->name = name;
			cout << "\nSuccessful operation!\n" << endl;
		}
		else {
			cout << "\ninvalid name: must be alphabetic chars and min size 5 and max size 20\n";
		}
	}
	string getName() {
		return name;
	}
	void setPassword(string password) {
		if (Validation::isPasswordValid(password)) {
			this->password = password;
			cout << "\nSuccessful operation!\n" << endl;

		}
		else {

			cout << "\nInvalid Password: must be with min size 8 and max size 20\n";
		}
	}
	string getPassword() {
		return password;
	}
	
	 void displayInfo() {
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
	 }
};

