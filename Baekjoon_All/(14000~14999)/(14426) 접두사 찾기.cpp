#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string arr[10001];

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	int cnt = 0;
	FOR(i, 1, M) {
		string tmp;
		cin >> tmp;
		int tmp_len = tmp.size();
		FOR(j, 1, N) {
			int arr_len = arr[j].size();
			if (tmp_len > arr_len) continue;
			bool flag = true;
			FOR(k, 0, tmp_len - 1) {
				if (tmp[k] != arr[j][k]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;

	return 0;
}