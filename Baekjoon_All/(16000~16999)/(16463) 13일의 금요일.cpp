#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[13] = { 0, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };

bool is_Yun(int x) {
	if (x % 400 == 0)
		return true;
	if (x % 100 == 0)
		return false;
	if (x % 4 == 0)
		return true;
	return false;
}

int main() {
	FASTIO;
	int idx = 4;
	int cnt = 0;
	int N;
	cin >> N;
	FOR(year, 2019, N) {
		bool yun_flag = is_Yun(year);
		FOR(month, 1, 12) {
			if (yun_flag && month == 3)
				idx = (idx + 29) % 7;
			else
				idx = (idx + arr[month]) % 7;
			if (idx == 5)
				cnt++;
		}
	}
	cout << cnt;

	return 0;
}