#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

void Clear(vector<vector<char>>& v) {
	FOR(i, 0, LEN(v) - 1) {
		FOR(j, 0, LEN(v[i]) - 1) {
			v[i][j] = '.';
		}
	}
}

int main() {
	FASTIO;
	int H1, W1, H2, W2;
	cin >> H1 >> W1;
	vector<vector<char>> Map1(H1, vector<char>(W1));
	FOR(i, 0, H1 - 1) {
		FOR(j, 0, W1 - 1) {
			cin >> Map1[i][j];
		}
	}
	cin >> H2 >> W2;
	vector<vector<char>> Map2(H2, vector<char>(W2));
	FOR(i, 0, H2 - 1) {
		FOR(j, 0, W2 - 1) {
			cin >> Map2[i][j];
		}
	}

	vector<vector<char>> v1(H1 + H2, vector<char>(W1 + W2, '.'));
	vector<vector<char>> v2(H1 + H2, vector<char>(W1 + W2, '.'));
	int mini = INF;
	FOR(sy1, 0, H2) {
		FOR(sx1, 0, W2) {
			Clear(v1);
			FOR(i, sy1, sy1 + H1 - 1) {
				FOR(j, sx1, sx1 + W1 - 1) {
					v1[i][j] = Map1[i - sy1][j - sx1];
				}
			}
			FOR(sy2, 0, H1) {
				FOR(sx2, 0, W1) {
					Clear(v2);
					FOR(i, sy2, sy2 + H2 - 1) {
						FOR(j, sx2, sx2 + W2 - 1) {
							v2[i][j] = Map2[i - sy2][j - sx2];
						}
					}
					
					int cnt = 0;
					FOR(i, 0, H1 + H2 - 1) {
						FOR(j, 0, W1 + W2 - 1) {
							cnt += (v1[i][j] != v2[i][j]);
						}
					}
					mini = min(mini, cnt / 2);
				}
			}
		}
	}
	cout << mini;

	return 0;
}