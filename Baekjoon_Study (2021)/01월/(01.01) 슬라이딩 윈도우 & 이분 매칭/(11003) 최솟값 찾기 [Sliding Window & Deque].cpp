#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[5000001];
deque<pii> dq;

int main() {
	FASTIO;
	int N, L;
	cin >> N >> L;
	FOR(i, 1, N)
		cin >> arr[i];
	FOR(i, 1, N) {
		while (!dq.empty() && dq.back().first > arr[i])
			dq.pop_back();
		if (!dq.empty() && dq.front().second <= i - L)
			dq.pop_front();
		dq.push_back({ arr[i], i });
		cout << dq.front().first << " ";
	}

	return 0;
}