#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int V[50001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	int maximum = 0;
	int sum = 0;
	FOR(i, 1, N) {
		cin >> V[i];
		maximum = max(maximum, V[i]);
		sum += V[i];
	}
	cout << sum - maximum;


	return 0;
}