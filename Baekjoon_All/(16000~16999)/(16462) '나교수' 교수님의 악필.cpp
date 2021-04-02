#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	cin >> N;
	double sum = 0;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		string s = to_string(num);
		int len = s.size();
		FOR(j, 0, len - 1) {
			if (s[j] == '0' || s[j] == '6')
				s[j] = 9 + '0';
		}
		int tmp = stoi(s);
		if (tmp > 100)
			tmp = 100;
		sum += tmp;
	}
	sum /= N;
	cout << round(sum);

	return 0;
}