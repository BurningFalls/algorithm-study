#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	string str;
	int num;
	int sum;
	for (int a = 0; a < T; a++) {
		cin >> str;
		sum = 0;
		num = 0;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == 'O') {
				num++;
				sum += num;
			}
			else if (str[j] == 'X') {
				num = 0;
			}
		}
		cout << sum << endl;
	}

}