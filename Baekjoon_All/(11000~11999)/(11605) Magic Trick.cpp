#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int n;
	int arr[101];
	FOR(i, 1, 100)
		arr[i] = i;
	cin >> n;
	FOR(i, 1, n) {
		string s;
		int num;
		cin >> s >> num;
		FOR(i, 1, 100) {
			if (arr[i] == -1) continue;
			if (s == "ADD") {
				arr[i] += num;
			}
			else if (s == "SUBTRACT") {
				arr[i] -= num;
				if (arr[i] < 0)
					arr[i] = -1;
			}
			else if (s == "MULTIPLY") {
				arr[i] *= num;
			}
			else if (s == "DIVIDE") {
				if (arr[i] % num == 0)
					arr[i] /= num;
				else
					arr[i] = -1;
			}
		}
	}
	int cnt = 0;
	FOR(i, 1, 100) {
		if (arr[i] == -1)
			cnt++;
	}
	cout << cnt;

	return 0;
}