#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	int len = S.size();
	int* arr = new int[len];
	int sum = 0;

	for (int i = 0; i < len; i++) {
		if (S[i] == 'A' || S[i] == 'B' || S[i] == 'C') {
			arr[i] = 2;
		}
		else if (S[i] == 'D' || S[i] == 'E' || S[i] == 'F') {
			arr[i] = 3;
		}
		else if (S[i] == 'G' || S[i] == 'H' || S[i] == 'I') {
			arr[i] = 4;
		}
		else if (S[i] == 'J' || S[i] == 'K' || S[i] == 'L') {
			arr[i] = 5;
		}
		else if (S[i] == 'M' || S[i] == 'N' || S[i] == 'O') {
			arr[i] = 6;
		}
		else if (S[i] == 'P' || S[i] == 'Q' || S[i] == 'R' || S[i] == 'S') {
			arr[i] = 7;
		}
		else if (S[i] == 'T' || S[i] == 'U' || S[i] == 'V') {
			arr[i] = 8;
		}
		else if (S[i] == 'W' || S[i] == 'X' || S[i] == 'Y' || S[i] == 'Z') {
			arr[i] = 9;
		}
	}
	for (int i = 0; i < len; i++) {
		sum += (arr[i] + 1);
	}

	cout << sum << endl;

	return 0;
}