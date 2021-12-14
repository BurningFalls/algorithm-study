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
#define MAX 2000003

vector<bool> nums(MAX + 1, 0);
vector<bool> check(MAX + 1, 0);

int main() {
	FASTIO;
	int N;
	cin >> N;
	set<int> s;
	FOR(i, 0, N - 1) {
		int num;
		cin >> num;
		nums[num] = 1;
	}
	if (!nums[0]) {
		cout << 0;
		return 0;
	}

	FOR(i, 1, MAX) {
		if (!nums[i]) continue;
		FOR(j, 1, MAX / i) {
			if (!nums[j]) continue;
			check[i * j] = 1;
		}
	}
	FOR(i, 1, MAX) {
		if (check[i]) continue;
		cout << i;
		break;
	}


	return 0;
}