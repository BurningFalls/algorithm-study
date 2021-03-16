#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N;
pii arr[1001];
bool check[1001] = { 0, };

bool cmp(pii a, pii b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		int d, w;
		cin >> d >> w;
		arr[i] = { d, w };
	}
	sort(arr + 1, arr + N + 1, cmp);
	int minimum = 1;
	int sum = 0;
	FOR(i, 1, N) {
		int d = arr[i].first;
		int w = arr[i].second;
		bool flag = false;
		ROF(j, d, minimum) {
			if (check[j]) continue;
			check[j] = 1;
			sum += w;
			flag = true;
			break;
		}
		if (!flag)
			minimum = d + 1;
	}
	cout << sum;

	return 0;
}