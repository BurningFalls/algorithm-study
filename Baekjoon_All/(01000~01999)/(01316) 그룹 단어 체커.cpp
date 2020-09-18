#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	string* S = new string[N];
	char X;
	bool con_flag;
	int count = N;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	for (int i = 0; i < N; i++) {
		int len = S[i].size();
		for (int j = 0; j < len; j++) {
			con_flag = true;
			X = S[i][j];
			for (int k = j + 1; k < len; k++) {
				if (S[i][k] != X) {
					con_flag = false;
				}
				else if (S[i][k] == X && con_flag == true) {
					con_flag = true;
				}
				else if (S[i][k] == X && con_flag == false) {
					count--;
					k = len;
					j = len;
				}
			}
		}
	}
	cout << count << endl;

	return 0;
}