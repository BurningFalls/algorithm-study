#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int arr[3] = { 1, 0, 0 };
	string s;
	cin >> s;
	FOR(i, 0, s.size() - 1) {
		if (s[i] == 'A')
			swap(arr[0], arr[1]);
		else if (s[i] == 'B')
			swap(arr[1], arr[2]);
		else if (s[i] == 'C')
			swap(arr[0], arr[2]);
	}
	FOR(i, 0, 2) {
		if (arr[i] == 1) {
			cout << i + 1;
			break;
		}
	}

	return 0;
}