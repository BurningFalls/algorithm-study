#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	int sum = 0;
	FOR(i, 1, K) {
		int num;
		cin >> num;
		sum += (num + 1) / 2;
	}
	if (sum >= N)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}