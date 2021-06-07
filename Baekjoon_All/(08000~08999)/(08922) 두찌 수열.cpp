#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int arr[16];
int ch[16];

bool Check() {
	FOR(i, 1, N) {
		if (arr[i] != 0)
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		FOR(i, 1, N)
			cin >> arr[i];
		int cnt = 0;
		bool flag = false;
		while (cnt <= 1001) {
			if (Check()) {
				flag = true;
				break;
			}
			FOR(i, 1, N)
				ch[i] = abs(arr[i % N + 1] - arr[i]);
			FOR(i, 1, N)
				arr[i] = ch[i];
			cnt++;
		}
		cout << (flag ? "ZERO" : "LOOP") << "\n";
	}


	return 0;
}