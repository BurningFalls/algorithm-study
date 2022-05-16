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
	int N, M;
	int Ac, D;
	int Sr, Sc;
	cin >> N >> M;
	cin >> Ac >> D;
	cin >> Sr >> Sc;

	bool flag = false;
	if (D == 0) {
		if (N % 2 == 0) {
			flag = true;
		}
		else if (N % 2 == 1) {
			flag = (Sr != N);
		}
	}
	else if (D == 1) {
		if (N % 2 == 0) {
			flag = (Sr != N);
		}
		else if (N % 2 == 1) {
			flag = true;
		}
	}

	cout << (flag ? "NO..." : "YES!");

	return 0;
}