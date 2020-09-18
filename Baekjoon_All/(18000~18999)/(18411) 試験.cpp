#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int arr[3];
	FOR(i, 0, 2)
		cin >> arr[i];
	sort(arr, arr + 3);
	cout << arr[1] + arr[2];

	return 0;
}