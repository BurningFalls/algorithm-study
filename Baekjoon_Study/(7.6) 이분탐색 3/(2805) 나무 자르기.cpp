#include <iostream>
using namespace std;

int trees[1000001];

int main() {
	int N, M;
	pair<long long int, long long int> left(2000000001, 0), right(-1, 0), mid(0, 0);
	long long int tree_sum_left = 0, tree_sum_right = 0, tree_sum;
	int ans = 0;
	cin >> N >> M;
	left.first = 0;
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
		if (right.first < trees[i])
			right.first = trees[i];
	}
	for (int i = 0; i < N; i++) {
		if (trees[i] > left.first)
			tree_sum_left += trees[i] - left.first;
		if (trees[i] > right.first)
			tree_sum_right += trees[i] - right.first;
	}
	left.second = tree_sum_left;
	right.second = tree_sum_right;

	while (right.first - left.first != 1) {
		tree_sum = 0;
		mid.first = (left.first + right.first) / 2;
		for (int i = 0; i < N; i++) {
			if (trees[i] > mid.first)
				tree_sum += trees[i] - mid.first;
		}
		mid.second = tree_sum;
		if (mid.second >= M) {
			if (ans < mid.first)
				ans = mid.first;
		}
		if (mid.second > M)
			left = mid;
		else if (mid.second < M)
			right = mid;
		else if (mid.second == M)
			break;
	}
	cout << ans;

	return 0;
}