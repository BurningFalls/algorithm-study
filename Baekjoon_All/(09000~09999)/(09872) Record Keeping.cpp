#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	map<string, int> mp;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		string arr[3];
		FOR(j, 0, 2)
			cin >> arr[j];
		sort(arr, arr + 3);
		string sum = "";
		FOR(j, 0, 2)
			sum += arr[j];
		if (mp.count(sum))
			mp[sum] += 1;
		else
			mp[sum] = 1;
	}
	int maxi = 0;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		maxi = max(maxi, (*it).second);
	}
	cout << maxi;

	return 0;
}