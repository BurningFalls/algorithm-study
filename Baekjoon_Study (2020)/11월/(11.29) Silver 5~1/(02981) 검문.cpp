#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[101];

int GCD(int a, int b) {
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	int gcd = arr[2] - arr[1];
	FOR(i, 3, N) {
		gcd = GCD(gcd, arr[i] - arr[i - 1]);
	}
	set<int> s;
	for (int i = 2; i * i <= gcd; i++) {
		if (gcd % i == 0) {
			s.insert(i);
			s.insert(gcd / i);
		}
	}
	s.insert(gcd);
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << (*it) << " ";
	}

	return 0;
}