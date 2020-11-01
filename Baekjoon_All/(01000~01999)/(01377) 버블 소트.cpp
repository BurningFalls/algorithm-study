#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 500000 + 1

int N;
vector<pii> A;

int main() {
	FASTIO;
	int maximum = 0;
	cin >> N;
	FOR(i, 0, N - 1) {
		int num;
		cin >> num;
		A.push_back({ num, i });
	}
	sort(A.begin(), A.end());
	FOR(i, 0, N - 1) {
		maximum = max(maximum, A[i].second - i);
	}
	cout << maximum + 1;


	return 0;
}