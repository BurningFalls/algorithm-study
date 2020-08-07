#include <iostream>
#include <string>
using namespace std;

int main() {
	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		int n;
		float avg = 0;
		float over_avg = 0;
		cin >> n;
		int* arr = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
			avg += arr[j];
		}
		avg = avg / n;
		for (int j = 0; j < n; j++) {
			if (avg < arr[j]) {
				over_avg++;
			}
		}
		cout << fixed;
		cout.precision(3);
		cout << over_avg / n * 100 << "%" << endl;
	}
}