#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string A, B;
vector<int> v;

void Calc() {
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	A += '0';
	B += '0';
	int lenA = A.size();
	int lenB = B.size();
	if (lenA > lenB) {
		FOR(i, 1, lenA - lenB)
			B += '0';
	}
	else if (lenA < lenB) {
		FOR(i, 1, lenB - lenA)
			A += '0';
	}
	int len = max(lenA, lenB);
	bool flag = false;
	FOR(i, 0, len - 1) {
		int sum = (A[i] - '0') + (B[i] - '0') + flag;
		if (sum == 0) {
			v.push_back(0);
			flag = false;
		}
		else if (sum == 1) {
			v.push_back(1);
			flag = false;
		}
		else if (sum == 2) {
			v.push_back(0);
			flag = true;
		}
		else if (sum == 3) {
			v.push_back(1);
			flag = true;
		}
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		v.clear();
		cin >> A >> B;
		Calc();
		int vlen = v.size();
		bool is_use = false;
		bool flag = false;
		ROF(i, vlen - 1, 0) {
			if (!flag && v[i] == 0) {
				continue;
			}
			if (!flag && v[i] == 1) {
				flag = true;
			}
			is_use = true;
			cout << v[i];
		}
		if (!is_use)
			cout << 0;
		cout << "\n";
	}

	return 0;
}