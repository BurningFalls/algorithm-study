#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int arr[4] = { 0, };
	int temp;
	while (getline(cin, str)) {
		for (int j = 0; j < 4; j++) {
			arr[j] = 0;
		}
		for (int j = 0; j < str.size(); j++) {
			temp = str[j];
			if (temp >= 65 && temp <= 90) {
				arr[1]++;
			}
			else if (temp >= 97 && temp <= 122) {
				arr[0]++;
			}
			else if (temp >= 48 && temp <= 57) {
				arr[2]++;
			}
			else if (temp == 32) {
				arr[3]++;
			}
		}
		for (int j = 0; j < 4; j++) {
			cout << arr[j] << " ";
		}
		cout << "\n";
	}

	return 0;
}