#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int A, B;
	string s;
	cin >> A >> B >> s;
	int len = s.size();
	int num = s[len - 1] - '0';
	if (num % 2 == 1) {
		cout << (A ^ B);
	}
	else if (num % 2 == 0) {
		cout << A;
	}

	return 0;
}