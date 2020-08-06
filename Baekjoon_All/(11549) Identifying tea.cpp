#include <iostream>
using namespace std;

int main() {
	int T;
	int num;
	int cnt = 0;
	cin >> T;
	for (int i = 0; i < 5; i++) {
		cin >> num;
		if (num == T)
			cnt++;
	}
	cout << cnt;

	return 0;
}