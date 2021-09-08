#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

char arr[401][401];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		vector<pii> v;
		cin >> N;
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				cin >> arr[i][j];
				if (arr[i][j] == '*')
					v.push_back({ i, j });
			}
		}
		int t1 = abs(v[0].first - v[1].first);
		int t2 = abs(v[0].second - v[1].second);
		if (t2 == 0) {
			if (v[0].second == N) {
				arr[v[0].first][v[0].second - 1] = '*';
				arr[v[1].first][v[1].second - 1] = '*';
			}
			else {
				arr[v[0].first][v[0].second + 1] = '*';
				arr[v[1].first][v[1].second + 1] = '*';
			}
		}
		else if (t1 == 0) {
			if (v[0].first == N) {
				arr[v[0].first - 1][v[0].second] = '*';
				arr[v[1].first - 1][v[1].second] = '*';
			}
			else {
				arr[v[0].first + 1][v[0].second] = '*';
				arr[v[1].first + 1][v[1].second] = '*';
			}
		}
		else {
			arr[v[0].first][v[1].second] = '*';
			arr[v[1].first][v[0].second] = '*';
		}
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				cout << arr[i][j];
			}
			cout << "\n";
		}
	}



	return 0;
}