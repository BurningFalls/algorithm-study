#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

bool arr[6][6];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	if (N == 10)
		cout << -1;
	else {
		int cnt = 0;
		bool check[5] = { 0, };
		FOR(i, 1, 5) {
			int j = (i + 1) % 5 + 1;
			if (arr[i][j]) {
				check[i - 1] = 1;
				cnt++;
			}
		}
		if (cnt == 5)
			cout << 2;
		else {
			bool flag = true;
			FOR(i, 0, 4) {
				if (check[i] && check[(i + 1) % 5]) {
					flag = false;
					break;
				}
			}
			if (flag)
				cout << 0;
			else
				cout << 1;
		}
	}


	return 0;
}