#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

pii arr[200001];

bool cmp(pii a, pii b) {
	return a.second < b.second;
}

int main() {
	FASTIO;
	int N, M, K;
	cin >> N >> M >> K;
	FOR(i, 1, K) {
		int v, c;
		cin >> v >> c;
		arr[i] = { v, c };
	}
	sort(arr + 1, arr + K + 1, cmp);
	priority_queue<int> pq;
	int sum = 0;
	int cnt = 0;
	int ans = -1;
	FOR(i, 1, K) {
		sum += arr[i].first;
		pq.push(-arr[i].first);
		cnt++;
		if (cnt > N) {
			sum += pq.top();
			pq.pop();
			cnt--;
		}
		if (cnt == N && sum >= M) {
			ans = arr[i].second;
			break;
		}
	}
	cout << ans;


	return 0;
}