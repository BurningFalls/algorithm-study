#include <iostream>
using namespace std;

int main() {
	int N, W, H;
	int len;
	cin >> N >> W >> H;
	for (int i = 0; i < N; i++) {
		cin >> len;
		if (len * len <= W * W + H * H) {
			cout << "DA" << "\n";
		}
		else {
			cout << "NE" << "\n";
		}
	}

	return 0;
}