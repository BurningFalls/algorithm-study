#include <iostream>
using namespace std;

int main() {
	int arr1[10], arr2[10];
	int A_cnt = 0, B_cnt = 0, D_cnt = 0;
	int A_score, B_score;
	char X;
	for (int i = 0; i < 10; i++)
		cin >> arr1[i];
	for (int i = 0; i < 10; i++)
		cin >> arr2[i];
	for (int i = 0; i < 10; i++) {
		if (arr1[i] > arr2[i]) {
			A_cnt++;
			X = 'A';
		}
		else if (arr1[i] < arr2[i]) {
			B_cnt++;
			X = 'B';
		}
		else if (arr1[i] == arr2[i])
			D_cnt++;
	}
	A_score = A_cnt * 3 + D_cnt;
	B_score = B_cnt * 3 + D_cnt;
	cout << A_score << " " << B_score << "\n";
	if (A_score > B_score)
		cout << "A";
	else if (A_score < B_score)
		cout << "B";
	else if (A_score == B_score) {
		if (D_cnt == 10)
			cout << "D";
		else
			cout << X;
	}

	return 0;
}