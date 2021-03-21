#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int P;
	cin >> P;
	while (P--) {
		int N, M;
		cin >> N >> M;
		int a = 1, b = 1;
		int cnt = 0;
		while (true) {
			int tmp = (a + b) % M;
			a = b;
			b = tmp;
			cnt++;
			if (a == 1 && b == 1)
				break;
		}
		cout << N << " " << cnt << "\n";
	}

	return 0;
}