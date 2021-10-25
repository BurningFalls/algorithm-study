#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int N, M;
int arr[100001];
pii Tree[400001];

pii Init(int node, int start, int end) {
	if (start == end) {
		return Tree[node] = { 1 - arr[start], arr[start] };
	}
	int mid = (start + end) / 2;
	pii LQ = Init(node * 2, start, mid);
	pii RQ = Init(node * 2 + 1, mid + 1, end);
	return Tree[node] = { LQ.first + RQ.first, LQ.second + RQ.second };
}

pii Update(int node, int start, int end, int idx, int val) {
	if (idx < start || end < idx) {
		return Tree[node];
	}
	if (start == end) {
		return Tree[node] = { 1 - val, val };
	}
	int mid = (start + end) / 2;
	pii LQ = Update(node * 2, start, mid, idx, val);
	pii RQ = Update(node * 2 + 1, mid + 1, end, idx, val);
	return Tree[node] = { LQ.first + RQ.first, LQ.second + RQ.second };
}

pii Find(int node, int start, int end, int left, int right) {
	if (end < left || right < start) {
		return { 0, 0 };
	}
	if (left <= start && end <= right) {
		return Tree[node];
	}
	int mid = (start + end) / 2;
	pii LQ = Find(node * 2, start, mid, left, right);
	pii RQ = Find(node * 2 + 1, mid + 1, end, left, right);
	return { LQ.first + RQ.first, LQ.second + RQ.second };
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		arr[i] = num % 2;
	}
	Init(1, 1, N);
	cin >> M;
	FOR(i, 1, M) {
		int kind, a, b;
		cin >> kind >> a >> b;
		if (kind == 1) {
			Update(1, 1, N, a, b % 2);
		}
		else if (kind == 2) {
			cout << Find(1, 1, N, a, b).first << "\n";
		}
		else if (kind == 3) {
			cout << Find(1, 1, N, a, b).second << "\n";
		}
	}


	return 0;
}