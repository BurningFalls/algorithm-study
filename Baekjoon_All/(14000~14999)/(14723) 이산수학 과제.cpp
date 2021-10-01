#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	int N;
	cin >> N;
	int idx = 1;
	while ((idx + 1) * idx / 2 < N)
		idx++;
	int sum = idx + 1;
	N = (idx + 1) * idx / 2 - N;
	cout << N + 1 << " " << sum - (N + 1);


	return 0;
}