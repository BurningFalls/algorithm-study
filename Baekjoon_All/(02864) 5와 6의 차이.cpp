#include <iostream>
#include <string>
using namespace std;

int main() {
	string A, B;
	cin >> A >> B;
	int len1 = A.size();
	int len2 = B.size();

	for (int i = 0; i < len1; i++) {
		if (A[i] == '6') {
			A[i] = '5';
		}
	}
	for (int i = 0; i < len2; i++) {
		if (B[i] == '6') {
			B[i] = '5';
		}
	}
	cout << atoi(A.c_str()) + atoi(B.c_str()) << " ";

	for (int i = 0; i < len1; i++) {
		if (A[i] == '5') {
			A[i] = '6';
		}
	}
	for (int i = 0; i < len2; i++) {
		if (B[i] == '5') {
			B[i] = '6';
		}
	}
	cout << atoi(A.c_str()) + atoi(B.c_str()) << endl;


	return 0;
}