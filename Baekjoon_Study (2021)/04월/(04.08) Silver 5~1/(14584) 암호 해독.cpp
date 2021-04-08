#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	string s;
	int N;
	string arr[21];
	cin >> s;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	int slen = s.size();
	bool flag = false;
	FOR(i, 0, 25) {
		FOR(j, 0, slen - 1) {
			s[j] = (s[j] - 'a' + 1) % 26 + 'a';
		}
		FOR(j, 1, N) {
			if (s.find(arr[j]) != string::npos) {
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}
	cout << s;


	return 0;
}