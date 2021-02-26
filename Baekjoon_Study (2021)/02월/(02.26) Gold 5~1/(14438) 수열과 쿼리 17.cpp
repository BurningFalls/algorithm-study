#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int
#define MAX 100000
#define INF 1000000001

int N, M;
int arr[MAX + 1];
int tree[4 * MAX + 1];

int Init(int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	int LQ = Init(node * 2, start, mid);
	int RQ = Init(node * 2 + 1, mid + 1, end);
	return tree[node] = min(LQ, RQ);
}

int Find(int node, int start, int end, int left, int right) {
	if (end < left || right < start)
		return INF;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	int LQ = Find(node * 2, start, mid, left, right);
	int RQ = Find(node * 2 + 1, mid + 1, end, left, right);
	return min(LQ, RQ);
}

int Update(int node, int start, int end, int idx, int value) {
	if (idx < start || end < idx)
		return tree[node];
	if (start == end)
		return tree[node] = value;

	int mid = (start + end) / 2;
	int LQ = Update(node * 2, start, mid, idx, value);
	int RQ = Update(node * 2 + 1, mid + 1, end, idx, value);
	return tree[node] = min(LQ, RQ);
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	Init(1, 1, N);
	cin >> M;
	FOR(i, 1, M) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			Update(1, 1, N, b, c);
		}
		else if (a == 2) {
			cout << Find(1, 1, N, b, c) << "\n";
		}
	}



	return 0;
}