#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[1001] = { 0, };

int main() {
	FASTIO;
	int N;
	cin >> N;
	int cnt;
	int idx = 1;
	FOR(num, 1, N) {
		cnt = 0;
		while (true) {
			if (arr[idx] == 0) {
				cnt++;
				if (cnt == num + 1) {
					arr[idx] = num;
					idx = idx % N + 1;
					break;
				}
			}
			idx = idx % N + 1;
		}
	}
	FOR(i, 1, N)
		cout << arr[i] << " ";

	return 0;
}