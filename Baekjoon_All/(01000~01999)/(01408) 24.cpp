#include <iostream>
using namespace std;

int main() {
	int hour[2], minute[2], second[2];
	int h = 0, m = 0, s = 0;
	char X;
	int num[2];
	int answer;
	for (int i = 0; i < 2; i++) {
		cin >> hour[i];
		cin >> X;
		cin >> minute[i];
		cin >> X;
		cin >> second[i];
	}
	for (int i = 0; i < 2; i++) {
		num[i] = hour[i] * 3600 + minute[i] * 60 + second[i];
	}
	if (num[0] > num[1]) {
		num[1] += 24 * 3600;
	}
	answer = num[1] - num[0];
	if (answer / 3600 < 10)
		cout << "0";
	cout << answer / 3600 << ":";
	answer -= int(answer / 3600) * 3600;
	if (answer / 60 < 10)
		cout << "0";
	cout << answer / 60 << ":";
	answer -= int(answer / 60) * 60;
	if (answer < 10)
		cout << "0";
	cout << answer;

	return 0;
}