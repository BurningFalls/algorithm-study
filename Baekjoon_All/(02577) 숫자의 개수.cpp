#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b, c;
	int mt;
	string str;
	int arr[10] = { 0, };
	cin >> a >> b >> c;
	mt = a * b * c;
	str = to_string(mt);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '0') {
			arr[0]++;
		}
		else if (str[i] == '1') {
			arr[1]++;
		}
		else if (str[i] == '2') {
			arr[2]++;
		}
		else if (str[i] == '3') {
			arr[3]++;
		}
		else if (str[i] == '4') {
			arr[4]++;
		}
		else if (str[i] == '5') {
			arr[5]++;
		}
		else if (str[i] == '6') {
			arr[6]++;
		}
		else if (str[i] == '7') {
			arr[7]++;
		}
		else if (str[i] == '8') {
			arr[8]++;
		}
		else if (str[i] == '9') {
			arr[9]++;
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
}