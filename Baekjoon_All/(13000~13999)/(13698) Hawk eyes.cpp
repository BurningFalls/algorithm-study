#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int arr[4] = { 1, 0, 0, 2 };
	string s;
	cin >> s;
	FOR(i, 0, s.size() - 1) {
		if (s[i] == 'A')
			swap(arr[0], arr[1]);
		else if (s[i] == 'B')
			swap(arr[0], arr[2]);
		else if (s[i] == 'C')
			swap(arr[0], arr[3]);
		else if (s[i] == 'D')
			swap(arr[1], arr[2]);
		else if (s[i] == 'E')
			swap(arr[1], arr[3]);
		else if (s[i] == 'F')
			swap(arr[2], arr[3]);
	}
	FOR(i, 0, 3) {
		if (arr[i] == 1)
			cout << i + 1 << "\n";
	}
	FOR(i, 0, 3) {
		if (arr[i] == 2)
			cout << i + 1;
	}

	return 0;
}