#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int main() {
	char arr[11];
	int len;
	cin >> arr;
	len = strlen(arr);
	sort(arr, arr + len, desc);
	cout << arr;

	return 0;
}