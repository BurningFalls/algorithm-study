#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define pdd pair<double, double>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	pdd arr[3];
	FOR(i, 0, 2) {
		cin >> arr[i].first >> arr[i].second;
	}
	FOR(i, 0, 2) {
		arr[i].first *= 10;
		arr[i].second *= 10;
		if (arr[i].first >= 5000)
			arr[i].first -= 500;
	}
	pair<double, char> arr2[3];
	FOR(i, 0, 2) {
		arr2[i].first = arr[i].second / arr[i].first;
	}
	arr2[0].second = 'S';
	arr2[1].second = 'N';
	arr2[2].second = 'U';
	sort(arr2, arr2 + 3);
	cout << arr2[2].second;

	return 0;
}