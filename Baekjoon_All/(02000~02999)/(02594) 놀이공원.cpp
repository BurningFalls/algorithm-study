#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

// 600 ~ 1320
bool arr[1351] = { 0, };

int main() {
	FASTIO;
	arr[1320] = 1;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int s, e;
		cin >> s >> e;
		int hour, minute, tmp1, tmp2;
		hour = s / 100;
		minute = s % 100;
		tmp1 = hour * 60 + minute;
		hour = e / 100;
		minute = e % 100;
		tmp2 = hour * 60 + minute;
		FOR(j, tmp1 - 10, tmp2 + 9)
			arr[j] = 1;
	}
	int cnt = 0;
	int maxi = 0;
	FOR(i, 600, 1320) {
		if (!arr[i]) {
			cnt++;
		}
		else {
			maxi = max(maxi, cnt);
			cnt = 0;
		}
	}
	cout << maxi;


	return 0;
}