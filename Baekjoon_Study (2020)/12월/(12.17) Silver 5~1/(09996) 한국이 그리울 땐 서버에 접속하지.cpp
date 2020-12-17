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
	string pattern, left = "", right = "";
	bool flag = false;
	cin >> pattern;
	FOR(i, 0, pattern.size() - 1) {
		if (pattern[i] == '*') {
			flag = true;
			continue;
		}
		if (!flag)
			left += pattern[i];
		else if (flag)
			right += pattern[i];
	}
	FOR(i, 1, N) {
		string s;
		bool flag2 = true;
		cin >> s;
		if (left.size() + right.size() > s.size())
			flag2 = false;
		else {
			FOR(i, 0, left.size() - 1) {
				if (s[i] != left[i]) {
					flag2 = false;
					break;
				}
			}
			FOR(i, 0, right.size() - 1) {
				if (s[s.size() - 1 - i] != right[right.size() - 1 - i]) {
					flag2 = false;
					break;
				}
			}
		}
		if (flag2)
			cout << "DA";
		else
			cout << "NE";
		cout << "\n";
	}

	return 0;
}