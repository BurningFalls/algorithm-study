#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[200001];
int multi[200001];

int main() {
	FASTIO;
	int N, Q;
	cin >> N >> Q;
	FOR(i, 1, N)
		cin >> arr[i];
	multi[1] = 1;
	FOR(i, 1, 4)
		multi[1] *= arr[i];
	int ans = multi[1];
	FOR(i, 2, N) {
		multi[i] = (multi[i - 1] / arr[i - 1]) * arr[(i + 2) % N + 1];
		ans += multi[i];
	}
	FOR(i, 1, Q) {
		int num;
		cin >> num;
		int tmp = 0;
		ROF(j, 4, 1) {
			tmp += 2 * multi[(num + N - j) % N + 1];
			multi[(num + N - j) % N + 1] *= (-1);
		}
		ans -= tmp;
		cout << ans << "\n";
	}


	return 0;
}