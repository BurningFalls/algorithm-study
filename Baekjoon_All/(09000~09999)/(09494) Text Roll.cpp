#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

string arr[1001];

int main() {
	FASTIO;
	while (true) {
		int N;
		cin >> N;
		cin.ignore();
		if (N == 0)
			break;
		FOR(i, 1, N) {
			getline(cin, arr[i]);
		}
		int pos = 0;
		FOR(i, 1, N) {
			int len = arr[i].size();
			while (pos <= len - 1) {
				if (arr[i][pos] == ' ') {
					break;
				}
				else {
					pos++;
				}
			}
		}
		cout << pos + 1 << "\n";
	}

	return 0;
}