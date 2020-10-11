#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int arr[51];

bool Check() {
	int sum = 0;
	FOR(i, 1, N) {
		sum += arr[i];
		if (sum == 0)
			return false;
	}
	return true;
}

bool Check2() {
	int sum = 0;
	ROF(i, N, 1) {
		sum += arr[i];
		if (sum == 0)
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		FOR(i, 1, N)
			cin >> arr[i];
		sort(arr + 1, arr + N + 1);
		if (!Check()) {
			if (!Check2()) {
				cout << "NO";
			}
			else {
				cout << "YES\n";
				ROF(i, N, 1)
					cout << arr[i] << " ";
			}
		}
		else {
			cout << "YES\n";
			FOR(i, 1, N)
				cout << arr[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}