#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string name[101];
int cnt[101];

int main() {
	FASTIO;
	int idx = 1;
	while (true) {
		memset(cnt, 0, sizeof(cnt));
		int N;
		cin >> N;
		if (N == 0)
			break;
		cin.ignore();
		FOR(i, 1, N)
			getline(cin, name[i]);
		FOR(i, 1, 2 * N - 1) {
			int num; char x;
			cin >> num >> x;
			cnt[num]++;
		}
		int ans = 0;
		FOR(i, 1, N) {
			if (cnt[i] == 1)
				ans = i;
		}
		cout << idx << " " << name[ans] << "\n";
		idx++;
	}


	return 0;
}