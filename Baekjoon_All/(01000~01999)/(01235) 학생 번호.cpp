#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N;
string arr[1001];
set<string> s;
string sub[1001];

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	int len = arr[1].size();
	ROF(i, len - 1, 0) {
		s.clear();
		FOR(j, 1, N)
			sub[j] += arr[j][i];
		bool flag = true;
		FOR(j, 1, N) {
			if (s.count(sub[j])) {
				flag = false;
				break;
			}
			else
				s.insert(sub[j]);
		}
		if (flag) {
			cout << len - i;
			break;
		}
	}


	return 0;
}