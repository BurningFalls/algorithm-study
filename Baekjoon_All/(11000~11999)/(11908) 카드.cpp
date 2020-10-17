#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[2223];

int main() {
	FASTIO;
	int n;
	cin >> n;
	FOR(i, 1, n) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1);
	int sum = 0;
	FOR(i, 1, n - 1)
		sum += arr[i];
	cout << sum;

	return 0;
}