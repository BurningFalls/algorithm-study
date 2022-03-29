#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	int N, P, Q, R;
	cin >> N >> P >> Q >> R;
	vector<char> v(N);
	FOR(i, 0, N - 1) {
		cin >> v[i];
	}

	int ans = 0;
	int skh = 0, sk = 0, kh = 0, sh = 0;
	int s = 0, k = 0, h = 0;

	int pos = 0;
	while (pos < N) {
		if (pos <= N - 3 && v[pos] == 'S' && v[pos + 1] == 'K' && v[pos + 2] == 'H') {
			skh++;
			pos += 3;
		}
		else if (pos <= N - 2 && v[pos] == 'S' && v[pos + 1] == 'K') {
			sk++;
			pos += 2;
		}
		else if (pos <= N - 2 && v[pos] == 'K' && v[pos + 1] == 'H') {
			kh++;
			pos += 2;
		}
		else if (pos <= N - 2 && v[pos] == 'S' && v[pos + 1] == 'H') {
			sh++;
			pos += 2;
		}
		else if (v[pos] == 'S') {
			s++;
			pos += 1;
		}
		else if (v[pos] == 'K') {
			k++;
			pos += 1;
		}
		else if (v[pos] == 'H') {
			h++;
			pos += 1;
		}
	}

	ans += skh;

	ans += min(sk, R) + min(kh, P) + min(sh, Q);
	P -= min(kh, P), Q -= min(sh, Q), R -= min(sk, R);

	int maxi = 0;
	int mini = min({ s, Q, R });
	FOR(i, 0, mini) {
		int t1 = min({ k, P, R - i});
		int t2 = min({ h, P - t1, Q - i});
		int t3 = min({ P - t1 - t2, Q - i - t2, R - i - t1});
		maxi = max(maxi, i + t1 + t2 + t3);
	}
	mini = min({ k, P, R });
	FOR(i, 0, mini) {
		int t1 = min({ s, Q, R - i });
		int t2 = min({ h, P - i, Q - t1 });
		int t3 = min({ P - i - t2, Q - t1 - t2, R - i - t1 });
		maxi = max(maxi, i + t1 + t2 + t3);
	}
	mini = min({ h, P, Q });
	FOR(i, 0, mini) {
		int t1 = min({ s, Q - i, R });
		int t2 = min({ k, P - i, R - t1 });
		int t3 = min({ P - i - t2, Q - i - t1, R - t1 - t2 });
		maxi = max(maxi, i + t1 + t2 + t3);
	}
	ans += maxi;

	cout << ans;


	return 0;
}