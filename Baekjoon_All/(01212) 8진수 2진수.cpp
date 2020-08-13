#include <iostream>
#include <string>
using namespace std;

int arr[3] = { 0, };

void Change(int n) {
	int i = 2;
	for (int j = 0; j < 3; j++) {
		arr[j] = 0;
	}
	while (i >= 0) {
		arr[i] = n % 2;
		n /= 2;
		i--;
	}
}

int main() {
	string num;
	bool one_flag = false;
	cin >> num;
	if (num == "0")
		cout << 0;
	else {
		for (int i = 0; i < num.size(); i++) {
			Change(num[i] - '0');
			for (int j = 0; j < 3; j++) {
				if (arr[j] == 1)
					one_flag = true;
				if (one_flag == false && arr[j] == 0) continue;
				cout << arr[j];
			}
		}
	}

	return 0;
}