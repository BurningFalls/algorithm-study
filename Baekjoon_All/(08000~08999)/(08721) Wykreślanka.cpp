#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int arr[1000001];

int main() {
	FASTIO;
	int n;
	cin >> n;
	FOR(i, 1, n)
		cin >> arr[i];
	int idx = 1;
	FOR(i, 1, n) {
		if (arr[i] == idx)
			idx++;
	}
	cout << n - (idx - 1);

	return 0;
}