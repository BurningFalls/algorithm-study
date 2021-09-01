#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 2100000000

struct NODE {
	int x;
	int y;
};

NODE arr[1001];
int Dist[1001][1001];

int Calc_Dist(NODE a, NODE b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i].x >> arr[i].y;
	}
	FOR(i, 1, N)
		Dist[i][i] = 0;
	FOR(i, 1, N) {
		FOR(j, i + 1, N) {
			int dist = Calc_Dist(arr[i], arr[j]);
			Dist[i][j] = dist;
			Dist[j][i] = dist;
		}
	}
	int mini = INF;
	int mini_idx = 0;
	FOR(i, 1, N) {
		int maxi = 0;
		FOR(j, 1, N)
			maxi = max(maxi, Dist[i][j]);
		if (mini > maxi) {
			mini = maxi;
			mini_idx = i;
		}
	}
	cout << arr[mini_idx].x << " " << arr[mini_idx].y;


	return 0;
}