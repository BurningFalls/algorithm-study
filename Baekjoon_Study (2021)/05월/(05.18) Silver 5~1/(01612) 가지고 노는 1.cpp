#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	cin >> N;
	if (N % 2 == 0 || N % 5 == 0)
		cout << -1;
	else if (N == 1)
		cout << 1;
	else {
		int idx = 1;
		int num = 1;
		while (num != 0) {
			num = (10 * num + 1) % N;
			idx++;
		}
		cout << idx;
	}


	return 0;
}