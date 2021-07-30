#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pll pair<ll, ll>
#define MAX 1000003

typedef struct _LINE {
	ll a, b;
} line;

struct convexhull_trick {
	int s = 0, e = 0;
	int idx[MAX];
	line deq[MAX];
	double cross(int a, int b) {
		return 1.0 * (deq[a].b - deq[b].b) / (deq[b].a - deq[a].a);
	}
	void insert(line v, int line_idx) {
		deq[e] = v;
		idx[e] = line_idx;
		while (s + 1 < e && cross(e - 2, e - 1) > cross(e - 1, e)) {
			deq[e - 1] = deq[e];
			idx[e - 1] = idx[e];
			e--;
		}
		e++;
	}
	pll query(long long x) {
		int l = 0, r = e - 1;
		while (l != r) {
			int m = (l + r) / 2;
			if (cross(m, m + 1) <= x)
				l = m + 1;
			else
				r = m;
		}
		return pll(deq[l].a * x + deq[l].b, idx[l]);
	}
	void clear() { s = e = 0; }
} cht;

ll N, A, B, C;
ll arr[MAX];
ll sum[MAX];
ll dp[MAX];

int main() {
	FASTIO;
	cin >> N;
	cin >> A >> B >> C;
	sum[0] = 0;
	FOR(i, 1, N) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	line ins;
	ins.a = B;
	ins.b = 0;
	cht.insert(ins, 0);
	FOR(i, 1, N) {
		dp[i] = C + A * sum[i] * sum[i] + cht.query(sum[i]).first;
		ins.a = -2 * A * sum[i] + B;
		ins.b = dp[i] - B * sum[i] + A * sum[i] * sum[i];
		cht.insert(ins, i);
	}
	cout << dp[N];

	return 0;
}