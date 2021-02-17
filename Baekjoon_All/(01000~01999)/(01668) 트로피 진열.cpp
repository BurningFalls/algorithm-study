#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int arr[51];

int main() {
	FASTIO;
	int N;
	int maximum = 0;
	int left = 1, right = 1;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
		maximum = max(maximum, arr[i]);
	}
	int num;
	num = arr[1];
	FOR(i, 2, N) {
		if (arr[i] > num) {
			num = arr[i];
			left++;
		}
		if (arr[i] == maximum)
			break;
	}
	num = arr[N];
	ROF(i, N - 1, 1) {
		if (arr[i] > num) {
			num = arr[i];
			right++;
		}
		if (arr[i] == maximum)
			break;
	}
	cout << left << "\n" << right;


	return 0;
}