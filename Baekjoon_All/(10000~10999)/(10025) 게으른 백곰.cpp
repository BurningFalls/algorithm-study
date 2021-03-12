#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int arr[1000001] = { 0, };

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N) {
		int g, x;
		cin >> g >> x;
		arr[x] = g;
	}
	int left = 0, right = 2 * K;
	int sum = 0;
	FOR(i, left, min(right, 1000000))
		sum += arr[i];
	int maximum = 0;
	while (true) {
		maximum = max(maximum, sum);
		if (arr[left])
			sum -= arr[left];
		left++;
		right++;
		if (right > 1000000)
			break;
		if (arr[right])
			sum += arr[right];
	}
	cout << maximum;

	return 0;
}