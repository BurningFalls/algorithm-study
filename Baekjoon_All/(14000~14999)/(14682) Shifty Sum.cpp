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
	int N, K;
	cin >> N >> K;
	int sum = 0;
	int tmp = 1;
	FOR(i, 0, K) {
		sum += tmp;
		tmp = tmp * 10;
	}
	cout << N * sum;


	return 0;
}