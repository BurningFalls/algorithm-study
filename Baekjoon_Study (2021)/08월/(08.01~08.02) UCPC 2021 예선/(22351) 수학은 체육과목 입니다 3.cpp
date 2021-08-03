#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	string S;
	cin >> S;
	int len = S.size();
	if (len == 1)
		cout << S << " " << S;
	else if (len == 2) {
		if (S[0] + 1 == S[1])
			cout << S[0] << " " << S[1];
		else
			cout << S << " " << S;
	}
	else {
		string arr[6];
		arr[0] = S.substr(0, 1);
		arr[1] = S.substr(0, 2);
		arr[2] = S.substr(0, 3);
		arr[3] = S.substr(len - 1, 1);
		arr[4] = S.substr(len - 2, 2);
		arr[5] = S.substr(len - 3, 3);
		int A, B;
		bool flag = false;
		FOR(i, 0, 2) {
			FOR(j, 3, 5) {
				A = stoi(arr[i]);
				B = stoi(arr[j]);
				string tmp = "";
				FOR(k, A, B) {
					string t = to_string(k);
					tmp += t;
				}
				if (S == tmp) {
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		cout << A << " " << B;
	}

	return 0;
}