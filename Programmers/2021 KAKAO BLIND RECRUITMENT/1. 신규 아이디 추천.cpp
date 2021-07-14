#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string solution(string new_id) {
	string answer = "";
	string tmp = "";
	int len = new_id.size();
	FOR(i, 0, len - 1) {
		if (new_id[i] >= 'A' && new_id[i] <= 'Z')
			new_id[i] = new_id[i] - 'A' + 'a';
	}
	FOR(i, 0, len - 1) {
		if (new_id[i] >= 'a' && new_id[i] <= 'z')
			tmp += new_id[i];
		else if (new_id[i] >= '0' && new_id[i] <= '9')
			tmp += new_id[i];
		else if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
			tmp += new_id[i];
	}
	new_id = tmp;
	tmp = "";
	len = new_id.size();
	int cnt = 0;
	FOR(i, 0, len - 1) {
		if (new_id[i] == '.') {
			cnt++;
			if (cnt >= 2)
				continue;
			tmp += new_id[i];
		}
		else {
			cnt = 0;
			tmp += new_id[i];
		}
	}
	new_id = tmp;
	tmp = "";
	len = new_id.size();
	FOR(i, 0, len - 1) {
		if (i == 0 && new_id[i] == '.')
			continue;
		if (i == len - 1 && new_id[i] == '.')
			continue;
		tmp += new_id[i];
	}
	new_id = tmp;
	tmp = "";
	len = new_id.size();
	if (len == 0) {
		new_id = "a";
		len = new_id.size();
	}
	if (len >= 16) {
		FOR(i, 0, 14) {
			tmp += new_id[i];
		}
		new_id = tmp;
		tmp = "";
		len = new_id.size();
	}
	FOR(i, 0, len - 1) {
		if (i == 0 && new_id[i] == '.')
			continue;
		if (i == len - 1 && new_id[i] == '.')
			continue;
		tmp += new_id[i];
	}
	new_id = tmp;
	tmp = "";
	len = new_id.size();
	if (len <= 2) {
		char x = new_id[len - 1];
		FOR(i, 1, 3 - len)
			new_id += x;
	}
	answer = new_id;

	return answer;
}