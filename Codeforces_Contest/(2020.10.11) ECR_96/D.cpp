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
	cin >> T;
	while (T--) {
		int n;
		string s;
		cin >> n;
		cin >> s;
		int arr[200002];
		int cnt = 1;
		int idx = 1;
		char x = s[0];
		FOR(i, 1, n - 1) {
			if (s[i] == x) {
				cnt++;
			}
			else if (s[i] != x) {
				x = s[i];
				arr[idx] = cnt;
				idx++;
				cnt = 1;
			}
		}
		arr[idx] = cnt;
		arr[idx + 1] = 2;
		int ans = 0;
		int idx2 = 1;
		int usable_idx = 1;
		int len = idx;
		while (arr[usable_idx] == 1) {
			usable_idx++;
		}
		while (idx2 <= len) {
			if (usable_idx > len) {
				ans += (len - idx2) / 2 + 1;
				break;
			}
			if (arr[idx2] == 1) {
				arr[usable_idx]--;
				if (arr[usable_idx] == 1) {
					usable_idx++;
					while (arr[usable_idx] == 1) {
						usable_idx++;
					}
				}
			}
			else if (arr[idx2] != 1) {
				if (usable_idx == idx2) {
					usable_idx++;
					while (arr[usable_idx] == 1) {
						usable_idx++;
					}
				}
			}
			idx2++;
			ans++;
		}
		cout << ans << "\n";
	}

	return 0;
}