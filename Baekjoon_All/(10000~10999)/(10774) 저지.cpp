#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char arr[1000001];
bool use[1000001] = { 0, };

bool Cmp(char x, char y) {
	char arr[3] = { 'S', 'M', 'L' };
	int a = 0, b = 0;
	FOR(i, 0, 2) {
		if (arr[i] == x)
			a = i;
		if (arr[i] == y)
			b = i;
	}
	return a >= b;
}

int main() {
	FASTIO;
	int J, A;
	cin >> J >> A;
	FOR(i, 1, J)
		cin >> arr[i];
	int cnt = 0;
	FOR(i, 1, A) {
		char x;
		int y;
		cin >> x >> y;
		if (use[y]) continue;
		bool flag = Cmp(arr[y], x);
		if (flag) {
			cnt++;
			use[y] = 1;
		}
	}
	cout << cnt;


	return 0;
}