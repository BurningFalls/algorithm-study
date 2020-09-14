#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int Y, M, D;
		cin >> Y >> M >> D;
		int temp = (Y - 1) * (20 + 19) * 5;
		temp += 5 * ((Y - 1) / 3);
		if (Y % 3 == 0) {
			temp += (M - 1) * 20;
		}
		else {
			temp += ((M - 1) / 2) * 39;
			if (M % 2 == 0)
				temp += 20;
		}
		temp += (D - 1);
		cout << 196470 - temp << "\n";
	}

	return 0;
}