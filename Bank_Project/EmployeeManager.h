#pragma once
#include "FileManager.h"
#include "FilesHelper.h"
#include "ClientManager.h"
#include <iostream>
#include <vector>
using namespace std;

class EmployeeManager {
private:
    static void EmployeeMenu() {
        cout << "(1) Display Information\n";
        cout << "(2) Check Salary\n";
        cout << "(3) Edit Password\n";
        cout << "(4) Add New Client\n";
        cout << "(5) List All Clients\n";
        cout << "(6) Search for a Client\n";
        cout << "(7) Edit Client Information\n";
        cout << "(8) Back to Employee Menu\n";
        cout << "(9) Logout\n";
    }

public:
    static void newClient(Employee* employee) {
        int id = FilesHelper::getLast("clientsLastID.txt") + 1;
        string name = FillData::enterName();
        string password = FillData::enterPassword();
        double balance = FillData::enterBalance();
        Client client(id, name, password, balance);
        employee->addClient(client);
        FileManager f;
        f.updateClient();
        cout << "\nAdded Client Successfully!\n";
    }

    static void listAllClients(Employee* employee) {
        employee->clientsList();
    }

    static void searchForClients(Employee* employee) {
        cout << "\nEnter Client ID: ";
        int id;
        cin >> id;
        system("cls");
        if (employee->searchClient(id) == nullptr) {
            cout << "\nClient Is NOT Found\n";
        }
        else {
            employee->searchClient(id)->displayInfo();
        }
    }

    static void EditClientInfo(Employee* employee) {
        cout << "\nEnter Client Id: ";
        int id;
        cin >> id;
        system("cls");
        if (employee->searchClient(id) == nullptr) {
            cout << "\nClient NOT Found!\n";
        }
        else {
            string name = FillData::enterName();
            string password = FillData::enterPassword();
            double balance = FillData::enterBalance();
            employee->editClient(id, name, password, balance);
            FileManager f;
            f.updateClient();
            cout << "\nClient Edited Successfully!\n";
        }
    }

    static Employee* login(int id, string password) {
        for (auto& emp : employees) {
            if (emp.getId() == id && emp.getPassword() == password) {
                return &emp;
            }
        }
        return nullptr;
    }

    static void back(Employee* employee) {
        employeeOptions(employee);
    }

    static bool employeeOptions(Employee* employee) {
        EmployeeMenu();
        cout << "\nChoose An Option: ";
        int op;
        cin >> op;
        FileManager f;

        switch (op) {
        case 1:
            system("cls");
            employee->displayInfo();
            break;
        case 2:
            system("cls");
            employee->getSalary();
            break;
        case 3:
            system("cls");
            ClientManager::updatePassword(employee);
            f.updateEmployee();
            break;
        case 4:
            system("cls");
            newClient(employee);
            break;
        case 5:
            system("cls");
            listAllClients(employee);
            break;
        case 6:
            system("cls");
            searchForClients(employee);
            break;
        case 7:
            system("cls");
            EditClientInfo(employee);
            break;
        case 8:
            system("cls");
            back(employee);
            break;
        case 9:
            system("cls");
            return false;
            break;
        default:
            system("cls");
            cout << "\nPlease, Enter A Valid Number!\n";
            back(employee);
            break;
        }

        char flag = 'y';
        cout << "\nDo you Want Another Operation? (Y/N)\n";
        cin >> flag;
        system("cls");
        if (flag == 'y' || flag == 'Y') {
            employeeOptions(employee);
        }
        return true;
    }
};
