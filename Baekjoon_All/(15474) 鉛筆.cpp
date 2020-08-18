#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	int N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	if (N == 1)
		cout << min(B, D);
	else
		cout << min(((N - 1) / A + 1) * B, ((N - 1) / C + 1) * D);

	return 0;
}