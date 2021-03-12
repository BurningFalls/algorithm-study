#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int M, N;
set<string> s;
vector<string> ans_v;

string arr[10] = { "zero", "one", "two", "three", "four", "five",
					"six", "seven", "eight", "nine" };

int main() {
	FASTIO;
	cin >> M >> N;
	FOR(num, M, N) {
		int a = num / 10;
		int b = num % 10;
		string tmp;
		if (a == 0)
			tmp = arr[b];
		else
			tmp = arr[a] + " " + arr[b];
		s.insert(tmp);
	}
	for (auto it = s.begin(); it != s.end(); it++) {
		string sa = "", sb = "";
		int len = (*it).size();
		bool flag = false;
		FOR(i, 0, len - 1) {
			if ((*it)[i] == ' ') {
				flag = true;
				continue;
			}
			if (!flag)
				sa += (*it)[i];
			else
				sb += (*it)[i];
		}
		string ans = "";
		FOR(i, 0, 9) {
			if (sa == arr[i])
				ans += (i + '0');
		}
		FOR(i, 0, 9) {
			if (sb == arr[i])
				ans += (i + '0');
		}
		ans_v.push_back(ans);
	}
	int ans_len = ans_v.size();
	FOR(i, 0, ans_len - 1) {
		if (i != 0 && i % 10 == 0)
			cout << "\n";
		cout << ans_v[i] << " ";
	}

	return 0;
}