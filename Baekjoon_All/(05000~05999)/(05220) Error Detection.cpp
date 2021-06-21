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
	FOR(i, 1, N) {
		int num;
		bool bit;
		cin >> num >> bit;
		int cnt = 0;
		FOR(i, 0, 15) {
			if ((1 << i) & num)
				cnt++;
		}
		if (cnt % 2 == bit)
			cout << "Valid";
		else
			cout << "Corrupt";
		cout << "\n";
	}


	return 0;
}