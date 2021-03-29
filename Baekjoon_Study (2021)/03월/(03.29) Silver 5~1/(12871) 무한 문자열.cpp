#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string s1, s2;
vector<string> v1, v2;

bool Func() {
	int len1 = s1.size();
	int len2 = s2.size();
	FOR(i, 1, len1) {
		if (len1 % i != 0) continue;
		int tmp = len1 / i;
		string n1 = "";
		FOR(j, 0, i - 1) {
			n1 += s1[j];
		}
		string nn1 = "";
		FOR(j, 1, tmp) {
			nn1 += n1;
		}
		bool flag = true;
		FOR(j, 0, len1 - 1) {
			if (nn1[j] != s1[j]) {
				flag = false;
				break;
			}
		}
		if (!flag) continue;
		v1.push_back(n1);
	}
	FOR(i, 1, len2) {
		if (len2 % i != 0) continue;
		int tmp = len2 / i;
		string n2 = "";
		FOR(j, 0, i - 1) {
			n2 += s2[j];
		}
		string nn2 = "";
		FOR(j, 1, tmp) {
			nn2 += n2;
		}
		bool flag = true;
		FOR(j, 0, len2 - 1) {
			if (nn2[j] != s2[j]) {
				flag = false;
				break;
			}
		}
		if (!flag) continue;
		v2.push_back(n2);
	}
	int vlen1 = v1.size();
	int vlen2 = v2.size();
	FOR(i, 0, vlen1 - 1) {
		FOR(j, 0, vlen2 - 1) {
			if (v1[i] == v2[j]) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	FASTIO;
	cin >> s1 >> s2;
	cout << Func();

	return 0;
}