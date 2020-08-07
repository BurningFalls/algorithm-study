#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	string X;
	int len;
	int check[10];
	int cnt;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cnt = 0;
		for (int i = 0; i <= 9; i++)
			check[i] = 0;
		cin >> X;
		len = X.size();
		for (int i = 0; i < len; i++) {
			check[X[i] - '0'] = 1;
		}
		for (int i = 0; i <= 9; i++) {
			if (check[i])
				cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}