#include <iostream>
#include <vector>
using namespace std;

int main() {
	int K;
	int n;
	vector<int> ans;
	int sum = 0;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> n;
		if (n == 0) {
			ans.pop_back();
		}
		else {
			ans.push_back(n);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		sum += ans[i];
	}
	cout << sum;

	return 0;
}