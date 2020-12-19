#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[20001];

int main() {
	FASTIO;
	int N;
	int minimum = 10001;
	int maximum = 0;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
		minimum = min(minimum, arr[i]);
		maximum = max(maximum, arr[i]);
	}
	int min_sum = 2100000000;
	int ans = 10001;
	FOR(i, minimum, maximum) {
		int sum = 0;
		FOR(j, 1, N)
			sum += abs(i - arr[j]);
		if (sum < min_sum) { 
			min_sum = sum;
			ans = i;
		}
	}
	cout << ans;

	return 0;
}