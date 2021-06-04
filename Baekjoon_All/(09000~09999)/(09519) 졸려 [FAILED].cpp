#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char arr[1011];
char tmp[1011];
char ch[1011];

int main() {
	FASTIO;
	int X;
	string s;
	cin >> X;
	cin >> s;
	int len = s.size();
	FOR(i, 0, len - 1)
		arr[i + 1] = s[i];
	int idx = 2;
	int cnt = 0;
	int mid = (len + 1) / 2;
	while (true) {
		if (idx <= mid) {
			idx = idx * 2 - 1;
		}
		else if (idx > mid) {
			idx = (len + 1 - idx) * 2;
		}
		cnt++;
		if (idx == 2)
			break;
	}
	X %= cnt;
	FOR(i, 1, len) {
		if (i % 2 == 0)
			ch[i] = (len + 1) - i / 2;
		else if (i % 2 == 1)
			ch[i] = (i + 1) / 2;
	}
	while (X--) {
		FOR(i, 1, len)
			tmp[ch[i]] = arr[i];
		FOR(i, 1, len)
			arr[i] = tmp[i];
	}
	FOR(i, 1, len)
		cout << arr[i];


	return 0;
}