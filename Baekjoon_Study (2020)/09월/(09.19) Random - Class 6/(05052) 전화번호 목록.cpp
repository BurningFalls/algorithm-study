#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

string arr[10001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		FOR(i, 1, n) {
			cin >> arr[i];
		}
		sort(arr + 1, arr + n + 1);
		bool flag = true;
		FOR(i, 1, n - 1) {
			if (arr[i].size() >= arr[i + 1].size()) continue;
			bool sub_flag = true;
			FOR(j, 0, arr[i].size() - 1) {
				if (arr[i][j] != arr[i + 1][j]) {
					sub_flag = false;
					break;
				}
			}
			if (sub_flag) {
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "YES";
		else
			cout << "NO";
		cout << "\n";
	}

	return 0;
}