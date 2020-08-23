#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int arr[1000001];

int main() {
	FASTIO;
	map<int, int> mp;
	map<int, int>::iterator it;
	int N;
	int num;
	cin >> N;
	FOR(i, 0, N - 1) {
		cin >> num;
		arr[i] = num;
		mp.insert(make_pair(num, 0));
	}
	int cnt = 0;
	for (it = mp.begin(); it != mp.end(); it++) {
		(*it).second = cnt;
		cnt++;
	}
	FOR(i, 0, N - 1) {
		cout << mp[arr[i]] << " ";
	}

	return 0;
}