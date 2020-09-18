#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int L;
	int arr[1001] = { 0, };
	int real_num[1001] = { 0, };
	int N;
	int predict_max = 0;
	int real_max = 1;
	vector<pair<int, int>> v;
	int P, K;
	cin >> L;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P >> K;
		v.push_back(make_pair(P, K));
		for (int j = P; j <= K; j++) {
			if (arr[j] == 0)
				arr[j] = i + 1;
		}
	}
	for (int i = 0; i < N; i++) {
		predict_max = max(predict_max, v[i].second - v[i].first + 1);
	}
	for (int i = 0; i < N; i++) {
		if ((v[i].second - v[i].first + 1) == predict_max) {
			cout << i + 1 << "\n";
			break;
		}
	}
	for (int i = 1; i <= L; i++) {
		if (arr[i] != 0) {
			real_num[arr[i]] += 1;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (real_num[real_max] < real_num[i]) {
			real_max = i;
		}
	}
	cout << real_max;

	return 0;
}