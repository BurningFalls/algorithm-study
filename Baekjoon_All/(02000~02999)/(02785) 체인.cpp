#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

deque<int> dq;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		dq.push_back(num);
	}
	sort(dq.begin(), dq.end());
	int ans = 0;
	while (dq.size() != 1) {
		dq.front() -= 1;
		ans += 1;
		if (dq.front() == 0)
			dq.pop_front();
		if (dq.size() == 1)
			break;
		int x = dq.back();
		dq.pop_back();
		int y = dq.back();
		dq.pop_back();
		dq.push_back(x + y + 1);
	}
	cout << ans;

	return 0;
}