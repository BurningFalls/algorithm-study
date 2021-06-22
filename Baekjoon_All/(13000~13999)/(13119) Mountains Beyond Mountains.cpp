#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int H[100001];

int main() {
	FASTIO;
	int N, M, X;
	cin >> N >> M >> X;
	FOR(i, 1, M)
		cin >> H[i];

	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (i >= N - H[j] + 1) {
				if (i == N - X + 1)
					cout << '*';
				else
					cout << '#';
			}
			else {
				if (i == N - X + 1)
					cout << '-';
				else if (j % 3 == 0 && i > N - X + 1 && i < N - H[j] + 1)
					cout << '|';
				else
					cout << '.';
			}
		}
		cout << "\n";
	}


	return 0;
}