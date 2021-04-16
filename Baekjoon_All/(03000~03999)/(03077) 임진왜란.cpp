#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

map<string, int> mp;
int arr[2501];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		string s;
		cin >> s;
		mp[s] = i;
	}
	FOR(i, 1, N) {
		string s;
		cin >> s;
		arr[i] = mp[s];
	}
	int right = N * (N - 1) / 2;
	int left = 0;
	FOR(i, 1, N) {
		FOR(j, i + 1, N) {
			if (arr[i] < arr[j])
				left++;
		}
	}
	cout << left << "/" << right;

	return 0;
}