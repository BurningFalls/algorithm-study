#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int cnt[1001] = { 0, };

int main() {
	FASTIO;
	int M;
	cin >> M;
	double num;
	while (cin >> num) {
		num += 0.0000000001;
		int tmp = floor(num * M);
		cnt[tmp]++;
	}
	FOR(i, 0, M - 1)
		cout << cnt[i] << " ";

	return 0;
}