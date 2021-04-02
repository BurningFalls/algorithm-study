#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int ds;
priority_queue<int> pq;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		if (i == 1)
			cin >> ds;
		else {
			int num;
			cin >> num;
			pq.push(num);
		}
	}
	int cnt = 0;
	while (!pq.empty() && pq.top() >= ds) {
		int tmp = pq.top();
		tmp -= 1;
		pq.pop();
		pq.push(tmp);
		ds += 1;
		cnt++;
	}
	cout << cnt;


	return 0;
}