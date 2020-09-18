#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int N;
	vector<int> v;
	int sum = 0;
	cin >> N;
	while (N >= 1) {
		v.push_back(N % 2);
		N /= 2;
	}
	for (int i = 0; i < v.size(); i++) {
		sum += v[i] * pow(2, v.size() - i - 1);
	}
	cout << sum;

	return 0;
}