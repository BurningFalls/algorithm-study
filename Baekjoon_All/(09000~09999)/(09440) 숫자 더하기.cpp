#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int arr[15];
	while (true) {
		int N;
		cin >> N;
		if (N == 0)
			break;
		FOR(i, 1, N)
			cin >> arr[i];
		sort(arr + 1, arr + N + 1, greater<int>());
		vector<int> v1, v2;
		int cnt = 0;
		FOR(i, 1, N) {
			if (arr[i] == 0) {
				cnt++;
				continue;
			}
			if (i % 2 == 1)
				v1.push_back(arr[i]);
			else if (i % 2 == 0)
				v2.push_back(arr[i]);
		}
		int a = v1.back();
		v1.pop_back();
		int b = v2.back();
		v2.pop_back();
		int len1 = v1.size();
		int len2 = v2.size();
		if (len1 > len2) {
			FOR(i, 1, cnt) {
				if (i % 2 == 1)
					v2.push_back(0);
				else if (i % 2 == 0)
					v1.push_back(0);
			}
		}
		else if (len1 <= len2) {
			FOR(i, 1, cnt) {
				if (i % 2 == 1)
					v1.push_back(0);
				else if (i % 2 == 0)
					v2.push_back(0);
			}
		}
		len1 = v1.size();
		len2 = v2.size();
		if (len1 <= len2) {
			v1.push_back(max(a, b));
			v2.push_back(min(a, b));
		}
		else if (len1 > len2) {
			v2.push_back(max(a, b));
			v1.push_back(min(a, b));
		}
		len1 = v1.size();
		len2 = v2.size();
		int tmp1 = 0, tmp2 = 0;
		FOR(i, 0, len1 - 1)
			tmp1 += v1[i] * pow(10, i);
		FOR(i, 0, len2 - 1)
			tmp2 += v2[i] * pow(10, i);

		cout << tmp1 + tmp2 << "\n";
	}


	return 0;
}