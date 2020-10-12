#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int A, B, N;
	int minimum = 1001;
	cin >> A >> B >> N;
	FOR(i, 1, N) {
		int a, b;
		int num;
		int pos1 = -1, pos2 = -1;
		cin >> a >> b;
		FOR(i, 1, b) {
			cin >> num;
			if (num == A)
				pos1 = i;
			else if (num == B)
				pos2 = i;
		}
		if (pos1 != -1 && pos2 != -1 && pos1 < pos2)
			minimum = min(minimum, a);
	}
	if (minimum == 1001)
		cout << -1;
	else
		cout << minimum;

	return 0;
}