#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

pii arr[101];

int main() {
	FASTIO;
	int N, B;
	cin >> N >> B;
	FOR(i, 1, N) {
		int x, y;
		cin >> x >> y;
		arr[i] = { x, y };
	}
	int ans = INF;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			int vert = arr[i].first + 1;
			int hori = arr[j].second + 1;
			int a = 0, b = 0, c = 0, d = 0;
			FOR(k, 1, N) {
				if (arr[k].first < vert && arr[k].second < hori) a++;
				if (arr[k].first < vert && arr[k].second > hori) b++;
				if (arr[k].first > vert && arr[k].second < hori) c++;
				if (arr[k].first > vert && arr[k].second > hori) d++;
			}
			int maxi = max({ a, b, c, d });
			ans = min(ans, maxi);
		}
	}
	cout << ans;

	return 0;
}