#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char Map[4][4] = { {'A', 'C', 'A', 'G'},
				{'C', 'G', 'T', 'A'},
				{'A', 'T', 'C', 'G'},
				{'G', 'A', 'G', 'T'} };
int arr[4] = { 'A', 'G', 'C', 'T' };
vector<char> v;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		char x;
		cin >> x;
		v.push_back(x);
	}
	FOR(i, 1, N - 1) {
		char x = v.back();
		v.pop_back();
		char y = v.back();
		v.pop_back();
		int a, b;
		FOR(j, 0, 3) {
			if (arr[j] == x)
				a = j;
		}
		FOR(j, 0, 3) {
			if (arr[j] == y)
				b = j;
		}
		v.push_back(Map[a][b]);
	}
	cout << v[0];

	return 0;
}