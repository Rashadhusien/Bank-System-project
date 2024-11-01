#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"
class FileManager : public DataSourceInterface
{
private:
	void addClient(Client client)  {
		FilesHelper::saveClient(client);
	}
	void addEmployee(Employee employee)  {
		FilesHelper::saveEmployee("Employee.txt", "EmployeeLastID.txt", employee);
	}
	void addAdmin(Admin admin)  {
		FilesHelper::saveEmployee("admin.txt", "adminLastID.txt", admin);
	}
	void getAllClients()  {
		FilesHelper::getClients();
	}
	void getAllEmployees()  {
		FilesHelper::getEmployees();
	}
	void getAllAdmins()  {
		FilesHelper::getAdmins();
	}
	void removeAllClients()  {
		FilesHelper::clearFile("clients.txt", "clientsLastID.txt");
	}
	void removeAllEmployees()  {
		FilesHelper::clearFile("employee.txt", "EmployeeLastID.txt");
	}
	void removeAllAdmins()  {
		FilesHelper::clearFile("admin.txt", "adminLastID.txt");
	}

public:
	void getAllData() {
		getAllClients();
		getAllEmployees();
		getAllAdmins();
	}

	void updateClient() {
		removeAllClients();
		for (cIt = clients.begin(); cIt != clients.end(); cIt++) {
			addClient(*cIt);
		}
	}

	void updateEmployee() {
		removeAllEmployees();
		for (eIt = employees.begin(); eIt != employees.end(); eIt++) {
			addEmployee(*eIt);
		}
	}

	void updateAdmin() {
		removeAllAdmins();
		for (aIt = admins.begin(); aIt != admins.end(); aIt++)
		{
			addAdmin(*aIt);
		}

	}

};

