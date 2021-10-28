#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int Gcd(int a, int b) {
	if (b == 0)
		return a;
	return Gcd(b, a % b);
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<int> v(N), Lgcd(N), Rgcd(N);
	FOR(i, 0, N - 1) {
		cin >> v[i];
	}
	Lgcd[0] = v[0];
	FOR(i, 1, N - 1) {
		Lgcd[i] = Gcd(Lgcd[i - 1], v[i]);
	}
	Rgcd[N - 1] = v[N - 1];
	ROF(i, N - 2, 0) {
		Rgcd[i] = Gcd(Rgcd[i + 1], v[i]);
	}
	int maxi = -1;
	int idx = -1;
	FOR(i, 0, N - 1) {
		int gcd = 0;
		if (i == 0) {
			gcd = Rgcd[1];
		}
		else if (i == N - 1) {
			gcd = Lgcd[N - 2];
		}
		else {
			gcd = Gcd(Lgcd[i - 1], Rgcd[i + 1]);
		}
		if (v[i] % gcd != 0) {
			if (maxi < gcd) {
				maxi = gcd;
				idx = i;
			}
		}
	}
	if (maxi == -1)
		cout << maxi;
	else
		cout << maxi << " " << v[idx];

	return 0;
}