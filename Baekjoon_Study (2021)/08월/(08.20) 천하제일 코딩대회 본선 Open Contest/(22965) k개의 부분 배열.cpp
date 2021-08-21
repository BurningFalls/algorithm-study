#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

pii arr[200001];

bool cmp(pii a, pii b) {
	return a.second < b.second;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		arr[i] = { num, i };
	}
	sort(arr + 1, arr + N + 1);
	FOR(i, 1, N)
		arr[i].first = i;
	sort(arr + 1, arr + N + 1, cmp);
	int cnt = 0;
	FOR(i, 1, N - 1) {
		if (arr[i].first + 1 != arr[i + 1].first)
			cnt++;
	}
	if (cnt == 0)
		cout << 1;
	else if (cnt == 1)
		cout << 2;
	else
		cout << 3;


	return 0;
}