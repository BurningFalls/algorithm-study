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

int N;
vector<int> A(1 << 17);
vector<int> v;
int idx = 0;

void Travel1(int node) {
	if (node > N) return;
	Travel1(node * 2);
	A[node] = v[idx];
	idx++;
	Travel1(node * 2 + 1);
}

void Travel2(int node) {
	if (node > N) return;
	Travel2(node * 2);
	Travel2(node * 2 + 1);
	cout << A[node] << " ";
}

int main() {
	FASTIO;
	int X;
	cin >> N;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		if (num != -1) {
			v.push_back(num);
		}
	}
	cin >> X;
	v.push_back(X);

	sort(ALL(v));

	Travel1(1);
	Travel2(1);

	return 0;
}