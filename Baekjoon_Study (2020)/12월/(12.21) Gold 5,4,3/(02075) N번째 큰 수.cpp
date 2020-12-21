#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
priority_queue<int> pq;

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			int num;
			cin >> num;
			pq.push(-num);
			if (pq.size() > N)
				pq.pop();
		}
	}
	cout << -pq.top();

	return 0;
}