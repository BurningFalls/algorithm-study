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

vector<int> is_prime(111, 1);
vector<int> prime;
vector<int> special;

void Find_Prime() {
	int sqrtn = sqrt(110);
	FOR(i, 2, sqrtn) {
		if (!is_prime[i]) continue;
		prime.push_back(i);
		for (int j = i * 2; j <= 110; j += i) {
			is_prime[j] = 0;
		}
	}
	FOR(i, sqrtn + 1, 110) {
		if (!is_prime[i]) continue;
		prime.push_back(i);
	}
}

int main() {
	FASTIO;
	Find_Prime();
	FOR(i, 0, LEN(prime) - 2) {
		special.push_back(prime[i] * prime[i + 1]);
	}
	int N;
	cin >> N;
	int ub = upper_bound(ALL(special), N) - special.begin();
	cout << special[ub];


	return 0;
}