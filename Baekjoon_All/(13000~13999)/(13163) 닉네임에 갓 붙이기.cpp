#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

string arr[101];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		cin.ignore();
		getline(cin, arr[i]);
	}
	FOR(i, 1, N) {
		string ch = "god";
		int len = arr[i].size();
		bool flag = false;
		FOR(j, 0, len - 1) {
			if (flag && arr[i][j] != ' ')
				ch += arr[i][j];
			if (!flag && arr[i][j] == ' ')
				flag = true;
		}
		cout << ch << "\n";
	}

	return 0;
}