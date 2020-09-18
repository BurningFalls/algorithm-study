#include <iostream>
#include <string>
using namespace std;

int main() {
	int T, R;
	string S;
	int len;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> R >> S;
		len = S.size();
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < R; j++) {
				cout << S[i];
			}
		}
		cout << endl;
	}

	return 0;
}