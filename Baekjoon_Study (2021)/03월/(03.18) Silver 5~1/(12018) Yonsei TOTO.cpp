#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int arr[101];
vector<int> v;

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N) {
		int P, L;
		cin >> P >> L;
		FOR(j, 1, P) {
			cin >> arr[j];
		}
		if (L > P)
			v.push_back(1);
		else {
			sort(arr + 1, arr + P + 1, greater<int>());
			v.push_back(arr[L]);
		}
	}
	sort(v.begin(), v.end());
	int idx = 0;
	int sum = 0;
	int cnt = 0;
	while (idx < N) {
		if (sum + v[idx] <= M) {
			sum += v[idx];
			cnt++;
			idx++;
		}
		else {
			break;
		}
	}
	cout << cnt;

	return 0;
}