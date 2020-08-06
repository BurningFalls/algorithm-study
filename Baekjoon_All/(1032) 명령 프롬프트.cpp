#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string arr[51];
	int len;
	int cnt;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	len = arr[0].size();
	for (int i = 0; i < len; i++) {
		cnt = 0;
		for (int j = 0; j < N; j++) {
			if (arr[j][i] == arr[0][i]) {
				cnt++;
			}
		}
		if (cnt == N) {
			cout << arr[0][i];
		}
		else {
			cout << "?";
		}
	}

	return 0;
}