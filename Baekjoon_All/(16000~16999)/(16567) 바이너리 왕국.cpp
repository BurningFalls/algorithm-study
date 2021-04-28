#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool arr[1000002] = { 0, };

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N)
		cin >> arr[i];
	int ans = 0;
	bool flag = false;
	FOR(i, 1, N + 1) {
		if (arr[i])
			flag = true;
		if (flag && !arr[i]) {
			flag = false;
			ans++;
		}
	}
	FOR(i, 1, M) {
		int kind, num;
		cin >> kind;
		if (kind == 0) {
			cout << ans << "\n";
		}
		else if (kind == 1) {
			cin >> num;
			if (arr[num] == 1) continue;
			arr[num] = 1;
			if (num != 1 && num != N &&
				arr[num - 1] && arr[num + 1])
				ans--;
			else if (!arr[num - 1] && !arr[num + 1])
				ans++;
		}
	}


	return 0;
}