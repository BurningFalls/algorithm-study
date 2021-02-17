#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

string arr[101];

bool is_P(string s) {
	int len = s.size();
	FOR(i, 0, len / 2 - 1) {
		if (s[i] != s[len - 1 - i])
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	bool flag = false;
	while (T--) {
		flag = false;
		int K;
		string temp;
		cin >> K;
		FOR(i, 1, K)
			cin >> arr[i];
		FOR(i, 1, K) {
			FOR(j, 1, K) {
				if (i == j) continue;
				temp = arr[i] + arr[j];
				if (is_P(temp)) {
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		if (!flag)
			cout << 0;
		else
			cout << temp;
		cout << "\n";
	}


	return 0;
}