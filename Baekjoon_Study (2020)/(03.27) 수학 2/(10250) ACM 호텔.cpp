#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int T;
	int H, W, N;
	int temp1, temp2;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> H >> W >> N;
		temp1 = (N - 1) % H + 1;
		temp2 = (N - 1) / H + 1;
		cout << temp1;
		if (temp2 >= 10) {
			cout << temp2 << endl;
		}
		else {
			cout << "0" << temp2 << endl;
		}
	}

	return 0;
}