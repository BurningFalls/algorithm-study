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
#define MOD 1000000000

map<int, int> Acnt, Bcnt;
vector<int> prime;
vector<int> is_Prime(40001, 1);

void Find_Prime() {
	FOR(i, 2, 40000) {
		if (!is_Prime[i]) continue;
		prime.push_back(i);
		for (int j = i * 2; j <= 40000; j += i) {
			is_Prime[j] = 0;
		}
	}
}

void Func(int x, int idx) {
	for (int div : prime) {
		while (x % div == 0) {
			if (idx == 0) {
				Acnt[div]++;
			}
			else if (idx == 1) {
				Bcnt[div]++;
			}
			x /= div;
		}
	}
	if (x != 1) {
		if (idx == 0) {
			Acnt[x]++;
		}
		else if (idx == 1) {
			Bcnt[x]++;
		}
	}
}

int main() {
	FASTIO;
	Find_Prime();
	int N, M;
	cin >> N;
	FOR(i, 0, N - 1) {
		int num;
		cin >> num;
		Func(num, 0);
	}
	cin >> M;
	FOR(i, 0, M - 1) {
		int num;
		cin >> num;
		Func(num, 1);
	}
	ll ans = 1;
	bool flag = false;
	for (auto it : Acnt) {
		if (!Bcnt[it.first]) continue;
		int mini = min(it.second, Bcnt[it.first]);
		FOR(i, 1, mini) {
			ans = ans * it.first;
			if (ans >= 1000000000) {
				ans = ans % MOD;
				flag = true;
			}
		}
	}
	if (flag) {
		cout.width(9);
		cout.fill('0');
		cout << ans;
	}
	else {
		cout << ans;
	}
	

	return 0;
}