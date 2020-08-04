#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

int N;
vector<int> num_v;
map<int, int> Map;
int tree[2000001] = { 0, };

ll Sum(int node, int start, int end, int left, int right) {
	if (end < left || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	ll left_query, right_query;
	left_query = Sum(node * 2, start, mid, left, right);
	right_query = Sum(node * 2 + 1, mid + 1, end, left, right);
	return left_query + right_query;
}

void Update(int node, int start, int end, int idx) {
	if (idx < start || end < idx)
		return;
	tree[node] += 1;
	if (start == end)
		return;
	int mid = (start + end) / 2;
	Update(node * 2, start, mid, idx);
	Update(node * 2 + 1, mid + 1, end, idx);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int num;
	int val, idx;
	ll ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		num_v.push_back(num);
	}
	for (int i = 1; i <= N; i++) {
		cin >> num;
		Map[num] = i;
	}
	for (int i = 0; i < N; i++) {
		val = num_v[i];
		idx = Map[val];
		ans += Sum(1, 1, N, idx, N);
		Update(1, 1, N, idx);
	}
	cout << ans;

	return 0;
}