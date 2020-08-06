#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	int cnt = 2;
	string str[14] = { "baby", "sukhwan", "trtr", "tr",
						"very", "cute", "trtr", "tr",
						"in", "bed", "trtr", "tr", "baby", "sukhwan" };
	cin >> N;
	N = N - 1;
	cnt = 2 + N / 14;
	if (N % 14 == 2 || N % 14 == 6 || N % 14 == 10) {
		if (cnt >= 5) {
			cout << "tu+ru*" << cnt;
		}
		else {
			cout << "tu";
			for (int i = 0; i < cnt; i++) {
				cout << "ru";
			}
		}
	}
	else if (N % 14 == 3 || N % 14 == 7 || N % 14 == 11) {
		if (cnt - 1 >= 5) {
			cout << "tu+ru*" << cnt - 1;
		}
		else {
			cout << "tu";
			for (int i = 0; i < cnt - 1; i++) {
				cout << "ru";
			}
		}
	}
	else {
		cout << str[N % 14];
	}


	return 0;
}