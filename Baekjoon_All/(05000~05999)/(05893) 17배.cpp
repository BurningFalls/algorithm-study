#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	string s;
	string s1 = "0000";
	string s2;
	string s3 = "";
	int flag = 0;
	int len1, len2;
	cin >> s;
	s1 += s;
	s2 = s + "0000";
	len1 = s1.size();
	len2 = s2.size();
	FOR(i, 1, len2) {
		int temp = (s1[len1 - i] - '0') + (s2[len2 - i] - '0') + flag;
		if (temp == 0) {
			s3 += '0';
			flag = 0;
		}
		else if (temp == 1) {
			s3 += '1';
			flag = 0;
		}
		else if (temp == 2) {
			s3 += '0';
			flag = 1;
		}
		else if (temp == 3) {
			s3 += '1';
			flag = 1;
		}
	}
	if (flag == 1)
		s3 += '1';
	int len3 = s3.size();
	ROF(i, len3 - 1, 0) {
		cout << s3[i];
	}

	return 0;
}