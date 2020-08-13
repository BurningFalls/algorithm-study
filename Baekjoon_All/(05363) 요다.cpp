#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string s1, s2, str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s1 >> s2;
		cin.ignore();
		getline(cin, str);
		cout << str << " " << s1 << " " << s2 << "\n";
	}

	return 0;
}