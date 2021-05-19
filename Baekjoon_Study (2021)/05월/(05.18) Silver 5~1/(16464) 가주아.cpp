#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool Check(int x) {
	while (x % 2 == 0 && x != 1) {
		x /= 2;
	}
	return (x == 1);
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int K;
		cin >> K;
		cout << (Check(K) ? "GoHanGang" : "Gazua") << "\n";
	}

	return 0;
}