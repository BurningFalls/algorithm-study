#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

double num[26];

int main() {
	FASTIO;
	int N;
	string s;
	cin >> N;
	cin >> s;
	FOR(i, 0, N - 1)
		cin >> num[i];
	vector<double> v;
	int len = s.size();
	FOR(i, 0, len - 1) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			v.push_back(num[s[i] - 'A']);
		else {
			double temp;
			double y = v.back();
			v.pop_back();
			double x = v.back();
			v.pop_back();
			if (s[i] == '+')
				temp = (x + y);
			else if (s[i] == '-')
				temp = (x - y);
			else if (s[i] == '*')
				temp = (x * y);
			else if (s[i] == '/')
				temp = (x / y);
			v.push_back(temp);
		}
	}
	cout << fixed << setprecision(2);
	cout << v.back();

	return 0;
}