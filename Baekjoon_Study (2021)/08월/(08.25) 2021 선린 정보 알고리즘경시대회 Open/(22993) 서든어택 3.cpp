#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
ll arr[100001];

int main() {
	FASTIO;
	cin >> N;
	ll num;
	cin >> num;
	FOR(i, 1, N - 1)
		cin >> arr[i];
	sort(arr + 1, arr + N);
	bool flag = true;
	FOR(i, 1, N - 1) {
		if (num > arr[i])
			num += arr[i];
		else {
			flag = false;
			break;
		}
	}
	cout << (flag ? "Yes" : "No");

	return 0;
}