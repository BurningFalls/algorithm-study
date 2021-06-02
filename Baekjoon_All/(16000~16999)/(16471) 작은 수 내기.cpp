#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[100001];
priority_queue<int> pq;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	FOR(i, 1, N) {
		int num;
		cin >> num;
		pq.push(num);
	}
	sort(arr + 1, arr + N + 1, greater<int>());

	int cnt = 0;
	FOR(i, 1, N) {
		if (pq.empty()) break;
		if (arr[i] >= pq.top()) continue;
		pq.pop();
		cnt++;
	}

	if (cnt >= (N + 1) / 2)
		cout << "YES";
	else
		cout << "NO";


	return 0;
}