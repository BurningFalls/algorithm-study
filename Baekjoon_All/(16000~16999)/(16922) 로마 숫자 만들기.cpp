#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

bool vis1[1001] = { 0, };
bool vis2[1001] = { 0, };

int main() {
	FASTIO;
	int N;
	cin >> N;
	vis1[1] = 1;
	vis1[5] = 1;
	vis1[10] = 1;
	vis1[50] = 1;
	FOR(i, 2, N) {
		if (i % 2 == 1) {
			FOR(i, 1, 1000) {
				if (vis2[i] == 1) {
					if (i + 1 <= 1000)
						vis1[i + 1] = 1;
					if (i + 5 <= 1000)
						vis1[i + 5] = 1;
					if (i + 10 <= 1000)
						vis1[i + 10] = 1;
					if (i + 50 <= 1000)
						vis1[i + 50] = 1;
					vis2[i] = 0;
				}
			}
		}
		else if (i % 2 == 0) {
			FOR(i, 1, 1000) {
				if (vis1[i] == 1) {
					if (i + 1 <= 1000)
						vis2[i + 1] = 1;
					if (i + 5 <= 1000)
						vis2[i + 5] = 1;
					if (i + 10 <= 1000)
						vis2[i + 10] = 1;
					if (i + 50 <= 1000)
						vis2[i + 50] = 1;
					vis1[i] = 0;
				}
			}
		}
	}
	int cnt = 0;
	FOR(i, 1, 1000) {
		if (N % 2 == 1) {
			if (vis1[i] == 1)
				cnt++;
		}
		else if (N % 2 == 0) {
			if (vis2[i] == 1)
				cnt++;
		}
	}
	cout << cnt;

	return 0;
}