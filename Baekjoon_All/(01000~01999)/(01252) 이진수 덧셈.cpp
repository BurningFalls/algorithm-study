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

int main() {
	FASTIO;
	string A, B;
	cin >> A >> B;
	reverse(ALL(A));
	reverse(ALL(B));
	int lenA = LEN(A);
	int lenB = LEN(B);
	if (lenA > lenB) {
		FOR(i, 1, lenA - lenB) {
			B += '0';
		}
	}
	else if (lenA < lenB) {
		FOR(i, 1, lenB - lenA) {
			A += '0';
		}
	}
	vector<int> v;
	bool flag = false;
	FOR(i, 0, LEN(A) - 1) {
		int tmp = (A[i] - '0') + (B[i] - '0') + flag;
		if (tmp >= 2) {
			tmp -= 2;
			flag = true;
		}
		else {
			flag = false;
		}
		v.push_back(tmp);
	}
	if (flag) {
		v.push_back(1);
	}
	while (LEN(v) > 1 && v.back() == 0) {
		v.pop_back();
	}
	ROF(i, LEN(v) - 1, 0) {
		cout << v[i];
	}

	return 0;
}