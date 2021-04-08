#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int X, N;
	cin >> X >> N;
	if (N == 0) {
		if (X <= 0)
			cout << 0;
		else
			cout << "INFINITE";
	}
	else if (N == 1) {
		if (X < 0)
			cout << "INFINITE";
		else if (X >= 0)
			cout << 0;
	}
	else {
		if (N % 2 == 1)
			cout << "ERROR";
		else if (N % 2 == 0) {
			if (X <= 0)
				cout << 0;
			else if (X > 0) {
				if (X % 2 == 1)
					cout << X / (N / 2);
				else if (X % 2 == 0)
					cout << X / (N / 2) - 1;
			}
		}
	}

	return 0;
}