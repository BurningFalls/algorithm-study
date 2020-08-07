#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
	double X, Y;
	int N;
	double minimum;
	cin >> X >> Y;
	cin >> N;
	double** arr = new double* [N];
	double* one = new double[N + 1];
	for (int i = 0; i < N; i++) {
		arr[i] = new double[2];
	}
	for (int i = 0; i < N; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	one[0] = X / Y;
	for (int i = 1; i <= N; i++) {
		one[i] = arr[i - 1][0] / arr[i - 1][1];
	}
	minimum = *min_element(one, one + N + 1);
	cout << fixed;
	cout << setprecision(2);
	cout << 1000 * minimum;

	return 0;
}