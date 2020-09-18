#include <iostream>
using namespace std;

int main() {
	int N;
	int i = 1;
	int cnt = 0;
	cin >> N;
	while (true) {
		if (i % 3 != 0 && i % 5 != 0) {
			cnt++;
		}
		if (cnt == N) {
			cout << i;
			break;
		}
		i++;
	}
}