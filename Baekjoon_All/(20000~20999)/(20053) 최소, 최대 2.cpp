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
	int T;
	cin >> T;
	while (T--) {
		int N;
		int mini = 1000001;
		int maxi = -1000001;
		cin >> N;
		FOR(i, 1, N) {
			int num;
			cin >> num;
			mini = min(mini, num);
			maxi = max(maxi, num);
		}
		cout << mini << " " << maxi << "\n";
	}

	return 0;
}