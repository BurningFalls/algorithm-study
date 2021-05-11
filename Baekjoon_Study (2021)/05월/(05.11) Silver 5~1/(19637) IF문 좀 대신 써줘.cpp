#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

struct INF {
	string name;
	int start;
	int end;
};

INF arr[100001];

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	int idx = 0;
	FOR(i, 1, N) {
		string s;
		int num;
		cin >> s >> num;
		arr[i] = { s, idx, num };
		idx = num + 1;
	}
	FOR(i, 1, M) {
		int num;
		cin >> num;
		int left = 1, right = N;
		int ans = 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (num >= arr[mid].start) {
				ans = mid;
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		cout << arr[ans].name << "\n";
	}

	return 0;
}