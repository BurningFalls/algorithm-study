#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

string X;
string arr[50001];
int ch[26];

bool cmp(string a, string b) {
	FOR(i, 0, min(LEN(a), LEN(b)) - 1) {
		if (a[i] != b[i])
			return ch[a[i] - 'a'] < ch[b[i] - 'a'];
	}
	return LEN(a) < LEN(b);
}

int main() {
	FASTIO;
	int N;
	cin >> X;
	FOR(i, 0, LEN(X) - 1) {
		ch[X[i] - 'a'] = i + 1;
	}
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1, cmp);
	FOR(i, 1, N)
		cout << arr[i] << "\n";


	return 0;
}