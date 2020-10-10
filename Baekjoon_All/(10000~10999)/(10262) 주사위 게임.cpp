#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int arr1[4], arr2[4];
	FOR(i, 0, 3)
		cin >> arr1[i];
	FOR(i, 0, 3)
		cin >> arr2[i];
	int cnt1 = 0, cnt2 = 0;
	FOR(i, arr1[0], arr1[1]) {
		FOR(j, arr1[2], arr1[3]) {
			FOR(k, arr2[0], arr2[1]) {
				FOR(l, arr2[2], arr2[3]) {
					if (i + j > k + l)
						cnt1++;
					else if (i + j < k + l)
						cnt2++;
				}
			}
		}
	}
	if (cnt1 > cnt2)
		cout << "Gunnar";
	else if (cnt1 == cnt2)
		cout << "Tie";
	else if (cnt1 < cnt2)
		cout << "Emma";

	return 0;
}