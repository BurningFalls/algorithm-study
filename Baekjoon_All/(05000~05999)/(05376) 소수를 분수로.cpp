#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

ll GCD(ll a, ll b) {
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		char t1, t2;
		cin >> t1 >> t2;
		string s;
		cin >> s;
		int slen = s.size();
		string front = "", back = "";
		int idx = 0;
		if (s[0] != '(') {
			bool flag = false;
			FOR(i, 0, slen - 1) {
				if (s[i] == '(') {
					idx = i;
					flag = true;
					break;
				}
				front += s[i];
			}
			if (!flag)
				idx = slen;
		}
		FOR(i, idx + 1, slen - 1) {
			if (s[i] == ')')
				break;
			back += s[i];
		}
		ll up = 1, down = 1;
		if (front == "") {
			up = stol(back);
			string tmp = "";
			int back_len = back.size();
			FOR(i, 1, back_len)
				tmp += '9';
			down = stol(tmp);
		}
		else if (back == "") {
			up = stol(front);
			int front_len = front.size();
			down = pow(10, front_len);
		}
		else {
			string tmp = "";
			int front_len = front.size();
			int back_len = back.size();
			FOR(i, 1, back_len)
				tmp += '9';
			FOR(i, 1, front_len)
				tmp += '0';
			down = stol(tmp);
			string num1 = "", num2 = "";
			num1 = front + back;
			num2 = front;
			up = stol(num1) - stol(num2);
		}
		ll gcd = GCD(up, down);
		cout << up / gcd << "/" << down / gcd << "\n";
	}


	return 0;
}