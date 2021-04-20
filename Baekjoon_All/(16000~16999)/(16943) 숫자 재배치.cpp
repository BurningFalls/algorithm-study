#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	string A, B;
	cin >> A >> B;
	sort(A.begin(), A.end());
	bool flag = true;
	string ans = "0";
	int lenA = A.size();
	int lenB = B.size();
	if (lenA > lenB) {
		cout << -1;
		return 0;
	}
	if (lenA < lenB) {
		reverse(A.begin(), A.end());
		cout << A;
		return 0;
	}
	while (flag) {
		if (A[0] != '0') {
			if (A <= B)
				ans = max(ans, A);
			else
				break;
		}
		flag = next_permutation(A.begin(), A.end());
	}
	if (ans == "0")
		cout << -1;
	else
		cout << ans;

	return 0;
}