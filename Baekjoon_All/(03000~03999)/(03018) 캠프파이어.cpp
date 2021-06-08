#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll song[101] = { 0, };
int arr[101];

int main() {
	FASTIO;
	int N, E;
	cin >> N;
	cin >> E;
	int idx = 0;
	FOR(t, 1, E) {
		int K;
		int one_flag = false;
		cin >> K;
		FOR(i, 1, K) {
			cin >> arr[i];
			if (arr[i] == 1)
				one_flag = true;
		}
		if (one_flag) {
			FOR(i, 1, K) {
				song[arr[i]] |= (1LL << idx);
			}
			idx++;
		}
		else if (!one_flag) {
			ll tmp = 0;
			FOR(i, 1, K) {
				tmp |= song[arr[i]];
			}
			FOR(i, 1, K) {
				song[arr[i]] = tmp;
			}
		}
	}
	FOR(i, 1, N) {
		if (song[i] == (1LL << idx) - 1)
			cout << i << "\n";
	}

	return 0;
}