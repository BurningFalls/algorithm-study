#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

string s;

bool DQ(int left, int right) {
	int len = right - left + 1;
	int mid = (left + right) / 2;
	bool flag = true;
	if (len == 1) {
		return true;
	}
	bool flag2 = true;
	FOR(i, 0, len / 2) {
		if (s[left + i] != s[right - i]) {
			flag2 = false;
		}
	}
	if (!flag2) {
		return false;
	}
	if (len % 2 == 1) {
		flag &= DQ(left, mid - 1);
		flag &= DQ(mid + 1, right);
	}
	else if (len % 2 == 0) {
		flag &= DQ(left, mid);
		flag &= DQ(mid + 1, right);
	}
	return flag;
}

int main() {
	FASTIO;
	cin >> s;
	bool flag = DQ(0, LEN(s) - 1);
	cout << (flag ? "AKARAKA" : "IPSELENTI");

	return 0;
}