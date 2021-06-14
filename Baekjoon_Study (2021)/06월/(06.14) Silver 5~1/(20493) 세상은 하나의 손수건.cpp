#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int main() {
	FASTIO;
	int N, T;
	cin >> N >> T;
	int dir = 0;
	ll X = 0, Y = 0;
	ll prev = 0;
	FOR(i, 1, N) {
		ll t; string s;
		cin >> t >> s;
		X += dx[dir] * (t - prev);
		Y += dy[dir] * (t - prev);
		prev = t;
		if (s == "left")
			dir = (dir + 1) % 4;
		else if (s == "right")
			dir = (dir + 3) % 4;
	}
	X += dx[dir] * (T - prev);
	Y += dy[dir] * (T - prev);

	cout << X << " " << Y;

	return 0;
}