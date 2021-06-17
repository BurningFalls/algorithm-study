#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[100001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	bool flag = true;
	int cnt = 0;
	bool flag2 = false;
	FOR(i, 1, N - 1) {
		if (arr[i] < arr[i + 1]) {
			if (flag2) {
				flag = false;
				break;
			}
		}
		else if (arr[i] == arr[i + 1]) {
			flag = false;
			break;
		}
		else if (arr[i] > arr[i + 1]) {
			flag2 = true;
		}
	}
	cout << (flag ? "YES" : "NO");

	return 0;
}