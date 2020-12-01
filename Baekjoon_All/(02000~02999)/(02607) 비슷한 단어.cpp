#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string arr[101];

int main() {
	FASTIO;
	int N;
	int ans = 0;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	int len1 = arr[1].size();
	int check1[26] = { 0, };
	FOR(i, 0, len1 - 1)
		check1[arr[1][i] - 'A']++;
	FOR(i, 2, N) {
		int len = arr[i].size();
		int check[26] = { 0, };
		FOR(j, 0, len - 1)
			check[arr[i][j] - 'A']++;
		int temp = 0;
		int idx = 0;
		FOR(j, 0, 25) {
			if (check1[j] == check[j])
				temp++;
			else
				idx = j;
		}
		if (len1 == len) {
			if (temp == 26)
				ans++;
			else if (temp == 24) {
				if (abs(check1[idx] - check[idx]) == 1)
					ans++;
			}
		}
		else if (len1 + 1 == len && temp == 25) {
			if (check1[idx] + 1 == check[idx])
				ans++;
		}
		else if (len1 == len + 1 && temp == 25) {
			if (check1[idx] == check[idx] + 1)
				ans++;
		}
	}
	cout << ans;

	return 0;
}