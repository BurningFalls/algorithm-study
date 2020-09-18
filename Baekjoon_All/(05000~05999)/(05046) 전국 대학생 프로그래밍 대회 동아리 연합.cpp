#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, B, H, W;
	int P;
	int A;
	int minimum;
	int cost;
	cin >> N >> B >> H >> W;
	minimum = B + 1;
	for (int i = 1; i <= H; i++) {
		cin >> P;
		cost = 0;
		for (int j = 1; j <= W; j++) {
			cin >> A;
			if (A >= N)
				cost = P * N;
		}
		if (minimum > cost&& cost != 0)
			minimum = cost;
	}

	if (minimum > B) {
		cout << "stay home";
	}
	else {
		cout << minimum;
	}

	return 0;
}