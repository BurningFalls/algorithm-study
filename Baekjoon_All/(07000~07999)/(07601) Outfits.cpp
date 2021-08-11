#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	bool arr1[51];
	bool arr2[51];
	int s_idx = 1;
	while (true) {
		int N, D;
		cin >> N >> D;
		FOR(i, 1, N) {
			arr1[i] = 1;
			arr2[i] = 1;
		}
		if (N == 0 && D == 0)
			break;
		int rm1, rm2;
		cin >> rm1 >> rm2;
		if (rm1 != 0)
			arr1[rm1] = 0;
		if (rm2 != 0)
			arr2[N + 1 - rm2] = 0;
		int cnt1, cnt2;
		cout << "Scenario " << s_idx << "\n";
		s_idx++;
		FOR(i, 1, D) {
			cin >> cnt1 >> cnt2;
			int left = 0, right = N + 1;
			while (cnt1) {
				left++;
				if (arr1[left])
					cnt1--;
			}
			while (cnt2) {
				right--;
				if (arr2[right])
					cnt2--;
			}
			cout << "Day " << i << " ";
			cout << ((left == right) ? "ALERT" : "OK") << "\n";
		}
		
	}


	return 0;
}