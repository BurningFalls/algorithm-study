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
	int left;
	int right;

	bool operator==(NODE a) {
		return ((left == a.left) && (right == a.right));
	}
};

int N, S;
vector<int> X, H;
int Left, Right;

void BFS() {
	queue<NODE> q;
	q.push({ X[S] - H[S], X[S] + H[S]});
	Left = S, Right = S;
	while (!q.empty()) {
		NODE node = q.front();
		q.pop();
		int lidx = lower_bound(ALL(X), node.left) - X.begin();
		int ridx = upper_bound(ALL(X), node.right) - X.begin() - 1;
		NODE next = node;
		if (lidx < Left) {
			FOR(i, lidx, Left - 1) {
				next.left = min(next.left, X[i] - H[i]);
				next.right = max(next.right, X[i] + H[i]);
			}
			Left = lidx;
		}
		if (Right < ridx) {
			FOR(i, Right + 1, ridx) {
				next.left = min(next.left, X[i] - H[i]);
				next.right = max(next.right, X[i] + H[i]);
			}
			Right = ridx;
		}
		if (!(node == next)) {
			q.push(next);
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> S;
	S -= 1;
	X = vector<int>(N);
	H = vector<int>(N);
	FOR(i, 0, N - 1) {
		cin >> X[i];
	}
	FOR(i, 0, N - 1) {
		cin >> H[i];
	}

	BFS();

	FOR(i, Left + 1, Right + 1) {
		cout << i << " ";
	}

	return 0;
}