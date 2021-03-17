#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		string A, B;
		cin >> A >> B;
		int lenA = A.size();
		int lenB = B.size();
		int sumA = 0, sumB = 0;
		vector<int> v1, v2;
		FOR(i, 0, lenA - 1) {
			if (A[i] == 'a') {
				sumA++;
				v1.push_back(i);
			}
		}
		FOR(i, 0, lenB - 1) {
			if (B[i] == 'a') {
				sumB++;
				v2.push_back(i);
			}
		}
		if ((lenA != lenB) || (sumA != sumB)) {
			cout << "-1\n";
			continue;
		}
		int sum = 0;
		FOR(i, 0, sumA - 1) {
			sum += abs(v1[i] - v2[i]);
		}
		cout << sum << "\n";
	}

	return 0;
}