#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	priority_queue<int> pq;
	cin >> N;
	FOR(i, 1, N) {
		int a;
		cin >> a;
		if (a == 0) {
			if (pq.empty())
				cout << "-1\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			FOR(j, 1, a) {
				int num;
				cin >> num;
				pq.push(num);
			}
		}
	}


	return 0;
}