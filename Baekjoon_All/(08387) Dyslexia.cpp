#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string a, b;
	int cnt = 0;
	cin >> N;
	cin >> a;
	cin >> b;
	for (int i = 0; i < N; i++) {
		if (a[i] == b[i])
			cnt++;
	}
	cout << cnt;

	return 0;
}