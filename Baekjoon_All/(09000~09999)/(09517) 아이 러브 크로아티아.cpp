#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

pair<int, char> arr[101];

int main() {
	FASTIO;
	int K, N;
	cin >> K >> N;
	int idx = K;
	int time = 210;
	FOR(i, 1, N) {
		int T;
		char Z;
		cin >> T >> Z;
		arr[i] = { T, Z };
	}
	FOR(i, 1, N) {
		time -= arr[i].first;
		if (time <= 0) {
			cout << idx;
			break;
		}
		if (arr[i].second == 'T') {
			idx++;
			if (idx == 9)
				idx = 1;
		}
	}

	return 0;
}