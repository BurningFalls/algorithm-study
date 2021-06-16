#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool is_Sign(char x) {
	char arr[10] = { '(', ')', '[', ']', '{', '}', '.', ',', ';', ':' };
	FOR(i, 0, 9) {
		if (x == arr[i])
			return true;
	}
	return false;
}

string CH(string s) {
	int len = s.size();
	vector<char> v;
	int idx = 0;
	while (idx < len && s[idx] == ' ')
		idx++;
	while(idx < len) {
		if (is_Sign(s[idx])) {
			while (!v.empty() && v.back() == ' ')
				v.pop_back();

			if (s[idx] == '[' || s[idx] == '{')
				v.push_back('(');
			else if (s[idx] == ']' || s[idx] == '}')
				v.push_back(')');
			else if (s[idx] == ';')
				v.push_back(',');
			else
				v.push_back(s[idx]);

			idx++;
			while (idx < len && s[idx] == ' ')
				idx++;
		}
		else if (s[idx] == ' ') {
			while (!v.empty() && v.back() == ' ')
				v.pop_back();
			v.push_back(s[idx]);
			idx++;
		}
		else {
			if (s[idx] >= 'A' && s[idx] <= 'Z') {
				char x = s[idx] - 'A' + 'a';
				v.push_back(x);
			}
			else
				v.push_back(s[idx]);
			idx++;
		}
	}
	while (!v.empty() && v.back() == ' ')
		v.pop_back();
	string ans = "";
	for (int x : v) {
		ans += x;
	}
	return ans;
}

int main() {
	FASTIO;
	int K;
	cin >> K;
	cin.ignore();
	FOR(i, 1, K) {
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		s1 = CH(s1);
		s2 = CH(s2);
		cout << "Data Set " << i << ": ";
		cout << ((s1 == s2) ? "equal" : "not equal") << "\n\n";
	}


	return 0;
}