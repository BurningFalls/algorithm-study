#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

queue<int> q[501];
char arr[5] = { 'q', 'u', 'a', 'c', 'k' };
int q_size = 0;

bool Func(int x) {
	bool flag = true;
	int pos = -1;
	FOR(i, 0, q_size) {
		if (x == 0) {
			if (q[i].empty() || q[i].back() == arr[4]) {
				pos = i;
				if (q[i].empty())
					q_size++;
				break;
			}
		}
		else {
			if (!q[i].empty() && q[i].back() == arr[x - 1]) {
				pos = i;
				break;
			}
		}
	}
	if (pos == -1)
		return false;
	q[pos].push(arr[x]);
	return true;
}

int main() {
	FASTIO;
	string s;
	cin >> s;
	int len = s.size();
	int cnt[5] = { 0, };
	FOR(i, 0, len - 1) {
		if (s[i] == 'q')
			cnt[0]++;
		else if (s[i] == 'u')
			cnt[1]++;
		else if (s[i] == 'a')
			cnt[2]++;
		else if (s[i] == 'c')
			cnt[3]++;
		else if (s[i] == 'k')
			cnt[4]++;
	}
	bool flag = true;
	FOR(i, 0, 3) {
		if (cnt[i] != cnt[i + 1])
			flag = false;
	}
	if (!flag) {
		cout << -1;
		return 0;
	}

	flag = true;
	FOR(i, 0, len - 1) {
		int idx = 0;
		FOR(j, 0, 4) {
			if (s[i] == arr[j]) {
				idx = j;
				break;
			}
		}
		flag &= Func(idx);
		if (!flag)
			break;
	}
	if (!flag)
		cout << -1;
	else
		cout << q_size;


	return 0;
}