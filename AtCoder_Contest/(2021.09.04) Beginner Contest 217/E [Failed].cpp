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
int idx[200001];

int main() {
	FASTIO;
	int Q;
	int mini = 1;
	int cnt = 1;
	cin >> Q;
	FOR(q, 1, Q) {
		int c, x;
		cin >> c;
		if (c == 1) {
			cin >> x; 
			mp[x] += 1;
			idx[cnt] = x;
			cnt++;
		}
		else if (c == 2) {
			cout << idx[mini] << "\n";
			if (--mp[idx[mini]] == 0)
				mp.erase(idx[mini]++);
			mini++;
		}
		else if (c == 3) {
			int left = 1;
			for (auto it = mp.begin(); it != mp.end(); it++) {
				FOR(i, left, left + (*it).second - 1)
					idx[i] = (*it).first;
				left += (*it).second;
			}
			mini = 1;
		}
	}


	return 0;
}