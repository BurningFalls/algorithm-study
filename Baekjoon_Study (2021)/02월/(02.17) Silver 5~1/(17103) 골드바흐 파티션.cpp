#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

bool prime[1000001] = { 0, };
vector<int> prime_v;

bool is_prime(int num) {
	if (num == 2)
		return true;
	FOR(i, 2, sqrt(num)) {
		if (num % i == 0)
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	FOR(i, 2, 1000000) {
		if (is_prime(i)) {
			prime[i] = 1;
			prime_v.push_back(i);
		}
	}
	int len = prime_v.size();
	int T;
	cin >> T;
	while (T--) {
		int N;
		int cnt = 0;
		cin >> N;
		FOR(i, 0, len - 1) {
			if (prime_v[i] > N / 2)
				break;
			if (prime[N - prime_v[i]] == 1)
				cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}