#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
string arr[21], arr2[21];

bool Increasing() {
	bool flag = true;
	FOR(i, 1, N) {
		if (arr[i] != arr2[i])
			return false;
	}
	return true;
}

bool Decreasing() {
	bool flag = true;
	FOR(i, 1, N) {
		if (arr[N - i + 1] != arr2[i])
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
		arr2[i] = arr[i];
	}
	sort(arr + 1, arr + N + 1);
	bool f1, f2;
	f1 = Increasing();
	f2 = Decreasing();
	if (!f1 && !f2)
		cout << "NEITHER";
	else if (f1)
		cout << "INCREASING";
	else if (f2)
		cout << "DECREASING";

	return 0;
}