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

struct NODE {
	int s;
	int e;
	int k;
};

bool compare(NODE n1, NODE n2) {
	return n1.s < n2.s;
}

int Change(string s) {
	int hour = (s[0] - '0') * 10 + (s[1] - '0');
	int minute = (s[3] - '0') * 10 + (s[4] - '0');
	return 60 * hour + minute;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int T;
		cin >> T;
		int NA, NB;
		cin >> NA >> NB;
		string A, B;
		vector<NODE> v;
		FOR(j, 1, NA) {
			cin >> A >> B;
			int start = Change(A);
			int end = Change(B);
			v.push_back({ start, end, 0 });
		}
		FOR(j, 1, NB) {
			cin >> A >> B;
			int start = Change(A);
			int end = Change(B);
			v.push_back({ start, end, 1 });
		}
		sort(ALL(v), compare);

		int left = 0, right = 0;
		PQ<int, vector<int>, greater<int>> Lpq, Rpq;
		FOR(i, 0, LEN(v) - 1) {
			if (v[i].k == 0) {
				if (Lpq.empty() || Lpq.top() > v[i].s) {
					left++;
				}
				else {
					Lpq.pop();
				}
				Rpq.push(v[i].e + T);
			}
			else if (v[i].k == 1) {
				if (Rpq.empty() || Rpq.top() > v[i].s) {
					right++;
				}
				else {
					Rpq.pop();
				}
				Lpq.push(v[i].e + T);
			}
		}
		cout << "Case #" << i << ": ";
		cout << left << " " << right << "\n";
	}

	return 0;
}