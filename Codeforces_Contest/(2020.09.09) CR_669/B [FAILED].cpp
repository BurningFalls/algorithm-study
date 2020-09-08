#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int arr[1001];
vector<int> ans;
bool visited[1001] = { 0, };

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int n;
		int maximum = 0;
		ans.clear();
		cin >> n;
		FOR(i, 1, n) {
			visited[i] = 0;
			cin >> arr[i];
		}
		sort(arr + 1, arr + 1 + n);
		ans.push_back(arr[n]);
		visited[n] = 1;
		int max_gcd;
		int g, node = 0;
		FOR(i, 0, n - 2) {
			int temp = ans[i];
			max_gcd = 0;
			FOR(j, 1, n) {
				if (visited[j]) continue;
				g = gcd(temp, arr[j]);
				if (max_gcd < g) {
					max_gcd = g;
					node = j;
				}
			}
			visited[node] = 1;
			ans.push_back(arr[node]);
		}

		FOR(i, 0, n - 1)
			cout << ans[i] << " ";
		cout << "\n";
	}

	return 0;
}