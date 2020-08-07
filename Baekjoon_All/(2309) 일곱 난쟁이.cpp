#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int arr[9];
	int d[9] = { 1,1,1,1,1,1,1,0,0 };
	bool flag = true;
	int sum;
	vector<int> ans;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	while (flag) {
		sum = 0;
		for (int i = 0; i < 9; i++) {
			if (d[i] == 1) {
				sum += arr[i];
			}
		}
		if (sum == 100) {
			for (int i = 0; i < 9; i++) {
				if (d[i] == 1) {
					ans.push_back(arr[i]);
				}
			}
			break;
		}
		prev_permutation(d, d + 9);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}