#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int N;
	string str;
	int sum;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		sum = 0;
		for (int i = 0; i < 24; i++) {
			if (str[i] == '0') continue;
			sum += int(pow(2, 23 - i));
		}
		cout << sum << "\n";
	}

	return 0;
}