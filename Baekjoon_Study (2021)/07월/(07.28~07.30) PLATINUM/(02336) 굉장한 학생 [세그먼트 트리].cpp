#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 500001
#define INF 987654321

typedef struct _NODE {
	int x;
	int y;
	int z;
} NODE;

int N;
NODE arr[MAX];
int tree[4 * MAX];

bool cmp(NODE a, NODE b) {
	return a.x < b.x;
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

int GetMin(int node, int start, int end, int left, int right) {
	if (right < start || end < left)
		return INF;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	int LQ = GetMin(node * 2, start, mid, left, right);
	int RQ = GetMin(node * 2 + 1, mid + 1, end, left, right);
	return min(LQ, RQ);
}

int main() {
	FASTIO;
	cin >> N;
	int num;
	FOR(i, 1, N) {
		cin >> num;
		arr[num].x = i;
	}
	FOR(i, 1, N) {
		cin >> num;
		arr[num].y = i;
	}
	FOR(i, 1, N) {
		cin >> num;
		arr[num].z = i;
	}
	FOR(i, 1, 4 * N)
		tree[i] = INF;
	sort(arr + 1, arr + N + 1, cmp);
	int ans = 0;
	FOR(i, 1, N) {
		int getnum = GetMin(1, 1, N, 1, arr[i].y);
		if (arr[i].z < getnum)
			ans++;
		Update(1, 1, N, arr[i].y, arr[i].z);
	}
	cout << ans;

	return 0;
}