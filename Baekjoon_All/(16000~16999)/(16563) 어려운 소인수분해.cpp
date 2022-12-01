#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MAX 5000000

vector<int> prime(MAX + 1, 1);
vector<int> min_prime(MAX + 1);

void Find_Prime() {
	int sqrtn = sqrt(MAX);
	FOR(i, 2, sqrtn) {
		if (!prime[i]) continue;
		for (int j = i * i; j <= MAX; j += i) {
			prime[j] = 0;
			min_prime[j] = min(min_prime[j], i);
		}
	}
}

int main() {
	FASTIO;
	FOR(i, 1, MAX) {
		min_prime[i] = i;
	}
	Find_Prime();
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		while (num != 1) {
			cout << min_prime[num] << " ";
			num /= min_prime[num];
		}
		cout << "\n";
	}


	return 0;
}