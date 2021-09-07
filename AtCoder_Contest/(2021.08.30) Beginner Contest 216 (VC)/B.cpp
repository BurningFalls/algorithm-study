#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

pair<string, string> arr[1001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i].first >> arr[i].second;
	}
	bool flag = false;
	FOR(i, 1, N) {
		FOR(j, i + 1, N) {
			if (arr[i].first == arr[j].first && arr[i].second == arr[j].second) {
				flag = true;
				break;
			}
		}
	}
	cout << (flag ? "Yes" : "No");

	return 0;
}