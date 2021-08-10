#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int ans1 = 0, ans2 = 0, ans3 = 0;
int arr[3][3] = { 0, };

void Func() {
	FOR(x1, 1, 10) {
		FOR(x2, 1, 10) {
			FOR(x3, 1, 10) {
				if ((arr[0][0] * x1 + arr[1][0] * x2 == arr[2][0] * x3) &&
					(arr[0][1] * x1 + arr[1][1] * x2 == arr[2][1] * x3) &&
					(arr[0][2] * x1 + arr[1][2] * x2 == arr[2][2] * x3)) {
					ans1 = x1;
					ans2 = x2;
					ans3 = x3;
					return;
				}
			}
		}
	}
}

int main() {
	FASTIO;
	
	string s;
	cin >> s;
	int len = s.size();
	string a = "", b = "", c = "";
	int flag = 0;
	FOR(i, 0, len - 1) {
		if (s[i] == '+') {
			flag = 1;
			continue;
		}
		else if (s[i] == '=') {
			flag = 2;
			continue;
		}
		if (flag == 0)
			a += s[i];
		else if (flag == 1)
			b += s[i];
		else if (flag == 2)
			c += s[i];
	}
	int alen = a.size();
	int blen = b.size();
	int clen = c.size();
	FOR(i, 0, alen - 1) {
		if (a[i] == 'C') {
			if (i != (alen - 1) && a[i + 1] >= '2' && a[i + 1] <= '9')
				arr[0][0] += (a[i + 1] - '0');
			else
				arr[0][0]++;
		}
		else if (a[i] == 'H') {
			if (i != (alen - 1) && a[i + 1] >= '2' && a[i + 1] <= '9')
				arr[0][1] += (a[i + 1] - '0');
			else
				arr[0][1]++;
		}
		else if (a[i] == 'O') {
			if (i != (alen - 1) && a[i + 1] >= '2' && a[i + 1] <= '9')
				arr[0][2] += (a[i + 1] - '0');
			else
				arr[0][2]++;
		}
	}
	FOR(i, 0, blen - 1) {
		if (b[i] == 'C') {
			if (i != (blen - 1) && b[i + 1] >= '2' && b[i + 1] <= '9')
				arr[1][0] += (b[i + 1] - '0');
			else
				arr[1][0]++;
		}
		else if (b[i] == 'H') {
			if (i != (blen - 1) && b[i + 1] >= '2' && b[i + 1] <= '9')
				arr[1][1] += (b[i + 1] - '0');
			else
				arr[1][1]++;
		}
		else if (b[i] == 'O') {
			if (i != (blen - 1) && b[i + 1] >= '2' && b[i + 1] <= '9')
				arr[1][2] += (b[i + 1] - '0');
			else
				arr[1][2]++;
		}
	}
	FOR(i, 0, clen - 1) {
		if (c[i] == 'C') {
			if (i != (clen - 1) && c[i + 1] >= '2' && c[i + 1] <= '9')
				arr[2][0] += (c[i + 1] - '0');
			else
				arr[2][0]++;
		}
		else if (c[i] == 'H') {
			if (i != (clen - 1) && c[i + 1] >= '2' && c[i + 1] <= '9')
				arr[2][1] += (c[i + 1] - '0');
			else
				arr[2][1]++;
		}
		else if (c[i] == 'O') {
			if (i != (clen - 1) && c[i + 1] >= '2' && c[i + 1] <= '9')
				arr[2][2] += (c[i + 1] - '0');
			else
				arr[2][2]++;
		}
	}
	
	Func();

	cout << ans1 << " " << ans2 << " " << ans3;


	return 0;
}