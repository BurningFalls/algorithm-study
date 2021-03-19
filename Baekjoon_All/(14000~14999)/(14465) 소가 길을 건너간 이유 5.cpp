#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

bool Break[100001] = { 0, };

int main() {
	FASTIO;
	int N, K, B;
	cin >> N >> K >> B;
	FOR(i, 1, B) {
		int num;
		cin >> num;
		Break[num] = 1;
	}
	int left = 1, right = K;
	int cnt = 0;
	FOR(i, left, right) {
		if (Break[i]) {
			cnt++;
		}
	}
	int minimum = cnt;
	while (true) {
		cnt -= Break[left];
		left++;
		right++;
		if (right > N) {
			break;
		}
		cnt += Break[right];
		minimum = min(minimum, cnt);
	}
	cout << minimum;

	return 0;
}