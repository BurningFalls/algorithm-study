﻿#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	string s;
	cin >> s;
	int len = s.size();
	int idx = 1;
	int tmp = sqrt(len);
	FOR(i, 1, tmp) {
		if (len % i == 0) {
			idx = i;
		}
	}
	vector<vector<char>> v(idx, vector<char>(len / idx));
	FOR(j, 0, len / idx - 1) {
		FOR(i, 0, idx - 1) {
			v[i][j] = s[j * idx + i];
		}
	}
	
	FOR(i, 0, idx - 1) {
		FOR(j, 0, len / idx - 1) {
			cout << v[i][j];
		}
	}
	

	return 0;
}