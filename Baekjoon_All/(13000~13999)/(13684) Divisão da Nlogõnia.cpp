#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	while (true) {
		int K;
		cin >> K;
		if (K == 0)
			break;
		int N, M;
		cin >> N >> M;
		FOR(i, 1, K) {
			int a, b;
			cin >> b >> a;
			if (a == M || b == N)
				cout << "divisa";
			else if (a > M&& b > N)
				cout << "NE";
			else if (a > M&& b < N)
				cout << "NO";
			else if (a < M && b > N)
				cout << "SE";
			else if (a < M && b < N)
				cout << "SO";
			cout << "\n";
		}
	}

	return 0;
}