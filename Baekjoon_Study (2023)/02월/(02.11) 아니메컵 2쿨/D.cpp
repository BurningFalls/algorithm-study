#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int N, M, F;
	cin >> N >> M >> F;
	vector<vector<char>> v(N, vector<char>(M));
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> v[i][j];
		}
	}
	
	int ans = 0;

	FOR(i, 0, N - 2) {
		int sum = 0;
		vector<int> tmp(M, 0);
		FOR(j, 0, M - 1) {
			if ((v[i][j] == '.' && v[i + 1][j] == '#') ||
				(v[i][j] == '#' && v[i + 1][j] == '.')) {
				tmp[j] = 2;
			}
			else if (v[i][j] == '.' && v[i + 1][j] == '.') {
				tmp[j] = 1;
			}
		}

		int left = 0, right = M - 1;
		int real = 0;
		while (left < M) {
			if (tmp[left] == 0) break;
			real += (tmp[left] == 2);
			left++;
		}
		sum += min(real, F);
		if (left < M) {
			real = 0;
			while (right >= 0) {
				if (tmp[right] == 0) break;
				real += (tmp[right] == 2);
				right--;
			}
			sum += min(real, F);
		}

		FOR(j, left + 1, right - 1) {
			sum += (tmp[j] == 2);
		}
		ans += sum;
	}

	FOR(j, 0, M - 2) {
		int sum = 0;
		vector<int> tmp(N, 0);
		FOR(i, 0, N - 1) {
			if ((v[i][j] == '.' && v[i][j + 1] == '#') ||
				(v[i][j] == '#' && v[i][j + 1] == '.')) {
				tmp[i] = 2;
			}
			else if (v[i][j] == '.' && v[i][j + 1] == '.') {
				tmp[i] = 1;
			}
		}

		int left = 0, right = N - 1;
		int real = 0;
		while (left < N) {
			if (tmp[left] == 0) break;
			real += (tmp[left] == 2);
			left++;
		}
		sum += min(real, F);
		if (left < N) {
			real = 0;
			while (right >= 0) {
				if (tmp[right] == 0) break;
				real += (tmp[right] == 2);
				right--;
			}
			sum += min(real, F);
		}

		FOR(j, left + 1, right - 1) {
			sum += (tmp[j] == 2);
		}
		ans += sum;
	}
	cout << ans;

	return 0;
}