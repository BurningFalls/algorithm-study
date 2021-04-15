#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
bool not_Prime[1000001] = { 0, };

bool Check(int x) {
	set<int> s;
	while (true) {
		if (x == 1)
			return true;
		if (!s.count(x))
			s.insert(x);
		else
			return false;
		int sum = 0;
		while (x) {
			sum += (x % 10) * (x % 10);
			x /= 10;
		}
		x = sum;
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 2, N) {
		if (not_Prime[i]) continue;
		if (Check(i))
			cout << i << "\n";
		for (int j = 2; i * j <= N; j++) {
			not_Prime[i * j] = 1;
		}
	}


	return 0;
}