#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int main() {
	FASTIO;
	int N;
	cin >> N;
	int num1, num2;
	cout << '?' << " " << 1 << endl;
	cin >> num1;
	cout << '?' << " " << N << endl;
	cin >> num2;
	if ((num1 ^ num2) == 0) {
		cout << '!' << " " << 0 << endl;
	}
	else if (num1 == 0 && num2 == 1) {
		cout << '!' << " " << 1 << endl;
	}
	else if (num1 == 1 && num2 == 0) {
		cout << '!' << " " << -1 << endl;
	}


	return 0;
}