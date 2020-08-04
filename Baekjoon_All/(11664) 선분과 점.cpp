#include <iostream>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <iomanip>
using namespace std;

double Cal_Dist(tuple<double, double, double> A, tuple<double, double, double> B) {
	double temp = 0;
	temp += pow(get<0>(A) - get<0>(B), 2);
	temp += pow(get<1>(A) - get<1>(B), 2);
	temp += pow(get<2>(A) - get<2>(B), 2);
	return sqrt(temp);
}

int main() {
	tuple<double, double, double> A, B, C;
	double left, right, mid = 0;
	double left_equ, right_equ;
	double temp1, temp2;
	double a, b, c;
	for (int i = 0; i < 3; i++) {
		cin >> a >> b >> c;
		if (i == 0)
			A = make_tuple(a, b, c);
		else if (i == 1)
			B = make_tuple(a, b, c);
		else if (i == 2)
			C = make_tuple(a, b, c);
	}

	temp1 = Cal_Dist(A, C);
	temp2 = Cal_Dist(B, C);
	left = 0;
	right = min(temp1, temp2);
	while (right - left >= 0.0000001) {
		mid = (left + right) / 2;
		left_equ = sqrt(pow(Cal_Dist(C, A), 2) - pow(mid, 2)) + sqrt(pow(Cal_Dist(C, B), 2) - pow(mid, 2));
		right_equ = Cal_Dist(A, B);
		if (left_equ > right_equ) {
			left = mid;
		}
		else if (left_equ < right_equ) {
			right = mid;
		}
		else if (left_equ == right_equ)
			break;
	}
	cout << fixed << setprecision(6) << mid;

	return 0;
}