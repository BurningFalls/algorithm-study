#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string arr[51];

bool cmp(string s1, string s2) {
	int len1 = s1.size();
	int len2 = s2.size();
	if (len1 == len2)
		return s1 < s2;
	return len1 < len2;
}

bool Check(string s1, string s2) {
	int len1 = s1.size();
	int len2 = s2.size();
	FOR(i, 0, len1 - 1) {
		if (s1[i] != s2[i])
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1, cmp);
	int cnt = 0;
	FOR(i, 1, N) {
		bool flag = true;
		FOR(j, i + 1, N) {
			if (Check(arr[i], arr[j])) {
				flag = false;
				break;
			}
		}
		if (flag)
			cnt++;
	}
	cout << cnt;

	return 0;
}