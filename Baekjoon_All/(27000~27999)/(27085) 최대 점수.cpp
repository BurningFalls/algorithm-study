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
	int N, S;
	cin >> N >> S;
	vector<ll> A(N + 1);
	FOR(i, 1, N) {
		cin >> A[i];
	}
	ll sum = 0, tlsum = 0, trsum = 0;
	int left = S - 1, tleft = S - 1;
	int right = S + 1, tright = S + 1;
	bool flag = true;
	while (flag) {
		flag = false;
		while (tleft >= 1 && 0 <= tlsum + A[tleft]) {
			tlsum += A[tleft];
			tleft--;
			if (tlsum > sum) break;
		}
		if (tlsum > sum) {
			trsum += (tlsum - sum);
			sum = tlsum;
			left = tleft;
			flag = true;
		}

		while (tright <= N && 0 <= trsum + A[tright]) {
			trsum += A[tright];
			tright++;
			if (trsum > sum) break;
		}
		if (trsum > sum) {
			tlsum += (trsum - sum);
			sum = trsum;
			right = tright;
			flag = true;
		}
	}

	cout << sum;

	return 0;
}