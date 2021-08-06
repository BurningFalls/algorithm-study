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
int N;
int A[100001];
int table[1000001] = { 0, };
vector<NODE> v;
int ANS[100001];

bool cmp(NODE a, NODE b) {
	if (a.left / sqrtN == b.left / sqrtN)
		return a.right / sqrtN < b.right / sqrtN;
	return a.left < b.left;
}

int main() {
	FASTIO;
	cin >> N;
	sqrtN = (int)sqrt(N);
	FOR(i, 1, N)
		cin >> A[i];
	int M;
	cin >> M;
	FOR(i, 0, M - 1) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b, i });
	}
	sort(v.begin(), v.end(), cmp);

	int ans = 0;
	int start = v[0].left;
	int end = v[0].right;
	FOR(i, start, end) {
		if (table[A[i]] == 0)
			ans++;
		table[A[i]]++;
	}
	ANS[v[0].idx] = ans;

	FOR(i, 1, M - 1) {
		while (v[i].left < start) {
			if (table[A[--start]] == 0)
				ans++;
			table[A[start]]++;
		}
		while (v[i].right > end) {
			if (table[A[++end]] == 0)
				ans++;
			table[A[end]]++;
		}
		while (v[i].left > start) {
			table[A[start]]--;
			if (table[A[start++]] == 0)
				ans--;
		}
		while (v[i].right < end) {
			table[A[end]]--;
			if (table[A[end--]] == 0)
				ans--;
		}
		ANS[v[i].idx] = ans;
	}

	FOR(i, 0, M - 1)
		cout << ANS[i] << "\n";

	return 0;
}