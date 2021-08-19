#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

bool compare(int a, int b) {
	return a > b;
}

int main() {
	FASTIO;
	int T;
	string s;
	cin >> T;
	FOR(t, 0, T - 1) {
		cin >> s;
		int len = s.size();
		bool flag = false;
		int cnt = 0;
		vector<int> v;
		FOR(i, 0, len - 1) {
			if (flag == false && s[i] == '1') {
				flag = true;
				cnt = 1;
			}
			else if (flag == true && s[i] == '1') {
				cnt++;
			}
			else if (flag == true && s[i] == '0') {
				flag = false;
				v.push_back(cnt);
			}
		}
		if (flag)
			v.push_back(cnt);
		sort(v.begin(), v.end(), compare);
		int v_len = v.size();
		int sum = 0;
		for (int i = 0; i < v_len; i += 2)
			sum += v[i];
		cout << sum << "\n";
	}

	return 0;
}