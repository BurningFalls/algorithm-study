#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

vector<int> is_prime(4000010, 1);

void Find_Prime(int N) {
	is_prime[1] = 0;
	FOR(i, 2, N) {
		if (!is_prime[i]) continue;
		for (int j = i * 2; j <= N; j += i)
			is_prime[j] = 0;
	}
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	Find_Prime(N);
	int left = 2, right = 2;
	int sum = 2;
	int cnt = 0;
	while (left <= right && right <= N) {
		if (sum == N) {
			cnt++;
			sum -= left;
			left++;
			while (left <= 4000000 && !is_prime[left])
				left++;
		}
		else if (sum > N) {
			sum -= left;
			left++;
			while (left <= 4000000 && !is_prime[left])
				left++;
		}
		else if (sum < N) {
			right++;
			while (right <= 4000000 && !is_prime[right])
				right++;
			sum += right;
		}
	}
	P1(cnt);

	return 0;
}