#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	int arr1[22][22];
	int arr2[22][22];
	int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	cin >> T;
	while (T--) {
		int H, W;
		cin >> H >> W;
		FOR(i, 1, H) {
			FOR(j, 1, W) {
				arr1[i][j] = 0;
				arr2[i][j] = 0;
			}
		}
		int cnt1 = 0, cnt2 = 0;
		FOR(i, 1, H) {
			FOR(j, 1, W) {
				bool flag = true;
				if (!(i == 1 || i == H || j == 1 || j == W)) continue;
				FOR(k, 0, 7) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 1 || nx < 1 || ny > H || nx > W) continue;
					if (arr1[ny][nx] == 1) {
						flag = false;
						break;
					}
				}
				if (flag) {
					arr1[i][j] = 1;
					cnt1++;
				}
			}
		}

		FOR(i, 1, H) {
			FOR(j, 1, W) {
				if (i == 1 && j == 1) continue;
				bool flag = true;
				if (!(i == 1 || i == H || j == 1 || j == W)) continue;
				FOR(k, 0, 7) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 1 || nx < 1 || ny > H || nx > W) continue;
					if (arr2[ny][nx] == 1) {
						flag = false;
						break;
					}
				}
				if (flag) {
					arr2[i][j] = 1;
					cnt2++;
				}
			}
		}
		if (cnt1 > cnt2) {
			FOR(i, 1, H) {
				FOR(j, 1, W) {
					cout << arr1[i][j];
				}
				cout << "\n";
			}
		}
		else{
			FOR(i, 1, H) {
				FOR(j, 1, W) {
					cout << arr2[i][j];
				}
				cout << "\n";
			}
		}
		cout << "\n";
	}


	return 0;
}