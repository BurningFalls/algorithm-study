#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long int ll;

pair<int, int> arr[200001];

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N;
	priority_queue<int> pq;
	ll sum = 0;
	int idx = 1;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr + 1, arr + N + 1, compare);
	for (int i = N; i >= 1; i--) {
		while (arr[idx].first == i && idx <= N) {
			pq.push(arr[idx].second);
			idx++;
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum;

	return 0;
}