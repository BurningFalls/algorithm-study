#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

map<int, int> mp;

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		mp.clear();
		int N;
		cin >> N;
		FOR(i, 1, N) {
			int num;
			cin >> num;
			mp[num] += 1;
		}
		priority_queue<int> pq;
		int size = 0;
		for (auto it = mp.begin(); it != mp.end(); it++) {
			pq.push((*it).second);
			size++;
		}
		while (size >= 2) {
			int a = pq.top();
			size--;
			pq.pop();
			int b = pq.top();
			pq.pop();
			size--;
			if (--a != 0) {
				pq.push(a);
				size++;
			}
			if (--b != 0) {
				pq.push(b);
				size++;
			}
		}
		if (size == 0)
			cout << 0;
		else
			cout << pq.top();
		cout << "\n";
	}

	return 0;
}