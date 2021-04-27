#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll cnt[10000001] = { 0, };

int main() {
	FASTIO;
	int N;
	int maxi = 0;
	ll comp_sum = 0;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			int num;
			cin >> num;
			maxi = max(maxi, num);
			cnt[num]++;
			comp_sum += num;
		}
	}
	cnt[0] = 0;
	ROF(i, maxi - 1, 1)
		cnt[i] = cnt[i + 1] + cnt[i];
	FOR(i, 1, maxi)
		cnt[i] = cnt[i - 1] + cnt[i];
	ll tmp;
	if (comp_sum == 0)
		tmp = 0;
	else
		tmp = (comp_sum - 1) / 2 + 1;
	
	int lb = lower_bound(cnt, cnt + maxi + 1, tmp) - cnt;
	cout << lb;


	return 0;
}