#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

vector<ll> v;

int main() {
	FASTIO;
	ll N, K;
	cin >> N >> K;
	int s_len = to_string(N).size();
	ll ending = 0;
	v.push_back(0);
	ll tmp_end;
	FOR(i, 1, s_len - 1) {
		ending += 9 * (ll)(pow(10, i - 1)) * i;
		v.push_back(ending);
	}
	tmp_end = ending + 9 * (ll)(pow(10, s_len - 1)) * s_len;
	v.push_back(tmp_end);
	ending += (N - ((ll)(pow(10, s_len - 1)) - 1)) * s_len;
	if (K > ending) {
		cout << -1;
		return 0;
	}
	int len = v.size();
	FOR(i, 0, len - 2) {
		if (v[i] + 1 <= K && K <= v[i + 1]) {
			ll temp = int(pow(10, i));
			K -= (v[i] + 1);
			ll num = temp + K / (i + 1);
			string s = to_string(num);
			cout << s[K % (i + 1)];
			break;
		}
	}

	return 0;
}