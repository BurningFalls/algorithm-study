#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool cmp(int a, int b) {
	if (a % 2 == 1 && b % 2 == 1)
		return a > b;
	else if (a % 2 == 1 && b % 2 == 0)
		return a % 2 > b % 2;
	else if (a % 2 == 0 && b % 2 == 1)
		return a % 2 > b % 2;
	else if (a % 2 == 0 && b % 2 == 0)
		return a > b;
}

int main() {
	FASTIO;
	vector<int> v;
	int A, B, C;
	cin >> A >> B >> C;
	v.push_back(A);
	v.push_back(B);
	v.push_back(C);
	v.push_back(A * C);
	v.push_back(A * B);
	v.push_back(B * C);
	v.push_back(A * B * C);
	sort(v.begin(), v.end(), cmp);
	cout << v[0];

	return 0;
}