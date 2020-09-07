#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int arr[4];
	FOR(i, 0, 3)
		cin >> arr[i];
	sort(arr, arr + 4);
	cout << arr[0] * arr[2];

	return 0;
}