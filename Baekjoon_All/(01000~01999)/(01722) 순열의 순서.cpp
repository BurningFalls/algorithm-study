#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll fact[21];

int main() {
	FASTIO;
	fact[0] = 1;
	FOR(i, 1, 20)
		fact[i] = fact[i - 1] * i;
	int N;
	cin >> N;
	int kind;
	cin >> kind;
	bool check[21] = { 0, };
	int arr[21];
	if (kind == 1) {
		ll K;
		cin >> K;
		FOR(i, 1, N) {
			FOR(j, 1, N) {
				if (check[j]) continue;
				if (fact[N - i] < K) {
					K -= fact[N - i];
				}
				else {
					arr[i] = j;
					check[j] = 1;
					break;
				}
			}
		}
		FOR(i, 1, N)
			cout << arr[i] << " ";
	}
	else if (kind == 2) {
		FOR(i, 1, N)
			cin >> arr[i];
		ll ans = 0;
		FOR(i, 1, N) {
			FOR(j, 1, arr[i] - 1) {
				if (check[j] == 0)
					ans += fact[N - i];
			}
			check[arr[i]] = 1;
		}
		cout << ans + 1;
	}


	return 0;
}