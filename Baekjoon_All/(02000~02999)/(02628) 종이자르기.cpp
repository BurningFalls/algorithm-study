#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int width, height;
	cin >> width >> height;
	int N;
	cin >> N;
	vector<int> v1, v2;
	FOR(i, 1, N) {
		int a, b;
		cin >> a >> b;
		if (a == 0)
			v1.push_back(b);
		else if (a == 1)
			v2.push_back(b);
	}
	v1.push_back(0);
	v1.push_back(height);
	v2.push_back(0);
	v2.push_back(width);
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int len1 = v1.size();
	int len2 = v2.size();
	int max1 = 0, max2 = 0;
	FOR(i, 0, len1 - 2) {
		max1 = max(max1, v1[i + 1] - v1[i]);
	}
	FOR(i, 0, len2 - 2) {
		max2 = max(max2, v2[i + 1] - v2[i]);
	}
	cout << max1 * max2;

	return 0;
}