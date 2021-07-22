#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool Check(string s, int start) {
	int len = s.size();
	int left = start - 1, right = start + 1;
	while (left >= 0 && right <= len - 1) {
		if (s[left] != s[right])
			return false;
		left--;
		right++;
	}
	return true;
}

string Make_String(string s, int start) {
	int len = s.size();
	int left = start;
	int right = len - start - 1;
	string tmp = "";
	if (left >= right) {
		FOR(i, 0, start)
			tmp += s[i];
	}
	else if (left < right) {
		ROF(i, len - 1, start) {
			tmp += s[i];
		}
	}
	return tmp;
}

int main() {
	FASTIO;
	int Q;
	cin >> Q;
	while (Q--) {
		string s1, s2;
		cin >> s1 >> s2;
		int len1 = s1.size();
		int len2 = s2.size();
		bool ans_flag = false;
		FOR(start, 0, len2 - 1) {
			bool flag = Check(s2, start);
			if (!flag) continue;
			string tmp = Make_String(s2, start);
			if (s1.find(tmp) != string::npos) {
				ans_flag = true;
				break;
			}
		}
		if (ans_flag)
			cout << "YES";
		else
			cout << "NO";
		cout << "\n";
	}


	return 0;
}