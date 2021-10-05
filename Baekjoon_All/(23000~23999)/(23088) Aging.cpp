#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

struct Process {
	int t;
	int p;
	int b;
	int idx;
};

struct compare {
	bool operator()(Process& A, Process& B) {
		if (A.p == B.p) {
			if (A.b == B.b) {
				return A.idx > B.idx;
			}
			return A.b > B.b;
		}
		return A.p < B.p;
	}
};

queue<Process> q;
vector<int> ans_v;
priority_queue<Process, vector<Process>, compare> pq;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int t, p, b;
		cin >> t >> p >> b;
		q.push({ t, p, b, i });
	}
	int time = 0;
	int end_time = 0;
	while (!(pq.empty() && q.empty())) {
		while (!q.empty() && q.front().t == time) {
			q.front().p -= time;
			pq.push(q.front());
			q.pop();
		}
		if (pq.empty() || time < end_time) {
			time++;
			continue;
		}
		Process P = pq.top();
		pq.pop();
		ans_v.push_back(P.idx);
		end_time = time + P.b;
		time++;
	}
	for (int x : ans_v)
		cout << x << " ";


	return 0;
}