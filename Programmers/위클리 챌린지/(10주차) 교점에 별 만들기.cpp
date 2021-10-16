#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

vector<string> solution(vector<vector<int>> line) {
	vector<string> answer;
	vector<pll> meets;
	FOR(i, 0, LEN(line) - 1) {
		FOR(j, i + 1, LEN(line) - 1) {
			ll A = line[i][0]; ll B = line[i][1]; ll E = line[i][2];
			ll C = line[j][0]; ll D = line[j][1]; ll F = line[j][2];
			ll down = A * D - B * C;
			if (down == 0) continue;
			ll xup = B * F - E * D;
			ll yup = E * C - A * F;
			if (xup % down != 0 || yup % down != 0) continue;
			ll x = xup / down;
			ll y = yup / down;
			meets.push_back({ y, x });
		}
	}
	ll miny = LINF; ll maxy = -LINF;
	ll minx = LINF; ll maxx = -LINF;
	FOR(i, 0, LEN(meets) - 1) {
		miny = min(miny, meets[i].first);
		maxy = max(maxy, meets[i].first);
		minx = min(minx, meets[i].second);
		maxx = max(maxx, meets[i].second);
	}
	FOR(i, 0, LEN(meets) - 1) {
		meets[i].first -= miny;
		meets[i].second -= minx;
	}
	maxy -= miny; maxx -= minx;
	string tmp = "";
	FOR(i, 0, maxx) {
		tmp += '.';
	}
	FOR(i, 0, maxy) {
		answer.push_back(tmp);
	}
	FOR(i, 0, LEN(meets) - 1) {
		answer[maxy - meets[i].first][meets[i].second] = '*';
	}

	return answer;
}