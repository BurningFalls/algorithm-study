#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int fibo[51];

int main() {
	FASTIO;
	fibo[0] = 1;
	fibo[1] = 2;
	FOR(i, 2, 42)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	int T;
	cin >> T;
	while (T--) {
		vector<int> v;
		int N;
		cin >> N;
		int idx = 42;
		while (N > 0) {
			while (N < fibo[idx])
				idx--;
			v.push_back(fibo[idx]);
			N -= fibo[idx];
		}
		int len = v.size();
		ROF(i, len - 1, 0)
			cout << v[i] << " ";
		cout << "\n";
	}

	return 0;
}