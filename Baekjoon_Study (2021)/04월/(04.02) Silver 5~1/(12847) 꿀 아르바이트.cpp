#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int T[100001];

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N)
		cin >> T[i];
	ll sum = 0;
	FOR(i, 1, M)
		sum += T[i];
	int left = 1, right = M;
	ll maximum = sum;
	while (true) {
		sum -= T[left];
		left++;
		right++;
		if (right > N)
			break;
		sum += T[right];
		maximum = max(maximum, sum);
	}
	cout << maximum;


	return 0;
}