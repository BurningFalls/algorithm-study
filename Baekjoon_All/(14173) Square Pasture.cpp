#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	int arr1[4], arr2[4];
	int t1, t2, t3;
	FOR(i, 0, 3) {
		cin >> arr1[i] >> arr2[i];
	}
	sort(arr1, arr1 + 4);
	sort(arr2, arr2 + 4);
	t1 = arr1[3] - arr1[0];
	t2 = arr2[3] - arr2[0];
	t3 = max(t1, t2);
	cout << t3 * t3;


	return 0;
}