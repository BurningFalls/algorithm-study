#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

typedef struct _INF {
	int H;
	int W;
	int calc;
} INF;

vector<INF> v;
vector<int> area_v;

bool cmp(INF a, INF b) {
	if (a.calc == b.calc) {
		return a.H < b.H;
	}
	return a.calc < b.calc;
}

int main() {
	FASTIO;
	int H, W;
	FOR(h, 1, 150) {
		FOR(w, h + 1, 150) {
			INF tmp = { h, w, h * h + w * w };
			v.push_back(tmp);
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (INF x : v)
		area_v.push_back(x.calc);
	int vlen = v.size();
	while (true) {
		cin >> H >> W;
		if (H == 0 && W == 0)
			break;
		int tmp = H * H + W * W;
		int lb = lower_bound(area_v.begin(), area_v.end(), tmp) - area_v.begin();
		while (lb < vlen) {
			if (v[lb].H == H && v[lb].W == W) {
				break;
			}
			lb++;
		}
		lb++;
		cout << v[lb].H << " " << v[lb].W << "\n";
	}


	return 0;
}