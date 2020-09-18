#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string str;
	string sub_str;
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		getline(cin, str);
		sub_str = str.substr(0, 10);
		if (sub_str == "Simon says") {
			sub_str = str.substr(11, str.size() - 10);
			cout << " " << sub_str << "\n";
		}
	}

	return 0;
}