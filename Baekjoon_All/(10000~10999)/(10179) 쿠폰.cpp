#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int N;
	double num;
	double temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		temp = num * 4 / 5;
		temp = round(temp * 100) / 100;
		cout << "$";
		cout << fixed << setprecision(2);
		cout << temp << "\n";
	}

	return 0;
}