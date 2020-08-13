#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	double x, y, c;
	double ans;
	double left, right, mid;
	double temp1, temp2;
	cin >> x >> y >> c;
	left = 0;
	right = min(x, y);
	while (right - left >= 0.001) {
		mid = (left + right) / 2;
		temp1 = sqrt(x * x - mid * mid);
		temp2 = sqrt(y * y - mid * mid);
		if (temp1 * temp2 > c* (temp2 + temp1))
			left = mid;
		else if (temp1 * temp2 < c * (temp2 + temp1))
			right = mid;
	}
	cout << mid;

	return 0;
}