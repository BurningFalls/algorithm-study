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
#define MAX 5000

struct NODE {
	int st_num;
	int ed_num;
	int max_pos;
};

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<int> v(N + 1);
	FOR(i, 1, N) {
		cin >> v[i];
	}
	vector<NODE> tmp;
	FOR(i, 1, N) {
		tmp.push_back({ v[i], v[i], i });
		while (LEN(tmp) >= 2) {
			NODE n1 = tmp.back();
			tmp.pop_back();
			NODE n2 = tmp.back();
			tmp.pop_back();
			if (n1.ed_num + 1 == n2.st_num) {
				tmp.push_back({ n1.st_num, n2.ed_num, max(n1.max_pos, n2.max_pos) });
				cout << min(n1.max_pos, n2.max_pos) << "\n";
			}
			else if (n2.ed_num + 1 == n1.st_num) {
				tmp.push_back({ n2.st_num, n1.ed_num, max(n1.max_pos, n2.max_pos) });
				cout << min(n1.max_pos, n2.max_pos) << "\n";
			}
			else {
				tmp.push_back(n2);
				tmp.push_back(n1);
				break;
			}
		}
	}

	return 0;
}