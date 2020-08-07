#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[40001];

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N;
	int num;
	int temp;
	int dp_max = 1;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		temp = 0;
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i]) {
				temp = max(temp, dp[j]);
			}
		}
		dp[i] = temp + 1;
		dp_max = max(dp_max, dp[i]);
	}
	cout << dp_max;

	return 0;
}