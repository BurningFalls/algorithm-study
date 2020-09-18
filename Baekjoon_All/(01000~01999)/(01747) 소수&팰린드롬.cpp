#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

bool Check_Prime(int a) {
	if (a == 1)
		return false;
	else if (a == 2)
		return true;
	for (int i = 2; i <= sqrt(a); i++) {
		if (a % i == 0)
			return false;
	}
	return true;
}

bool Check_PD(int a) {
	string s = to_string(a);
	string ch_s;
	ch_s = s;
	reverse(s.begin(), s.end());
	if (ch_s == s)
		return true;
	else
		return false;
}

int main() {
	int N;
	cin >> N;
	for (int i = N; i <= 1003002; i++) {
		if (Check_Prime(i)) {
			if (Check_PD(i)) {
				cout << i;
				break;
			}
		}
	}

	return 0;
}