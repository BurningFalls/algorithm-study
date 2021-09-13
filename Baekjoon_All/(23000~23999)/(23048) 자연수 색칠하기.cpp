#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int color[500001] = { 0, };

int main() {
	FASTIO;
	int N;
	cin >> N;
	color[1] = 1;
	int idx = 1;
	FOR(i, 2, N) {
		if (color[i] != 0) continue;
		idx++;
		for (int j = i; j <= N; j += i)
			color[j] = idx;
	}
	cout << idx << "\n";
	FOR(i, 1, N)
		cout << color[i] << " ";


	return 0;
}