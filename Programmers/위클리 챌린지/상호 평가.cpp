#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)

string solution(vector<vector<int>> scores) {
	string answer = "";
	int len = scores.size();
	FOR(i, 0, len - 1) {
		int maxi = -1;
		int mini = 101;
		int max_cnt = 0;
		int min_cnt = 0;
		double sum = 0;
		FOR(j, 0, len - 1) {
			maxi = max(maxi, scores[j][i]);
			mini = min(mini, scores[j][i]);
			sum += scores[j][i];
		}
		FOR(j, 0, len - 1) {
			if (scores[j][i] == maxi)
				max_cnt++;
			if (scores[j][i] == mini)
				min_cnt++;
		}
		double avg;
		if ((scores[i][i] == maxi && max_cnt == 1) ||
			(scores[i][i] == mini && min_cnt == 1)) {
			sum -= scores[i][i];
			avg = sum / (len - 1);
		}
		else
			avg = sum / len;
		if (avg >= 90)
			answer += 'A';
		else if (80 <= avg && avg < 90)
			answer += 'B';
		else if (70 <= avg && avg < 80)
			answer += 'C';
		else if (50 <= avg && avg < 70)
			answer += 'D';
		else if (avg < 50)
			answer += 'F';
	}

	return answer;
}