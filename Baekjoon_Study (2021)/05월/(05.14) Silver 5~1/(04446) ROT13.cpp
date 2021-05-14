#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr1[6] = { 'a', 'i', 'y', 'e', 'o', 'u' };
int arr2[20] = { 'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g', 'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm' ,'f' };

int main() {
	FASTIO;
	string s;
	while (getline(cin, s)) {
		int len = s.size();
		FOR(i, 0, len - 1) {
			char x;
			if (s[i] >= 'A' && s[i] <= 'Z')
				x = s[i] - 'A' + 'a';
			else if (s[i] >= 'a' && s[i] <= 'z')
				x = s[i];
			else {
				cout << s[i];
				continue;
			}
			int idx1 = -1, idx2 = -1;
			FOR(j, 0, 5)
				if (arr1[j] == x)
					idx1 = j;
			FOR(j, 0, 20)
				if (arr2[j] == x)
					idx2 = j;
			char ans = '.';
			if (idx1 != -1) {
				idx1 = (idx1 + 3) % 6;
				ans = arr1[idx1];
			}
			else if (idx2 != -1) {
				idx2 = (idx2 + 10) % 20;
				ans = arr2[idx2];
			}
			if (s[i] >= 'A' && s[i] <= 'Z')
				ans = ans - 'a' + 'A';
			cout << ans;
		}
		cout << "\n";
	}



	return 0;
}