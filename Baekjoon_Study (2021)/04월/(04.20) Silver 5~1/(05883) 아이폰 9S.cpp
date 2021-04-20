#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int arr[1002];
set<int> s;

int main() {
	FASTIO;
	cin >> N;
	arr[N + 1] = -1;
	FOR(i, 1, N) {
		cin >> arr[i];
		s.insert(arr[i]);
	}
	int ans = 0;
	for (auto it = s.begin(); it != s.end(); it++) {
		int num = (*it);
		int cnt = 0;
		int prev = -1;
		FOR(i, 1, N + 1) {
			if (arr[i] == num) continue;
			if (prev == arr[i])
				cnt++;
			else if (prev != arr[i]) {
				ans = max(ans, cnt);
				cnt = 1;
				prev = arr[i];
			}
		}
	}
	cout << ans;


	return 0;
}