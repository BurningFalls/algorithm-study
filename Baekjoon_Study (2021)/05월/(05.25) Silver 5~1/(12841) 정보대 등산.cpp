#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int road[100001];
int L[100001];
int R[100001];
ll sumL[100001];
ll sumR[100001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	sumL[0] = 0, sumR[0] = 0;
	FOR(i, 1, N)
		cin >> road[i];
	FOR(i, 1, N - 1) {
		cin >> L[i];
		sumL[i] = sumL[i - 1] + L[i];
	}
	FOR(i, 1, N - 1) {
		cin >> R[i];
		sumR[i] = sumR[i - 1] + R[i];
	}
	ll mini = 100000000000;
	int idx = 0;
	FOR(i, 1, N) {
		ll Sum = sumL[i - 1] + road[i] + sumR[N - 1] - sumR[i - 1];
		if (mini > Sum) {
			mini = Sum;
			idx = i;
		}
	}
	cout << idx << " " << mini;


	return 0;
}