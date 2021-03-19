#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int D[101];

int main() {
	FASTIO;
	int N, A, B, C;
	cin >> N >> A >> B >> C;
	FOR(i, 1, N) {
		cin >> D[i];
	}
	sort(D + 1, D + N + 1, greater<int>());
	double maximum = C / A;
	double up_sum = C;
	double down_sum = A;
	FOR(i, 1, N) {
		up_sum += D[i];
		down_sum += B;
		if (maximum < up_sum / down_sum)
			maximum = up_sum / down_sum;
		else
			break;
	}
	cout << (int)maximum;

	return 0;
}