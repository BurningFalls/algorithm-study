#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 100000

int X[MAX + 1];
int tree[4 * MAX + 1];

int Check(int x) {
	if (x > 0)
		return 1;
	else if (x == 0)
		return 0;
	else if (x < 0)
		return -1;
}

int Init(int node, int start, int end) {
	if (start == end)
		return tree[node] = X[start];
	int mid = (start + end) / 2;
	int LQ = Init(node * 2, start, mid);
	int RQ = Init(node * 2 + 1, mid + 1, end);
	return tree[node] = LQ * RQ;
}

int Multi(int node, int start, int end, int left, int right) {
	if (end < left || right < start)
		return 1;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	int LQ = Multi(node * 2, start, mid, left, right);
	int RQ = Multi(node * 2 + 1, mid + 1, end, left, right);
	return LQ * RQ;
}

int Update(int node, int start, int end, int index, int ch) {
	if (index < start || end < index)
		return tree[node];
	if (start == end)
		return tree[node] = ch;
	int mid = (start + end) / 2;
	int LQ = Update(node * 2, start, mid, index, ch);
	int RQ = Update(node * 2 + 1, mid + 1, end, index, ch);
	return tree[node] = LQ * RQ;
}

int main() {
	FASTIO;
	int N, K;
	while (cin >> N >> K) {
		vector<char> ans_v;
		FOR(i, 1, N) {
			int num;
			cin >> num;
			X[i] = Check(num);
		}
		Init(1, 1, N);
		FOR(i, 1, K) {
			char order;
			cin >> order;
			if (order == 'C') {
				int I, V;
				cin >> I >> V;
				X[i] = Check(V);
				Update(1, 1, N, I, Check(V));
			}
			else if (order == 'P') {
				int I, J;
				cin >> I >> J;
				int t = Multi(1, 1, N, I, J);
				if (t == 1)
					ans_v.push_back('+');
				else if (t == 0)
					ans_v.push_back('0');
				else if (t == -1)
					ans_v.push_back('-');
			}
		}
		int len = ans_v.size();
		FOR(i, 0, len - 1)
			cout << ans_v[i];
		cout << "\n";
	}

	return 0;
}