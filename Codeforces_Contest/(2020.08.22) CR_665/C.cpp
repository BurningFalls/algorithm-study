#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int arr[100001];
int s_arr[100001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		int minimum;
		cin >> N;
		FOR(i, 1, N) {
			cin >> arr[i];
			s_arr[i] = arr[i];
			if (i == 1)
				minimum = arr[1];
			else
				minimum = min(minimum, arr[i]);
		}
		sort(s_arr + 1, s_arr + N + 1);
		bool flag = true;
		FOR(i, 1, N) {
			if (arr[i] != s_arr[i]) {
				if (arr[i] % minimum != 0) {
					flag = false;
					break;
				}
			}
		}
		if (flag)
			cout << "YES";
		else
			cout << "NO";
		cout << "\n";
	}

	return 0;
}