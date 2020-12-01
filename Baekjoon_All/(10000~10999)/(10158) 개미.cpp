#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int W, H;
int P, Q, T;
int Dir;
int dy[4] = { 1, 1, -1, -1 };
int dx[4] = { 1, -1, -1, 1 };

bool Move() {
	int dist1, dist2;
	int arr[4] = { W - P, H - Q, P, Q };
	dist1 = arr[Dir];
	dist2 = arr[(Dir + 1) % 4];
	int moving = min(dist1, dist2);
	T -= moving;
	P += dx[Dir] * moving;
	Q += dy[Dir] * moving;
	if (T <= 0)
		return false;
	if (dist1 < dist2)
		Dir = (Dir + 1) % 4;
	else if (dist1 > dist2)
		Dir = (Dir + 3) % 4;
	else if (dist1 == dist2)
		Dir = (Dir + 2) % 4;
	return true;
}

int main() {
	FASTIO;
	cin >> W >> H;
	cin >> P >> Q;
	cin >> T;
	Dir = 0;
	while (Move())
		;
	Dir = (Dir + 2) % 4;
	P += dx[Dir] * (0 - T);
	Q += dy[Dir] * (0 - T);
	cout << P << " " << Q;

	return 0;
}