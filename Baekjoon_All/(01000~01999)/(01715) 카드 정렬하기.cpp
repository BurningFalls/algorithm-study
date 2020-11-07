#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

priority_queue<int> pq;

int main() {
	FASTIO;
	int N;
	int ans = 0;
	cin >> N;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		pq.push(-num);
	}
	while (pq.size() >= 2) {
		int a = -pq.top();
		pq.pop();
		int b = -pq.top();
		pq.pop();
		ans += (a + b);
		pq.push(-(a + b));
	}
	cout << ans;

	return 0;
}