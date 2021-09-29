#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define LEN(s) int(s.size())

int solution(vector<vector<int>> sizes) {
	int left_maxi = 0, right_maxi = 0;
	FOR(i, 0, LEN(sizes) - 1) {
		left_maxi = max(left_maxi, min(sizes[i][0], sizes[i][1]));
		right_maxi = max(right_maxi, max(sizes[i][0], sizes[i][1]));
	}
	int answer = left_maxi * right_maxi;
	return answer;
}