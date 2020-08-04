#include <iostream>
#include <string>
using namespace std;

int dn(int n) {
	string str = to_string(n);
	int sum = 0;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		sum += str[i] - '0';
	}
	sum += n;
	return sum;
}

int main() {
	int count = 0;
	int arr[10001] = { 0, };
	for (int i = 1; i <= 10000; i++) {
		if (dn(i) <= 10000) {
			arr[dn(i)] = 1;
		}
	}
	for (int i = 1; i <= 10000; i++) {
		if (arr[i] == 0) {
			cout << i << endl;
		}
	}

	return 0;
}