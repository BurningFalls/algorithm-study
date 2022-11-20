#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	vector<int> v(N);
	vector<int> cnt1(K + 1, 0);
	vector<int> cnt2(K + 1, 0);
	int kind1 = 0, kind2 = 0;
	FOR(i, 0, N - 1) {
		cin >> v[i];
		if (cnt2[v[i]]++ == 0) kind2++;
	}
	if (cnt1[v[0]]++ == 0) kind1++;
	if (--cnt2[v[0]] == 0) kind2--;

	int ans = INF;
	int left = 0, right = 0;
	while (right < N) {
		if (kind1 == K) {
			if (kind2 == K) {
				ans = min(ans, right - left + 1);
			}
			if (--cnt1[v[left]] == 0) kind1--;
			if (cnt2[v[left]]++ == 0) kind2++;
			left++;
		}
		else if (kind1 < K) {
			right++;
			if (right >= N) break;
			if (cnt1[v[right]]++ == 0) kind1++;
			if (--cnt2[v[right]] == 0) kind2--;
		}
	}

	cout << (ans == INF ? 0 : ans);

	return 0;
}