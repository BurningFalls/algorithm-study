#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	cin >> N;
	while (N--) {
		ld A, B;
		cin >> A >> B;
		int flag1 = 0, flag2 = 0;
		if (A < 0) {
			flag1 = -1;
			A *= (-1);
		}
		else if (A > 0)
			flag1 = 1;
		if (B < 0) {
			flag2 = -1;
			B *= (-1);
		}
		else if (B > 0)
			flag2 = 1;
		A += pow(10, -10);
		B += pow(10, -10);
		ull a = A * pow(10, 9);
		ull b = B * pow(10, 9);
		ull c = a * b;
		vector<int> v;
		while (c) {
			v.push_back(c % 10);
			c /= 10;
		}
		int len = v.size();
		FOR(i, 0, 18 - len)
			v.push_back(0);
		len = v.size();
		if ((flag1 == -1 && flag2 == 1) || (flag1 == 1 && flag2 == -1))
			cout << '-';
		if (len == 18)
			cout << 0;
		else {
			ROF(i, len - 1, 18) {
				cout << v[i];
			}
		}
		cout << '.';
		ROF(i, 17, 0)
			cout << v[i];
		cout << "\n";
	}


	return 0;
}