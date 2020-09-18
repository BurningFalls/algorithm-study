#include <iostream>
#include <math.h>
using namespace std;

int main() {
	double a, b, c;
	double ans1, ans2;
	cin >> a >> b >> c;
	ans1 = b * sqrt((a * a) / (b * b + c * c));
	ans2 = c * sqrt((a * a) / (b * b + c * c));
	cout << floor(ans1) << " " << floor(ans2);

	return 0;
}