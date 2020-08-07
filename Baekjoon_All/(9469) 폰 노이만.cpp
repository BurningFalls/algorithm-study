#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int P;
	double N, D, A, B, F;
	cin >> P;
	for (int a = 0; a < P; a++) {
		cin >> N >> D >> A >> B >> F;
		cout << fixed << setprecision(0);
		cout << N << " ";
		cout << fixed << setprecision(2);
		cout << (D * F) / (A + B) << "\n";
	}


	return 0;
}