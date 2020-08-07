#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

bool Is_Prime(int num) {
	if (num == 2)
		return true;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

bool Is_Prime2(int num) {
	for (int i = 0; i < v.size() && (long long int)v[i] * v[i] <= num; i++) {
		if (num % v[i] == 0)
			return false;
	}
	return true;
}

int main() {
	int T;
	int A, B;
	cin >> T;
	for (int i = 2; i <= 2000000; i++) {
		if (Is_Prime(i))
			v.push_back(i);
	}

	for (int a = 0; a < T; a++) {
		cin >> A >> B;
		if (A + B < 4) {
			cout << "NO\n";
			continue;
		}
		if ((A + B) % 2 == 0) {
			cout << "YES\n";
			continue;
		}
		if (Is_Prime2(A + B - 2))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}