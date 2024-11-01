#pragma once
#include "Employee.h"
class Admin: public Employee
{
public:
	Admin() {}
	Admin(int id, string name, string password, double salary) :Employee(id, name, password, salary) {
	}
	void addClient(Client& client) {
		clients.push_back(client);
	}
	Client* searchClient(int id) {
		for (cIt = clients.begin(); cIt != clients.end(); cIt++) {
			if (cIt->getId() == id)
				return cIt._Ptr;
		}
		return  NULL;
	}
	void clientsList() {
		for (cIt = clients.begin(); cIt != clients.end(); cIt++) {
			cIt->printData();
			cout << "===============================" << endl;
		}
	}
	void editClient(int id, string name, string password, double balance) {
		searchClient(id)->setName(name);
		searchClient(id)->setPassword(password);
		searchClient(id)->setBalance(balance);
	}
	void addEmployee(Employee& client) {
		employees.push_back(client);
	}
	Employee* searchEmployee(int id) {
		for (eIt = employees.begin(); eIt != employees.end(); eIt++) {
			if (cIt->getId() == id)
				return eIt._Ptr;
		}
		return  NULL;
	}
	void employeesList() {
		for (eIt = employees.begin(); eIt != employees.end(); eIt++) {
			eIt->printData();
			cout << "===============================" << endl;
		}
	}
	void editEmployee(int id, string name, string password, double salary) {
		searchEmployee(id)->setName(name);
		searchEmployee(id)->setPassword(password);
		searchEmployee(id)->setSalary(salary);
	}
};


static vector<Admin>admins; 
static vector<Admin>::iterator aIt; 
