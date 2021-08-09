#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 250001
#define SIZE 65536

int arr[MAX];
int tree[SIZE * 4] = { 0, };

int Update(int node, int start, int end, int idx, int val) {
	if (idx < start || end < idx)
		return tree[node];
	if (start == end)
		return tree[node] += val;
	int mid = (start + end) / 2;
	int LQ = Update(node * 2, start, mid, idx, val);
	int RQ = Update(node * 2 + 1, mid + 1, end, idx, val);
	return tree[node] = LQ + RQ;
}

int Find(int node, int start, int end, int idx) {
	if (start == end)
		return start;
	int mid = (start + end) / 2;
	if (idx <= tree[node * 2])
		return Find(node * 2, start, mid, idx);
	else if (tree[node * 2] < idx)
		return Find(node * 2 + 1, mid + 1, end, idx - tree[node * 2]);
}

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 0, N - 1)
		cin >> arr[i];
	int left = 0, right = 0;
	int mid = (K + 1) / 2;
	while (right < K - 1)
		Update(1, 0, SIZE - 1, arr[right++], 1);
	ll ans = 0;
	while (right < N) {
		Update(1, 0, SIZE - 1, arr[right++], 1);
		ans += Find(1, 0, SIZE - 1, mid);
		Update(1, 0, SIZE - 1, arr[left++], -1);
	}
	cout << ans;

	return 0;
}