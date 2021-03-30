#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int X, Y, M;
	int maximum = 0;
	cin >> X >> Y >> M;
	for (int i = 0; i * X <= M; i++) {
		for (int j = 0; i * X + j * Y <= M; j++) {
			maximum = max(maximum, i * X + j * Y);
		}
	}
	cout << maximum;

	return 0;
}