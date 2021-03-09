#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N;
int arr[2001];
vector<int> v;

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[N - i + 1];
	v.push_back(arr[1]);
	int cnt = 1;
	FOR(i, 2, N) {
		if (v.back() < arr[i]) {
			v.push_back(arr[i]);
			cnt++;
		}
		else {
			int lb = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[lb] = arr[i];
		}
	}
	cout << N - cnt;

	return 0;
}