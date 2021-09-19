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
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (j == 1 || j == N || i == 1 || i == N
				|| i == j || i + j == N + 1)
				cout << '*';
			else
				cout << ' ';
		}
		cout << "\n";
	}


	return 0;
}