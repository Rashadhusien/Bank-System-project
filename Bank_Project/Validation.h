#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
class Validation {
public:
	static bool isNameValid(string& name) {
		if (name.size() > 3 || name.size() > 20) {
			return false;
		}
		for (int i = 0; i < name.size(); i++) {
			if (!isalpha(name[i])) {
				return false;
			}
		}
		return true;
	}
	static bool isPasswordValid(string& password) {
		return password.size() >= 8 && password.size() <= 20;
	}
	static bool isBalanceValid(double balance) {
		return balance >= 1500;
	}

	static bool isSalaryValid(double salary) {
		return salary >= 5000;
	}
};
