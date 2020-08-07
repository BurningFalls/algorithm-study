#include <iostream>
#include <string>
using namespace std;

int main() {
	string A, B;
	int len1, len2;
	int loc_y, loc_x;
	cin >> A >> B;
	len1 = A.size();
	len2 = B.size();
	char** arr = new char* [len2];
	for (int i = 0; i < len2; i++) {
		arr[i] = new char[len1];
	}
	for (int i = 0; i < len2; i++) {
		for (int j = 0; j < len1; j++) {
			arr[i][j] = '.';
		}
	}
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			if (A[i] == B[j]) {
				loc_y = i;
				loc_x = j;
				j = len2;
				i = len1;
			}
		}
	}
	for (int i = 0; i < len1; i++) {
		arr[loc_x][i] = A[i];
	}
	for (int i = 0; i < len2; i++) {
		arr[i][loc_y] = B[i];
	}
	for (int i = 0; i < len2; i++) {
		for (int j = 0; j < len1; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}

	return 0;
}