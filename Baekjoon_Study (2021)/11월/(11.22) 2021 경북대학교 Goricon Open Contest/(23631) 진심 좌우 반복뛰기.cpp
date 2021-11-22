#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		int sum = 0;
		int tmp = K;
		int idx = 0;
		bool flag = false;
		while (true) {
			if (sum + tmp >= N) {
				break;
			}
			sum += tmp;
			tmp += K;
			idx++;
		}
		int rest = N - 1 - sum;
		int pos;
		if (idx % 2 == 1) {
			flag = true;
		}
		if (idx == 0) {
			pos = rest;
		}
		else if (flag) {
			pos = (idx + 1) / 2 * K - rest;
		}
		else if (!flag) {
			pos = -(idx + 1) / 2 * K + rest;
		}
		cout << pos << " " << (flag ? "L" : "R") << "\n";
	}


	return 0;
}