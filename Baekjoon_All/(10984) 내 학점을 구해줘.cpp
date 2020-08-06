#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int T;
	int N;
	int C;
	double G;
	int sum1;
	double sum2;
	cin >> T;
	for (int a = 0; a < T; a++) {
		sum1 = 0;
		sum2 = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> C >> G;
			sum1 += C;
			sum2 += C * G;
		}
		cout << fixed;
		cout << setprecision(1);
		cout << sum1 << " " << sum2 / sum1 << "\n";
	}

	return 0;
}