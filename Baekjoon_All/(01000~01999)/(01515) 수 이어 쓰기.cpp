#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[1000000];

int main() {
	FASTIO;
	string s;
	cin >> s;
	int slen = s.size();
	string numbering = "";
	int prev = 0;
	FOR(i, 1, 100000) {
		string tmp = to_string(i);
		int tmplen = tmp.size();
		numbering += tmp;
		FOR(j, prev, prev + tmplen - 1) {
			arr[j] = i;
		}
		prev = prev + tmplen;
	}
	int numlen = numbering.size();
	int idx = 0;
	FOR(i, 0, slen - 1) {
		while (true) {
			if (s[i] != numbering[idx])
				idx++;
			else
				break;
		}
		idx++;
	}
	cout << arr[idx - 1];

	return 0;
}