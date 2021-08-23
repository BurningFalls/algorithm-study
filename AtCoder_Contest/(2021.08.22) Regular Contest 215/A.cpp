#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char S[200001], T[200001];

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	bool zero_flag1 = false;
	bool one_flag1 = false;
	FOR(i, 0, N - 1) {
		cin >> S[i];
		if (S[i] == '0')
			zero_flag1 = true;
		else if (S[i] == '1')
			one_flag1 = true;
	}
	bool zero_flag2 = false;
	bool one_flag2 = false;
	FOR(i, 0, M - 1) {
		cin >> T[i];
		if (T[i] == '0')
			zero_flag2 = true;
		else if (T[i] == '1')
			one_flag2 = true;
	}
	if ((zero_flag2 && !zero_flag1) ||
		(one_flag2 && !one_flag1)) {
		cout << -1;
		return 0;
	}
	if ((zero_flag1 && !one_flag1) ||
		(!zero_flag1 && one_flag1)) {
		cout << M;
		return 0;
	}
	int left = 0, right = 0;
	int cnt = 0;
	char num;
	if (S[0] == '0')
		num = '1';
	else if (S[0] == '1')
		num = '0';
	while (S[left] != num && S[right] != num) {
		left = (left - 1 + N) % N;
		right = (right + 1) % N;
		cnt++;
	}
	int ans = 0;
	char prev = '2';
	bool flag = false;
	FOR(i, 0, M - 1) {
		if (i == 0) {
			if (S[0] != T[0]) {
				ans += cnt;
				flag = true;
			}
		}
		else if (prev != T[i]) {
			if (!flag) {
				flag = true;
				ans += cnt;
			}
			else if (flag) {
				ans += 1;
			}
		}
		ans++;
		prev = T[i];
	}
	cout << ans;


	return 0;
}