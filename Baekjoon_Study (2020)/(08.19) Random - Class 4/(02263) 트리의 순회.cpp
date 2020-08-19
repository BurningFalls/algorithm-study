#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N;
int idx[100001];
int InOrder[100001];
int PostOrder[100001];

void PreOrder(int IO_s, int IO_e, int PO_s, int PO_e) {
	if (IO_s > IO_e || PO_s > PO_e)
		return;
	int root = PostOrder[PO_e];
	cout << root << " ";
	PreOrder(IO_s, idx[root] - 1, PO_s, PO_s + idx[root] - IO_s - 1);
	PreOrder(idx[root] + 1, IO_e, PO_s + idx[root] - IO_s, PO_e - 1);
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N)
		cin >> InOrder[i];
	FOR(i, 1, N)
		cin >> PostOrder[i];
	FOR(i, 1, N)
		idx[InOrder[i]] = i;
	PreOrder(1, N, 1, N);

	return 0;
}