#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)

int solution(string word) {
	int answer = 0;
	int section_cnt[5];
	int tmp = 1;
	char ch[5] = { 'A', 'E', 'I', 'O', 'U' };
	section_cnt[0] = 1;
	FOR(i, 1, 4) {
		tmp *= 5;
		section_cnt[i] = section_cnt[i - 1] + tmp;
	}
	answer += word.size();
	FOR(i, 0, word.size() - 1) {
		int idx = 0;
		FOR(j, 0, 4) {
			if (word[i] == ch[j])
				idx = j;
		}
		answer += idx * section_cnt[4 - i];
	}

	return answer;
}