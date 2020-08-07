#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	int* arr = new int[N];
	int cnt[8001] = { 0, };
	double A = 0;
	int maximum = -1;
	vector<int> maximum_loc;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		A += arr[i];
		cnt[arr[i] + 4000]++;
	}
	cout << round(A / N) << "\n";
	sort(arr, arr + N);
	cout << arr[N / 2] << "\n";
	maximum = *max_element(cnt, cnt + 8001);
	for (int i = 0; i <= 8000; i++) {
		if (maximum == cnt[i]) {
			maximum_loc.push_back(i - 4000);
		}
	}
	if (maximum_loc.size() >= 2) {
		sort(maximum_loc.begin(), maximum_loc.end());
		cout << maximum_loc[1] << "\n";
	}
	else {
		cout << maximum_loc[0] << "\n";
	}
	cout << abs(arr[N - 1] - arr[0]) << "\n";

	return 0;
}