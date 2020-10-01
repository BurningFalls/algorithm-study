#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[1500000];

int main() {
	FASTIO;
	arr[0] = 0;
	arr[1] = 1;
	FOR(i, 2, 1499999)
		arr[i] = (arr[i - 2] + arr[i - 1]) % 1000000;
	ll n;
	cin >> n;
	cout << arr[n % 1500000];

	return 0;
}