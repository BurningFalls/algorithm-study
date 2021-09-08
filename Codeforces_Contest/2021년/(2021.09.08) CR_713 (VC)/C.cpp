#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int a, b;
char arr[400001];

bool Func() {
	int len = a + b;
	if (len % 2 == 0) {
		if (a % 2 == 1 || b % 2 == 1) {
			return false;
		}
	}
	else if (len % 2 == 1) {
		if ((a % 2 == 0 && b % 2 == 0) ||
			(a % 2 == 1 && b % 2 == 1)) {
			return false;
		}
	}
	FOR(i, 1, len) {
		if (arr[i] == '0')
			a--;
		else if (arr[i] == '1')
			b--;
	}
	FOR(i, 1, len / 2) {
		if (arr[i] != '?' && arr[len + 1 - i] == '?') {
			if (arr[i] == '0') {
				if (a >= 1) {
					arr[len + 1 - i] = '0';
					a -= 1;
				}
				else
					return false;
			}
			else if (arr[i] == '1') {
				if (b >= 1) {
					arr[len + 1 - i] = '1';
					b -= 1;
				}
				else
					return false;
			}
		}
		else if (arr[i] == '?' && arr[len + 1 - i] != '?') {
			if (arr[len + 1 - i] == '0') {
				if (a >= 1) {
					arr[i] = '0';
					a -= 1;
				}
				else
					return false;
			}
			else if (arr[len + 1 - i] == '1') {
				if (b >= 1) {
					arr[i] = '1';
					b -= 1;
				}
				else
					return false;
			}
		}
		else if (arr[i] != '?' && arr[len + 1 - i] != '?') {
			if (arr[i] != arr[len + 1 - i])
				return false;
		}
	}

	FOR(i, 1, len / 2) {
		if (arr[i] == '?' && arr[len + 1 - i] == '?') {
			if (a >= 2) {
				arr[i] = '0';
				arr[len + 1 - i] = '0';
				a -= 2;
			}
			else if (b >= 2) {
				arr[i] = '1';
				arr[len + 1 - i] = '1';
				b -= 2;
			}
			else
				return false;
		}
	}

	if (len % 2 == 1) {
		int idx = len / 2 + 1;
		if (arr[idx] == '?') {
			if (a >= 1) {
				arr[idx] = '0';
				a--;
			}
			else if (b >= 1) {
				arr[idx] = '1';
				b--;
			}
			else
				return false;
		}	
	}
	if (a != 0 || b != 0)
		return false;
	return true;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		cin >> a >> b;
		int len = a + b;
		FOR(i, 1, len)
			cin >> arr[i];
		bool flag = Func();
		if (flag) {
			FOR(i, 1, len)
				cout << arr[i];
		}
		else
			cout << -1;
		cout << "\n";
	}

	return 0;
}