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

int main() {
	FASTIO;
	int N;
	cin >> N;
	cout << "int a;\n";
	cout << "int *ptr = &a;\n";
	FOR(i, 2, N) {
		cout << "int ";
		FOR(j, 1, i) {
			cout << '*';
		}
		cout << "ptr" << i;
		cout << " = " << "&ptr";
		if (i != 2) {
			cout << i - 1;
		}
		cout << ";\n";
	}

	return 0;
}