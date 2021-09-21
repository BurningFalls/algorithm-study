#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

ll Hero[200001];

int main() {
	FASTIO;
	int N, M;
	ll Hero_sum = 0;
	cin >> N;
	FOR(i, 1, N) {
		cin >> Hero[i];
		Hero_sum += Hero[i];
	}
	sort(Hero + 1, Hero + N + 1);
	cin >> M;
	FOR(i, 1, M) {
		ll x, y;
		cin >> x >> y;
		ll mini = -1;
		int lb = lower_bound(Hero + 1, Hero + N + 1, x) - Hero;
		int ub = upper_bound(Hero + 1, Hero + N + 1, x) - Hero;
		if (Hero[lb] == x) {
			ll tmp = max(0LL, (x - Hero[lb])) + max(0LL, y - (Hero_sum - Hero[lb]));
			if (mini == -1)
				mini = tmp;
			else
				mini = min(mini, tmp);
		}
		if (lb >= 2 && lb <= N + 1) {
			lb -= 1;
			ll tmp = max(0LL, (x - Hero[lb])) + max(0LL, y - (Hero_sum - Hero[lb]));
			if (mini == -1)
				mini = tmp;
			else
				mini = min(mini, tmp);
		}
		if (ub >= 1 && ub <= N) {
			ll tmp = max(0LL, (x - Hero[ub])) + max(0LL, y - (Hero_sum - Hero[ub]));
			if (mini == -1)
				mini = tmp;
			else
				mini = min(mini, tmp);
		}
		cout << mini << "\n";
	}


	return 0;
}