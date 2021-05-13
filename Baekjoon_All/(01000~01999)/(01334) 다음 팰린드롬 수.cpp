#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string Next_Number(string s) {
	int len = s.size();
	reverse(s.begin(), s.end());
	bool flag = false;
	FOR(i, 0, len - 1) {
		int tmp = (s[i] - '0') + flag;
		if (i == 0)
			tmp += 1;
		if (tmp >= 10) {
			s[i] = '0';
			flag = 1;
		}
		else {
			s[i] = tmp + '0';
			flag = 0;
		}
	}
	if (flag)
		s += '1';
	reverse(s.begin(), s.end());
	return s;
}

int main() {
	FASTIO;
	string s;
	cin >> s;
	int len = s.size();
	if (len % 2 == 1) {
		string front = s.substr(0, len / 2 + 1);
		string s1 = front, s2 = "";
		string re_front = front;
		re_front.pop_back();
		reverse(re_front.begin(), re_front.end());
		s1 += re_front;
		front = Next_Number(front);
		int ch_front_size = front.size();
		if (ch_front_size == len / 2 + 2) {
			front.pop_back();
			re_front = front;
			s2 = front;
			reverse(re_front.begin(), re_front.end());
			s2 += re_front;
		}
		else {
			re_front = front;
			re_front.pop_back();
			s2 = front;
			reverse(re_front.begin(), re_front.end());
			s2 += re_front;
		}
		if (s < s1)
			cout << s1;
		else
			cout << s2;
	}
	else if (len % 2 == 0) {
		string front = s.substr(0, len / 2);
		string s1 = front, s2 = "";
		string re_front = front;
		reverse(re_front.begin(), re_front.end());
		s1 += re_front;
		front = Next_Number(front);
		int ch_front_size = front.size();
		if (ch_front_size == len / 2 + 1) {
			s2 = front;
			front.pop_back();
			re_front = front;
			reverse(re_front.begin(), re_front.end());
			s2 += re_front;
		}
		else {
			re_front = front;
			s2 = front;
			reverse(re_front.begin(), re_front.end());
			s2 += re_front;
		}
		if (s < s1)
			cout << s1;
		else
			cout << s2;
	}


	return 0;
}