#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int num[500];
int N, K;
vector<double> result;

void calculate() {
	double avg, v;
	for (int a = K; a <= N; a++) {
		for (int j = 0; j < N - a + 1; j++) {
			avg = 0;
			v = 0;
			for (int i = j; i < j + a; i++) {
				avg += num[i];
			}
			avg = avg / a;
			for (int i = j; i < j + a; i++) {
				v += (num[i] - avg) * (num[i] - avg);
			}
			v = v / a;
			result.push_back(sqrt(v));
		}
	}
}



int main() {
	int size;
	double Min;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	calculate();
	Min = result[0];
	size = result.size();
	for (int i = 1; i < size; i++) {
		if (Min > result[i]) {
			Min = result[i];
		}
	}
	cout << Min << endl;
	return 0;
}