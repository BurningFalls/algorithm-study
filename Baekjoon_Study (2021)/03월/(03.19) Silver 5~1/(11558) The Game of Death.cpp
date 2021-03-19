#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[10001];
bool visited[10001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		memset(visited, 0, sizeof(visited));
		int N;
		cin >> N;
		FOR(i, 1, N)
			cin >> arr[i];
		int loc = 1;
		int cnt = 0;
		bool flag = true;
		while (loc != N) {
			loc = arr[loc];
			if (visited[loc]) {
				flag = false;
				break;
			}
			visited[loc] = 1;
			cnt++;
		}
		if (!flag)
			cout << 0;
		else
			cout << cnt;
		cout << "\n";
	}

	return 0;
}