#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string arr[201];

int main() {
	FASTIO;
	int idx = 1;
	while (true) {
		int N;
		cin >> N;
		if (N == 0)
			break;
		cin.ignore();
		FOR(i, 1, N)
			getline(cin, arr[i]);
		sort(arr + 1, arr + N + 1);
		cout << idx << "\n";
		FOR(i, 1, N)
			cout << arr[i] << "\n";
		idx++;
	}


	return 0;
}