#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<int> A;

int main() {
	FASTIO;
	int NA, NB;
	int num;
	cin >> NA >> NB;
	FOR(i, 1, NA) {
		cin >> num;
		A.push_back(num);
	}
	int cnt = 0;
	sort(A.begin(), A.end());
	FOR(i, 1, NB) {
		cin >> num;
		bool flag = binary_search(A.begin(), A.end(), num);
		if (flag)
			cnt++;
	}
	cout << NA + NB - cnt * 2;

	return 0;
}