#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[42][42];

int main() {
	FASTIO;
	int R, C, T;
	cin >> R >> C;
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			cin >> arr[i][j];
		}
	}
	cin >> T;
	int cnt = 0;
	FOR(i, 1, R - 2) {
		FOR(j, 1, C - 2) {
			vector<int> v;
			FOR(y, i, i + 2) {
				FOR(x, j, j + 2) {
					v.push_back(arr[y][x]);
				}
			}
			sort(v.begin(), v.end());
			if (T <= v[4])
				cnt++;
		}
	}
	cout << cnt;


	return 0;
}