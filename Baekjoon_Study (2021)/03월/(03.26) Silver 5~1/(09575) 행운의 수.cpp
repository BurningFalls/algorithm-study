#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int A[51], B[51], C[51];
vector<int> v1, v2, v3;
set<int> se;

bool is_Lucky(int x) {
	string s = to_string(x);
	int len = s.size();
	FOR(i, 0, len - 1) {
		if (s[i] != '5' && s[i] != '8')
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		v1.clear();
		v2.clear();
		v3.clear();
		se.clear();
		int N, M, K;
		cin >> N;
		FOR(i, 1, N)
			cin >> A[i];
		cin >> M;
		FOR(i, 1, M)
			cin >> B[i];
		cin >> K;
		FOR(i, 1, K)
			cin >> C[i];
		sort(A + 1, A + N + 1);
		sort(B + 1, B + M + 1);
		sort(C + 1, C + K + 1);
		v1.push_back(A[1]);
		v2.push_back(B[1]);
		v3.push_back(C[1]);
		FOR(i, 2, N) {
			if (v1.back() != A[i])
				v1.push_back(A[i]);
		}
		FOR(i, 2, M) {
			if (v2.back() != B[i])
				v2.push_back(B[i]);
		}
		FOR(i, 2, K) {
			if (v3.back() != C[i])
				v3.push_back(C[i]);
		}
		int len1 = v1.size();
		int len2 = v2.size();
		int len3 = v3.size();
		FOR(i, 0, len1 - 1) {
			FOR(j, 0, len2 - 1) {
				FOR(k, 0, len3 - 1) {
					int sum = v1[i] + v2[j] + v3[k];
					if (is_Lucky(sum))
						se.insert(sum);
				}
			}
		}
		int ans = se.size();
		cout << ans << "\n";
	}


	return 0;
}