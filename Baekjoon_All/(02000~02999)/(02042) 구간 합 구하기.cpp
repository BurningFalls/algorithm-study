#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MAX 1000001

int N;	// 수의 개수
int M;	// 수의 변경이 일어나는 횟수
int K;	// 구간의 합을 구하는 횟수
vector<ll> arr(MAX);
vector<ll> tree(4 * MAX);

ll Init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	ll LQ = Init(node * 2, start, mid);
	ll RQ = Init(node * 2 + 1, mid + 1, end);
	return tree[node] = LQ + RQ;
}

ll Update(int node, int start, int end, int idx, ll num) {
	if (idx < start || end < idx) {
		return tree[node];
	}
	if (start == end) {
		return tree[node] = num;
	}
	int mid = (start + end) / 2;
	ll LQ = Update(node * 2, start, mid, idx, num);
	ll RQ = Update(node * 2 + 1, mid + 1, end, idx, num);
	return tree[node] = LQ + RQ;
}

ll Sum(int node, int start, int end, int left, int right) {
	if (right < start || end < left) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	ll LQ = Sum(node * 2, start, mid, left, right);
	ll RQ = Sum(node * 2 + 1, mid + 1, end, left, right);
	return LQ + RQ;
}

int main() {
	FASTIO;
	cin >> N >> M >> K;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	Init(1, 1, N);
	FOR(i, 1, M + K) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		if (a == 1) {
			// b번째 수를 c로 바꿈
			// arr[b] = c;
			Update(1, 1, N, b, c);
		}
		else if (a == 2) {
			// b번째 수부터 c번째 수까지의 합
			cout << Sum(1, 1, N, b, c) << "\n";
		}
	}

	return 0;
}