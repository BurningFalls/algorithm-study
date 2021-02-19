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
		vector<int> ans_v;
		priority_queue<int> pq1, pq2;
		int M;
		int num;
		int len1 = 0, len2 = 0;
		cin >> M;
		FOR(i, 1, M) {
			cin >> num;
			if (i == 1) {
				pq1.push(num);
				ans_v.push_back(num);
				len1++;
				continue;
			}
			if (pq1.top() < num) {
				pq2.push(-num);
				len2++;
			}
			else if (pq1.top() >= num) {
				pq1.push(num);
				len1++;
			}
			if (i % 2 == 1) {
				if (len1 == len2 + 3) {
					pq2.push(-pq1.top());
					pq1.pop();
					len1--;
					len2++;
				}
				else if (len1 + 1 == len2) {
					pq1.push(-pq2.top());
					pq2.pop();
					len1++;
					len2--;
				}
				ans_v.push_back(pq1.top());
			}
		}
		int len = ans_v.size();
		cout << len << "\n";
		FOR(i, 0, len - 1) {
			if (i != 0 && i % 10 == 0)
				cout << "\n";
			cout << ans_v[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}