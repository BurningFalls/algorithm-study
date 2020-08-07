#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	int D;
	int hour;
	int minute;
	int second;
	int temp = 0;
	cin >> A >> B >> C;
	cin >> D;

	second = C + D;
	if (second >= 60) {
		temp = second / 60;
		second = second % 60;
	}
	else {
		temp = 0;
	}
	minute = B + temp;
	if (minute >= 60) {
		temp = minute / 60;
		minute = minute % 60;
	}
	else {
		temp = 0;
	}
	hour = A + temp;
	if (hour >= 24) {
		hour = hour % 24;
	}
	cout << hour << " " << minute << " " << second;

	return 0;
}