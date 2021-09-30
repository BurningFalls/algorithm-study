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
	while (true) {
		int N;
		cin >> N;
		if (N == 0)
			break;
		if (N > 1000000 && N <= 5000000)
			N -= N / 10;
		else if (N > 5000000)
			N -= N / 5;
		cout << N << "\n";
	}

	return 0;
}