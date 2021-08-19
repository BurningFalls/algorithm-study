#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

typedef struct _NODE {
	int num;
	int idx;
	int value;
} NODE;

NODE node[200001];
int cnt[200001];

bool cmp(NODE a, NODE b) {
	return a.num < b.num;
}

bool cmp2(NODE a, NODE b) {
	return a.idx < b.idx;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		memset(cnt, 0, sizeof(cnt));
		int N, K;
		cin >> N >> K;
		FOR(i, 1, N) {
			int x;
			cin >> x;
			cnt[x]++;
			node[i] = { x, i, -1 };
		}
		int notk_cnt = 0;
		FOR(i, 1, N) {
			if (cnt[i] < K)
				notk_cnt += cnt[i];
		}
		int pos_cycle = notk_cnt / K;
		sort(node + 1, node + N + 1, cmp);
		int prev = -1;
		int counter = 0;
		int counter2 = 1;
		int cycle = 0;
		FOR(i, 1, N) {
			if (cnt[node[i].num] >= K) {
				if (prev != node[i].num) {
					counter = K;
					node[i].value = counter;
				}
				else if (prev == node[i].num) {
					counter = max(0, counter - 1);
					node[i].value = counter;
				}
			}
			else {
				if (counter2 == 1) {
					cycle++;
					if (cycle > pos_cycle) {
						counter2 = 0;
					}
				}
				node[i].value = counter2;
				counter2 = counter2 % K + 1;
			}
			prev = node[i].num;
		}
		sort(node + 1, node + N + 1, cmp2);
		FOR(i, 1, N) {
			cout << node[i].value << " ";
		}
		cout << "\n";
	}


	return 0;
}