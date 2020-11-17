#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 1000000000 + 1

int N;
int arr[100001];
int tree[400001];

int Init(int node, int start, int end) {
	if (start == end)
		return tree[node] = start;
	int mid = (start + end) / 2;
	int LQ = Init(node * 2, start, mid);
	int RQ = Init(node * 2 + 1, mid + 1, end);
	if (arr[LQ] < arr[RQ])
		return tree[node] = LQ;
	else
		return tree[node] = RQ;
}

int Min(int node, int start, int end, int left, int right) {
	if (end < left || right < start)
		return -1;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	int LQ = Min(node * 2, start, mid, left, right);
	int RQ = Min(node * 2 + 1, mid + 1, end, left, right);
	if (LQ == -1)
		return RQ;
	else if (RQ == -1)
		return LQ;
	else if (arr[LQ] < arr[RQ])
		return LQ;
	else
		return RQ;
}

ll Calc(int left, int right) {
	int idx = Min(1, 1, N, left, right);
	ll area = ((ll)right - left + 1) * arr[idx];
	if (left < idx)
		area = max(area, Calc(left, idx - 1));
	if (idx < right)
		area = max(area, Calc(idx + 1, right));
	return area;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	Init(1, 1, N);
	cout << Calc(1, N);

	return 0;
}