#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	cin >> N;
	string ans = "";
	int min = 5;
	FOR(i, 1, N) {
		string s;
		int hard;
		cin >> s >> hard;
		if (min > hard) {
			min = hard;
			ans = s;
		}
	}
	cout << ans;


	return 0;
}