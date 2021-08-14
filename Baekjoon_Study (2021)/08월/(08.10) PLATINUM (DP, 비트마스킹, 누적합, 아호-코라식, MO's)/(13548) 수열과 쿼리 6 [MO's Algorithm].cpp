#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

typedef struct _NODE {
	int left;
	int right;
	int idx;
} NODE;

int sqrtN;
int N, M;
int A[100001];
int cnt[100001];
int cnt_cnt[100001];
int ANS[100001];
vector<NODE> v;
int max_count = 0;

bool cmp(NODE a, NODE b) {
	if (a.left / sqrtN == b.left / sqrtN)
		return a.right < b.right;
	return a.left / sqrtN < b.left / sqrtN;
}

void Add(int x) {
	if (cnt[x] != 0)
		cnt_cnt[cnt[x]]--;
	cnt[x]++;
	cnt_cnt[cnt[x]]++;
	max_count = max(max_count, cnt[x]);
}

void Sub(int x) {
	cnt_cnt[cnt[x]]--;
	if (cnt[x] == max_count && cnt_cnt[cnt[x]] == 0)
		max_count--;
	cnt[x]--;
	cnt_cnt[cnt[x]]++;
}

int main() {
	cin >> N;
	sqrtN = (int)sqrt(N);
	FOR(i, 0, N - 1)
		cin >> A[i];
	int M;
	cin >> M;
	FOR(i, 0, M - 1) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a - 1, b - 1, i });
	}
	sort(v.begin(), v.end(), cmp);
	int start = v[0].left;
	int end = v[0].right;
	FOR(i, start, end) {
		Add(A[i]);
	}
	ANS[v[0].idx] = max_count;

	FOR(i, 1, M - 1) {
		while (v[i].left < start)
			Add(A[--start]);
		while (v[i].right > end)
			Add(A[++end]);
		while (v[i].left > start)
			Sub(A[start++]);
		while (v[i].right < end)
			Sub(A[end--]);
		ANS[v[i].idx] = max_count;
	}
	FOR(i, 0, M - 1)
		cout << ANS[i] << "\n";


	return 0;
}