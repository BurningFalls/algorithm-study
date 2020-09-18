#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int N;
	int arr[26] = { 0, };
	int sum;
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		sum = 0;
		for (int i = 0; i < 26; i++)
			arr[i] = 0;
		getline(cin, str);
		for (int j = 0; j < str.size(); j++) {
			if (str[j] >= 65 && str[j] <= 90) {
				arr[int(str[j]) - 65] = 1;
			}
			else if (str[j] >= 97 && str[j] <= 122) {
				arr[int(str[j]) - 97] = 1;
			}
		}
		for (int i = 0; i < 26; i++)
			sum += arr[i];
		if (sum == 26) {
			cout << "pangram\n";
		}
		else {
			cout << "missing ";
			for (int i = 0; i < 26; i++) {
				if (arr[i] == 0) {
					cout << char(i + 97);
				}
			}
			cout << "\n";
		}
	}

	return 0;
}