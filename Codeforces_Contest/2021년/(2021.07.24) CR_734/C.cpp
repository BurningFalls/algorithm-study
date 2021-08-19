#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

typedef struct _NODE {
	int acnt = 0;
	int bcnt = 0;
	int ccnt = 0;
	int dcnt = 0;
	int ecnt = 0;
} NODE;

NODE node[200001];

bool cmp_a(NODE x, NODE y) {
	return x.acnt > y.acnt;
}

bool cmp_b(NODE x, NODE y) {
	return x.bcnt > y.bcnt;
}

bool cmp_c(NODE x, NODE y) {
	return x.ccnt > y.ccnt;
}

bool cmp_d(NODE x, NODE y) {
	return x.dcnt > y.dcnt;
}

bool cmp_e(NODE x, NODE y) {
	return x.ecnt > y.ecnt;
}

void Do(int idx, string s) {
	int slen = s.size();
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	FOR(i, 0, slen - 1) {
		if (s[i] == 'a')
			a++;
		else if (s[i] == 'b')
			b++;
		else if (s[i] == 'c')
			c++;
		else if (s[i] == 'd')
			d++;
		else if (s[i] == 'e')
			e++;
	}
	int t1 = 2 * a - slen;
	int t2 = 2 * b - slen;
	int t3 = 2 * c - slen;
	int t4 = 2 * d - slen;
	int t5 = 2 * e - slen;
	node[idx] = { t1, t2, t3, t4, t5 };
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		int maxi = 0;
		cin >> N;
		FOR(i, 1, N) {
			string s;
			cin >> s;
			Do(i, s);
		}
		int sum;
		int idx;

		sort(node + 1, node + N + 1, cmp_a);
		sum = 0;
		idx = N;
		FOR(i, 1, N) {
			sum += node[i].acnt;
			if (sum <= 0) {
				idx = i - 1;
				break;
			}
		}
		maxi = max(maxi, idx);

		sort(node + 1, node + N + 1, cmp_b);
		sum = 0;
		idx = N;
		FOR(i, 1, N) {
			sum += node[i].bcnt;
			if (sum <= 0) {
				idx = i - 1;
				break;
			}
		}
		maxi = max(maxi, idx);

		sort(node + 1, node + N + 1, cmp_c);
		sum = 0;
		idx = N;
		FOR(i, 1, N) {
			sum += node[i].ccnt;
			if (sum <= 0) {
				idx = i - 1;
				break;
			}
		}
		maxi = max(maxi, idx);

		sort(node + 1, node + N + 1, cmp_d);
		sum = 0;
		idx = N;
		FOR(i, 1, N) {
			sum += node[i].dcnt;
			if (sum <= 0) {
				idx = i - 1;
				break;
			}
		}
		maxi = max(maxi, idx);

		sort(node + 1, node + N + 1, cmp_e);
		sum = 0;
		idx = N;
		FOR(i, 1, N) {
			sum += node[i].ecnt;
			if (sum <= 0) {
				idx = i - 1;
				break;
			}
		}
		maxi = max(maxi, idx);
		
		cout << maxi << "\n";
	}

	return 0;
}