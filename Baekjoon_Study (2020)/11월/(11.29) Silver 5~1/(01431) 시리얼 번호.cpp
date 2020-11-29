#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string arr[1001];

bool cmp(string s1, string s2) {
	int len1 = s1.size(), len2 = s2.size();
	if (len1 == len2) {
		int sum1 = 0, sum2 = 0;
		FOR(i, 0, len1 - 1) {
			if (s1[i] >= '1' && s1[i] <= '9')
				sum1 += (s1[i] - '0');
		}
		FOR(i, 0, len2 - 1) {
			if (s2[i] >= '1' && s2[i] <= '9')
				sum2 += (s2[i] - '0');
		}
		if (sum1 == sum2)
			return s1 < s2;
		return sum1 < sum2;
	}
	return len1 < len2;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1, cmp);
	FOR(i, 1, N)
		cout << arr[i] << "\n";

	return 0;
}