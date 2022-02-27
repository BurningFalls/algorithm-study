#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define ld long double
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define MAX 100002

ll H;
vector<ld> tree(MAX * 4, 0);
vector<ld> lazy(MAX * 4, 0);

void lazy_Update(int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] = tree[node] + (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[node * 2] = lazy[node * 2] + lazy[node];
			lazy[node * 2 + 1] = lazy[node * 2 + 1] + lazy[node];
		}
		lazy[node] = 0;
	}
}

void Update(int node, int start, int end, int left, int right, ld add) {
	lazy_Update(node, start, end);
	if (end < left || right < start)
		return;
	if (left <= start && end <= right) {
		tree[node] = tree[node] + (end - start + 1) * add;
		if (start != end) {
			lazy[node * 2] = lazy[node * 2] + add;
			lazy[node * 2 + 1] = lazy[node * 2 + 1] + add;
		}
		return;
	}
	int mid = (start + end) / 2;
	Update(node * 2, start, mid, left, right, add);
	Update(node * 2 + 1, mid + 1, end, left, right, add);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ld Sum(int node, int start, int end, int left, int right) {
	lazy_Update(node, start, end);
	if (end < left || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	ld Left = Sum(node * 2, start, mid, left, right);
	ld Right = Sum(node * 2 + 1, mid + 1, end, left, right);
	return Left + Right;
}

int main() {
	FASTIO;
	ll Q, R;
	vector<ld> cnt(MAX, 0);
	cin >> H;
	cin >> Q >> R;
	FOR(q, 1, Q) {
		ll a;
		ld b;
		cin >> a >> b;
		ll left = 1, right = H;
		ll height = 0;
		while (left <= right) {
			ll mid = (left + right) / 2;
			if (a < (mid - 1) * mid / 2 + 1) {
				right = mid - 1;
			}
			else if (mid * (mid + 1) / 2 < a) {
				left = mid + 1;
			}
			else {
				height = mid;
				break;
			}
		}
		ll pos = a - (height - 1) * height / 2;
		left = pos;
		ll len = H + 2 - height;
		right = left + len - 1;
		ld prob = b / len;
		Update(1, 1, H + 1, left, right, prob);
	}
	cout << fixed << setprecision(4);
	FOR(r, 1, R) {
		int a, b;
		cin >> a >> b;
		cout << Sum(1, 1, H + 1, a, b) << "\n";
	}

	return 0;
}