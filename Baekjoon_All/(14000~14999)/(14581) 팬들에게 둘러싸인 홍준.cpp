#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < 3; i++)
		cout << ":fan:";
	cout << "\n";
	cout << ":fan::";
	cout << s;
	cout << "::fan:\n";
	for (int i = 0; i < 3; i++)
		cout << ":fan:";

	return 0;
}