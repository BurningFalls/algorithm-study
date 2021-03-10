#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int arr[101];

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N)
		cin >> arr[i];
	int left = 1, right = K;
	int sum = 0;
	FOR(i, left, right)
		sum += arr[i];
	int maximum = -10001;
	while (true) {
		maximum = max(maximum, sum);
		sum -= arr[left];
		left++;
		right++;
		if (right > N)
			break;
		sum += arr[right];
	}
	cout << maximum;

	return 0;
}