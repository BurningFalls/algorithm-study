#include <iostream>
#include <string>
using namespace std;

int main() {
	int arr[3];
	int sum = 0;
	string str[3] = { "Soongsil", "Korea", "Hanyang" };
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum >= 100)
		cout << "OK";
	else {
		if (arr[0] < arr[1] && arr[0] < arr[2])
			cout << str[0];
		else if (arr[1] < arr[0] && arr[1] < arr[2])
			cout << str[1];
		else if (arr[2] < arr[1] && arr[2] < arr[0])
			cout << str[2];
	}

	return 0;
}