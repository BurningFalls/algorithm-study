#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int A, B, C, D, P;
	int temp;
	cin >> A >> B >> C >> D >> P;
	if (P <= C) {
		temp = B;
	}
	else if (P > C) {
		temp = B + (P - C) * D;
	}
	cout << min(A * P, temp);

	return 0;
}