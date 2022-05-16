#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

vector<int> cnt(100001, 0);

bool compare(pii a, pii b) {
	return cnt[a.first] > cnt[b.first];
}

bool compare2(pii a, pii b) {
	return a.second < b.second;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<int> A(N);
	FOR(i, 0, N - 1) {
		cin >> A[i];
		cnt[A[i]]++;
	}

	bool flag = true;
	FOR(i, 1, 100000) {
		if (cnt[i] > N - cnt[i]) {
			flag = false;
			break;
		}
	}

	if (!flag) {
		cout << -1;
	}
	else {
		vector<pii> B(N);
		vector<pii> C(N);
		FOR(i, 0, N - 1) {
			C[i] = { A[i], i };
		}
		sort(ALL(C), compare);
		FOR(i, 0, N - 1) {
			B[i].first = C[N - i - 1].first;
			B[i].second = C[i].second;
		}
		sort(ALL(B), compare2);
		FOR(i, 0, N - 1) {
			cout << B[i].first << " ";
		}
	}

	return 0;
}