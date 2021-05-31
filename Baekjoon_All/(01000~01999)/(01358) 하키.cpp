#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int dist(pii A, pii B) {
	return (A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second);
}

int main() {
	FASTIO;
	int W, H, X, Y, P;
	cin >> W >> H >> X >> Y >> P;
	int cnt = 0;
	FOR(i, 1, P) {
		int a, b;
		cin >> a >> b;
		if (a == 1 && b == 1)
			int x = 1;
		if (X - H / 2 <= a && a < X) {
			int tmp = dist({ a, b }, { X, Y + H / 2 });
			if (tmp <= (H / 2) * (H / 2))
				cnt++;
		}
		else if (X <= a && a <= X + W) {
			if (Y <= b && b <= Y + H)
				cnt++;
		}
		else if (X + W < a && a <= X + W + H / 2) {
			int tmp = dist({ a, b }, { X + W, Y + H / 2 });
			if (tmp <= (H / 2) * (H / 2))
				cnt++;
		}
	}
	cout << cnt;


	return 0;
}