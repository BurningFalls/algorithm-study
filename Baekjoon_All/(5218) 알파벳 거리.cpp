#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	string str1, str2;
	int temp1, temp2;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> str1 >> str2;
		cout << "Distances: ";
		for (int i = 0; i < str1.size(); i++) {
			temp1 = str1[i] - 64;
			temp2 = str2[i] - 64;
			if (temp2 >= temp1)
				cout << temp2 - temp1 << " ";
			else
				cout << temp2 - temp1 + 26 << " ";
		}
		cout << "\n";
	}


	return 0;
}