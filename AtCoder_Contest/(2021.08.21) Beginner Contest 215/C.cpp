#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	string S;
	int K;
	cin >> S >> K;
	bool flag = true;
	int cnt = 0;
	sort(S.begin(), S.end());
	while (flag) {
		cnt++;
		if (cnt == K)
			break;
		flag = next_permutation(S.begin(), S.end());
	}
	cout << S;

	return 0;
}