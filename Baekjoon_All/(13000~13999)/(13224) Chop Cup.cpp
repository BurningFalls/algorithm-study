#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int arr[4] = { 0, 1, 2, 3 };
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A')
			swap(arr[1], arr[2]);
		else if (s[i] == 'B')
			swap(arr[2], arr[3]);
		else if (s[i] == 'C')
			swap(arr[1], arr[3]);
	}
	for (int i = 1; i <= 3; i++) {
		if (arr[i] == 1) {
			cout << i;
			break;
		}
	}

	return 0;
}