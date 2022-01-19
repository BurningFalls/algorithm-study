#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

map<string, set<string>> mp;
map<string, int> cnt;

pair<string, string> Split(string s) {
	string tmp = "";
	vector<string> v;
	s += ' ';
	FOR(i, 0, LEN(s) - 1) {
		if (s[i] == ' ') {
			v.push_back(tmp);
			tmp = "";
		}
		tmp += s[i];
	}
	return { v[0], v[1] };
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;
	FOR(i, 0, LEN(id_list) - 1) {
		cnt[id_list[i]] = 0;
	}
	FOR(i, 0, LEN(report) - 1) {
		pair<string, string> tmp = Split(report[i]);
		string s1 = tmp.first;
		string s2 = tmp.second;
		mp[s2].insert(s1);
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		set<string> tmp = (*it).second;
		if (LEN(tmp) >= k) {
			for (string name : tmp) {
				cnt[name]++;
			}
		}
	}
	FOR(i, 0, LEN(id_list) - 1) {
		answer.push_back(cnt[id_list[i]]);
	}

	return answer;
}