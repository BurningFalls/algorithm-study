#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

map<string, vector<int>> mp;

int Find(vector<string> words, int score) {
	int words_len = words.size();
	int cnt = 0;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		string tmp = (*it).first;
		int vlen = (*it).second.size();
		bool flag = true;
		FOR(i, 0, words_len - 1) {
			if (tmp.find(words[i]) == string::npos) {
				flag = false;
			}
		}
		if (flag) {
			FOR(i, 0, vlen - 1) {
				if ((*it).second[i] >= score)
					cnt++;
			}
		}
	}

	return cnt;
}

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	int info_len = info.size();
	FOR(i, 0, info_len - 1) {
		string words = "";
		string score = "";
		int slen = info[i].size();
		FOR(j, 0, slen - 1) {
			if (info[i][j] >= '0' && info[i][j] <= '9')
				score += info[i][j];
			else
				words += info[i][j];
		}
		words.pop_back();
		int iscore = stoi(score);
		mp[words].push_back(iscore);
	}

	int query_len = query.size();
	FOR(t, 0, query_len - 1) {
		string qs = query[t];
		int qs_len = qs.size();
		vector<string> word_v;
		string tmp = "";
		int score = 0;
		FOR(i, 0, qs_len - 1) {
			if (qs[i] == ' ') {
				if (tmp != "and" && tmp != "-")
					word_v.push_back(tmp);
				tmp = "";
			}
			else {
				tmp += qs[i];
			}
		}
		score = stoi(tmp);
		int result = Find(word_v, score);
		answer.push_back(result);
	}

	return answer;
}