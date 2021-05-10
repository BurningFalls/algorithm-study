#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	cin >> T;
	int idx = 1;
	while (T--) {
		int N;
		bool use[10] = { 0, };
		cin >> N;
		cout << "Case #" << idx << ": ";
		if (N == 0)
			cout << "INSOMNIA\n";
		else {
			int num = 0;
			while (true) {
				num += N;
				string tmp = to_string(num);
				int len = tmp.size();
				FOR(i, 0, len - 1) {
					use[tmp[i] - '0'] = 1;
				}
				bool flag = true;
				FOR(i, 0, 9) {
					if (!use[i])
						flag = false;
				}
				if (flag)
					break;
			}
			cout << num << "\n";
		}
		idx++;
	}


	return 0;
}