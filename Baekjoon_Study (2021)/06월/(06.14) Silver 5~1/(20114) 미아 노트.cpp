#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char arr[1001];

int main() {
	FASTIO;
	int N, H, W;
	cin >> N >> H >> W;
	FOR(i, 1, N * W)
		arr[i] = '?';
	FOR(i, 1, H) {
		FOR(j, 1, N * W) {
			char x;
			cin >> x;
			if (arr[j] == '?')
				arr[j] = x;
		}
	}
	vector<char> v;
	for (int i = 1; i <= N * W; i += W) {
		char x = '?';
		FOR(j, i, i + W - 1) {
			if (arr[j] != '?')
				x = arr[j];
		}
		v.push_back(x);
	}
	for (char c : v)
		cout << c;


	return 0;
}