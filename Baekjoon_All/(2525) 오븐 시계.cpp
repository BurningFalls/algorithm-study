#include <iostream>
using namespace std;

int main() {
	int A, B;
	int C;
	int hour;
	int minute;
	cin >> A >> B;
	cin >> C;
	hour = A + C / 60;
	if (hour >= 24) {
		hour -= 24;
	}
	minute = B + C % 60;
	if (minute >= 60) {
		minute -= 60;
		hour++;
		if (hour == 24) {
			hour = 0;
		}
	}
	cout << hour << " " << minute;


	return 0;
}