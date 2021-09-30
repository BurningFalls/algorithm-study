#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	int move = 1;
	int start, end;
	cin >> start >> end;
	int ans = 0;
	int cnt = 0;
	int dir = 1;
	int tmp = 0;
	while (start != end) {
		ans += 1;
		cnt += 1;
		start += dir;
		if (cnt == move) {
			if (tmp == 0) {
				tmp++;
				dir *= (-1);
			}
			else if (tmp == 1) {
				tmp = 0;
				move *= 2;
			}
			cnt = 0;
		}
	}
	cout << ans;


	return 0;
}