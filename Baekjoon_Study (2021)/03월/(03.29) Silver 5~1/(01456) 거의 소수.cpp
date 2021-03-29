#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 10000001

bool visited[MAX] = { 0, };
vector<ll> prime_v;

void Find_Prime() {
	FOR(i, 2, MAX - 1) {
		if (visited[i]) continue;
		prime_v.push_back(i);
		for (int j = 2 * i; j < MAX; j += i) {
			visited[j] = 1;
		}
	}
}

int main() {
	FASTIO;
	ll A, B;
	cin >> A >> B;
	Find_Prime();

	int ans = 0;
	for (ll n : prime_v) {
		ll tmp = n;
		while (tmp <= B / n) {
			tmp *= n;
			if (tmp >= A) {
				ans++;
			}
		}
	}
	cout << ans;

	return 0;
}