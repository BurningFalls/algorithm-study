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

bool is_Prime(ll n) {
	if (n == 1) {
		return false;
	}
	ll sqrtn = sqrt(n);
	FOR(i, 2, sqrtn) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int solution(int n, int k) {
	int answer = 0;
	vector<int> v;
	v.push_back(0);
	while (n) {
		v.push_back(n % k);
		n /= k;
	}
	v.push_back(0);
	int len = LEN(v);
	string tmp = "";
	ROF(i, len - 1, 0) {
		if (v[i] == 0 && !tmp.empty()) {
			bool flag = is_Prime(stol(tmp));
			if (flag) {
				answer++;
			}
			tmp = "";
		}
		else if (v[i] != 0) {
			tmp += v[i] + '0';
		}
	}

	return answer;
}