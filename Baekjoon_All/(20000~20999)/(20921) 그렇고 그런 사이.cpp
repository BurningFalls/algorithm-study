#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, K;
int arr[4244];

int main() {
	FASTIO;
	int cnt = 0;
	cin >> N >> K;
	FOR(i, 1, N)
		arr[i] = i;
	if (K != 0) {
		FOR(i, 1, N - 1) {
			ROF(j, N - 1, i) {
				swap(arr[j], arr[j + 1]);
				cnt++;
				if (cnt == K)
					break;
			}
			if (cnt == K)
				break;
		}
	}
	FOR(i, 1, N)
		cout << arr[i] << " ";

	return 0;
}