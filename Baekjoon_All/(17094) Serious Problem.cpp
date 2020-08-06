#include <iostream>
#include <string>
using namespace std;

int main() {
	int len;
	string str;
	int arr[2] = { 0, };
	cin >> len;
	cin >> str;
	for (int i = 0; i < len; i++) {
		if (str[i] == '2')
			arr[0]++;
		else if (str[i] == 'e')
			arr[1]++;
	}
	if (arr[0] > arr[1])
		cout << "2";
	else if (arr[0] < arr[1])
		cout << "e";
	else if (arr[0] == arr[1])
		cout << "yee";

	return 0;
}