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

void DQ(int l, int r) {
	if (l == r) {
		cout << "!" << " " << l << endl;
		return;
	}
	int mid = (l + r) / 2;
	cout << "?" << " " << l << " " << mid << endl;
	int cnt = 0;
	FOR(i, 0, mid - l) {
		int num;
		cin >> num;
		if (l <= num && num <= mid) {
			cnt++;
		}
	}
	if (cnt % 2 == 1) {
		DQ(l, mid);
	}
	else {
		DQ(mid + 1, r);
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		DQ(1, N);
	}

	return 0;
}