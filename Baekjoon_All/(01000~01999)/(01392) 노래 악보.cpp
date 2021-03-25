#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int music[10001] = { 0, };

int main() {
	FASTIO;
	int N, Q;
	cin >> N >> Q;
	int end = 0;
	FOR(i, 1, N) {
		int B;
		cin >> B;
		FOR(j, end, end + B - 1)
			music[j] = i;
		end = end + B;
	}
	FOR(i, 1, Q) {
		int tim;
		cin >> tim;
		cout << music[tim] << "\n";
	}


	return 0;
}