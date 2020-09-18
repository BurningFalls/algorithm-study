#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b;
	string oper;
	int i = 1;
	while (true) {
		cin >> a >> oper >> b;
		if (oper == "E")
			break;
		cout << "Case " << i << ": ";
		if (oper == ">") {
			if (a > b)
				cout << "true";
			else
				cout << "false";
		}
		else if (oper == ">=") {
			if (a >= b)
				cout << "true";
			else
				cout << "false";
		}
		else if (oper == "<") {
			if (a < b)
				cout << "true";
			else
				cout << "false";
		}
		else if (oper == "<=") {
			if (a <= b)
				cout << "true";
			else
				cout << "false";
		}
		else if (oper == "==") {
			if (a == b)
				cout << "true";
			else
				cout << "false";
		}
		else if (oper == "!=") {
			if (a != b)
				cout << "true";
			else
				cout << "false";
		}
		cout << "\n";
		i++;
	}

	return 0;
}