#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int arr1[3];
	int arr2[3];
	int sum = 0;
	FOR(i, 0, 2)
		cin >> arr1[i];
	FOR(i, 0, 2)
		cin >> arr2[i];
	FOR(i, 0, 2) {
		if (arr1[i] < arr2[i])
			sum += arr2[i] - arr1[i];
	}
	cout << sum;

	return 0;
}