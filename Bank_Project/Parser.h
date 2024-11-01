
#pragma once
#include "Admin.h"
#include <fstream>
#include <sstream>

class Parser
{
private:
	static vector<string> customSplit( string line) {
		stringstream content(line);
		string segment;
		vector<string> splitText;
		while (getline(content, segment, ' '))
			splitText.push_back(segment);
		return splitText;
	}

public:
	static Client parseToClient( string line) {
	
		vector <string> data = customSplit(line);
		Client client(stoi(data[0]), data[1], data[2], stod(data[3]));
		return client;
	}
	 static  Employee employeeParser(string line) {
		
		vector <string> data = customSplit(line);
		Employee employee(stoi(data[0]), data[1], data[2], stod(data[3]));
		return employee;
	}
	static Admin adminParser(string line) {
		vector<string> data = customSplit(line);
		Admin admin(stoi(data[0]), data[1], data[2],stod(data[3]));
		return admin;
	}
};