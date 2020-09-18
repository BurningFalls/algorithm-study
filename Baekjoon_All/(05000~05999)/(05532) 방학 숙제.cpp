#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	double L, A, B, C, D;
	cin >> L >> A >> B >> C >> D;

	cout << L - max(ceil(A / C), ceil(B / D));


	return 0;
}