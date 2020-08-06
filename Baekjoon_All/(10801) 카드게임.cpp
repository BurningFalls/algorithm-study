#include <iostream>
using namespace std;

int main() {
	int A[10];
	int B[10];
	int A_win = 0;
	int B_win = 0;
	for (int i = 0; i < 10; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 10; i++) {
		cin >> B[i];
	}
	for (int i = 0; i < 10; i++) {
		if (A[i] > B[i])
			A_win++;
		else if (A[i] < B[i])
			B_win++;
	}
	if (A_win > B_win)
		cout << "A";
	else if (A_win < B_win)
		cout << "B";
	else if (A_win == B_win)
		cout << "D";

	return 0;
}