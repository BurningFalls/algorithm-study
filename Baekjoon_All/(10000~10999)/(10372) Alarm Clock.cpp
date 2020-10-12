#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int n;
int cnt[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

pii func() {
	int temp = 0;
	FOR(i, 0, 23) {
		FOR(j, 0, 59) {
			temp = (cnt[i / 10] + cnt[i % 10]);
			temp += (cnt[j / 10] + cnt[j % 10]);
			if (temp == n)
				return { i, j };
		}
	}
	return { -1, -1 };
}

int main() {
	FASTIO;
	pii temp;
	cin >> n;
	temp = func();
	if (temp.first == -1)
		cout << "Impossible";
	else {
		int h = temp.first;
		int m = temp.second;
		if (h < 10)
			cout << 0;
		cout << h;
		cout << ":";
		if (m < 10)
			cout << 0;
		cout << m;
	}

	return 0;
}