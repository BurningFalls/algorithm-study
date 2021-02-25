#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

queue<pii> q;
map<pii, int> mp;
int A, B, C, D;

int BFS() {
	q.push( { 0, 0 } );
	mp[{0, 0}] = 0;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		int vis = mp[{a, b}];
		q.pop();
		if (a == C && b == D)
			return vis;
		if (a != A && !mp.count({ A, b })) {
			q.push({ A, b });
			mp[{A, b}] = vis + 1;
		}
		if (b != B && !mp.count({ a, B })) {
			q.push({ a, B });
			mp[{ a, B }] = vis + 1;
		}
		if (a != 0 && !mp.count({ 0, b })) {
			q.push({ 0, b });
			mp[{0, b}] = vis + 1;
		}
		if (b != 0 && !mp.count({ a, 0 })) {
			q.push({ a, 0 });
			mp[{a, 0}] = vis + 1;
		}
		if (a != 0 && b != B) {
			if (a + b <= B && !mp.count({ 0, a + b })) {
				q.push({ 0, a + b });
				mp[{ 0, a + b }] = vis + 1;
			}
			else if (a + b > B && !mp.count({ a + b - B, B})) {
				q.push({ a + b - B, B });
				mp[{ a + b - B, B }] = vis + 1;
			}
		}
		if (a != A && b != 0) {
			if (a + b <= A && !mp.count({ a + b, 0 })) {
				q.push({ a + b, 0 });
				mp[{ a + b, 0 }] = vis + 1;
			}
			else if (a + b > A && !mp.count({ A, a + b - A })) {
				q.push({ A, a + b - A });
				mp[{ A, a + b - A }] = vis + 1;
			}
		}
	}
	return -1;
}

int main() {
	FASTIO;
	cin >> A >> B >> C >> D;
	cout << BFS();

	return 0;
}