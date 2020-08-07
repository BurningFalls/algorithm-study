#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string str;
	cin >> N;
	cin.ignore();
	for (int i = 1; i <= N; i++) {
		getline(cin, str);
		cout << i << ". " << str << "\n";
	}

	return 0;
}