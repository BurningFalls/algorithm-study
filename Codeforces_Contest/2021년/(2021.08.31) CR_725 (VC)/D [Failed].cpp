#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[2][32001];

void Func(int x, int idx) {
	int num = 2;
	while (x != 1) {
		while (x % num == 0) {
			arr[idx][num] += 1;
			x /= num;
		}
		num++;
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		FOR(i, 0, 1)
			FOR(j, 0, 32000)
			arr[i][j] = 0;
		int a, b, k;
		cin >> a >> b >> k;
		Func(a, 0);
		Func(b, 1);
		int left = 0;
		int right = 0;
		int maxi = 0;
		int sum = 0;
		FOR(i, 1, 32000) {
			if (arr[0][i] == 0 && arr[1][i] == 0) continue;
			if (arr[0][i] > arr[1][i]) left++;
			else if (arr[0][i] < arr[1][i]) right++;
			maxi += abs(arr[0][i] - arr[1][i]);
			sum += (arr[0][i] + arr[1][i]);
		}
		int mini;
		if (a % b == 0 || b % a == 0)
			mini = 1;
		else
			mini = 2;
		if (sum < k) {
			cout << "No\n";
		}
		else {
			bool flag = false;
			FOR(i, mini, maxi) {
				if ((k - i) % 2 == 0) {
					flag = true;
					break;
				}
			}
			cout << (flag ? "Yes" : "No") << "\n";
		}
	}

	return 0;
}