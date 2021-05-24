#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int K;
	cin >> K;
	int cnt = 0;
	int divide = 2;
	while (K != 1 && divide * divide <= K) {
		if (K % divide == 0) {
			K /= divide;
			cnt++;
		}
		else
			divide++;
	}
	int ans = 0;
	while (cnt != 0) {
		cnt /= 2;
		ans++;
	}
	cout << ans;


	return 0;
}