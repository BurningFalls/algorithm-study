#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

bool not_prime[100001] = { 0, };
vector<int> prime_v;

void Prime_Func() {
	FOR(i, 2, 100000) {
		if (!not_prime[i]) {
			for (int j = 2; i * j <= 100000; j++)
				not_prime[i * j] = 1;
		}
	}
	FOR(i, 2, 317) {
		if (!not_prime[i])
			prime_v.push_back(i);
	}
}

int Divide(int x) {
	int cnt = 0;
	int node = 0;
	int len = prime_v.size();
	while (node < len && prime_v[node] * prime_v[node] <= x) {
		if (x % prime_v[node] == 0) {
			cnt++;
			x /= prime_v[node];
		}
		else
			node++;
	}
	return cnt + 1;
}

int main() {
	FASTIO;
	not_prime[1] = 1;
	Prime_Func();
	int A, B;
	int ans = 0;
	cin >> A >> B;
	FOR(i, A, B) {
		int tmp = Divide(i);
		if (!not_prime[tmp])
			ans++;
	}
	cout << ans;

	return 0;
}