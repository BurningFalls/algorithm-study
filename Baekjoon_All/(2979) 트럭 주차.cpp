#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	int start, end;
	int Check[101] = { 0, };
	int sum = 0;
	cin >> A >> B >> C;
	for (int i = 0; i < 3; i++) {
		cin >> start >> end;
		for (int j = start; j < end; j++)
			Check[j]++;
	}
	for (int i = 1; i <= 100; i++) {
		if (Check[i] == 0) continue;
		if (Check[i] == 1)
			sum += A;
		else if (Check[i] == 2)
			sum += B * 2;
		else if (Check[i] == 3)
			sum += C * 3;
	}
	cout << sum;

	return 0;
}