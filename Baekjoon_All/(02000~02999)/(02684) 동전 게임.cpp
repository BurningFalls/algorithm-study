#include <iostream>
#include <string>
using namespace std;

int main() {
	int P;
	string str;
	int arr[8] = { 0, };
	int len;
	string sub_str;
	cin >> P;
	for (int i = 0; i < P; i++) {
		cin >> str;
		len = str.size();
		for (int i = 0; i < 8; i++)
			arr[i] = 0;
		for (int j = 0; j < len - 2; j++) {
			sub_str = "";
			sub_str += str[j];
			sub_str += str[j + 1];
			sub_str += str[j + 2];
			if (sub_str == "TTT")
				arr[0]++;
			else if (sub_str == "TTH")
				arr[1]++;
			else if (sub_str == "THT")
				arr[2]++;
			else if (sub_str == "THH")
				arr[3]++;
			else if (sub_str == "HTT")
				arr[4]++;
			else if (sub_str == "HTH")
				arr[5]++;
			else if (sub_str == "HHT")
				arr[6]++;
			else if (sub_str == "HHH")
				arr[7]++;
		}
		for (int i = 0; i < 8; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}

	return 0;
}