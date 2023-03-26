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

int N;
vector<int> is_prime(MAX + 1, 1);
vector<int> primes;

void Find_Prime() {
	int sqrtx = sqrt(N);
	FOR(i, 2, sqrtx) {
		if (!is_prime[i]) continue;
		primes.push_back(i);
		for (int j = i * i; j <= N; j += i) {
			is_prime[j] = 0;
		}
	}
	FOR(i, sqrtx + 1, N) {
		if (!is_prime[i]) continue;
		primes.push_back(i);
	}
}

int main() {
	FASTIO;
	cin >> N;
	Find_Prime();

	int input;
	int left = 0, right = LEN(primes) - 1;
	int ans = right;
	while (left <= right) {
		int mid = (left + right) / 2;
		cout << "? " << primes[mid] << endl;
		cin >> input;
		if (input) {
			left = mid + 1;
		}
		else if (!input) {
			ans = min(ans, mid);
			right = mid - 1;
		}
	}

	cout << "! " << primes[ans] << endl;

	return 0;
}