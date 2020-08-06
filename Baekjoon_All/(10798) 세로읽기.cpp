#include <iostream>
#include <string>
using namespace std;

int main() {
	char arr[5][16];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 16; j++) {
			arr[i][j] = ' ';
		}
	}
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[j][i] != ' ' && arr[j][i] != NULL) {
				cout << arr[j][i];
			}
		}
	}


	return 0;
}