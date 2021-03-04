#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

char OS[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
int OS_num[7] = { 1, 5, 10, 50, 100, 500, 1000 };
string TS[6] = { "IV", "IX", "XL", "XC", "CD", "CM" };
int TS_num[6] = { 4, 9, 40, 90, 400, 900 };

int Func1(string s) {
	int len = s.size();
	int sum = 0;
	FOR(i, 0, len - 1) {
		if (i != len - 1) {
			string sub = "";
			sub += s[i];
			sub += s[i + 1];
			bool flag = false;
			int pos = 0;
			FOR(j, 0, 6) {
				if (sub == TS[j]) {
					flag = true;
					pos = j;
				}
			}
			if (flag) {
				sum += TS_num[pos];
				i++;
			}
			else if (!flag) {
				FOR(j, 0, 7) {
					if (s[i] == OS[j]) {
						sum += OS_num[j];
					}
				}
			}
		}
		else {
			FOR(j, 0, 7) {
				if (s[i] == OS[j]) {
					sum += OS_num[j];
				}
			}
		}
	}
	return sum;
}

string Func2(int num) {
	string ans = "";
	string s = to_string(num);
	int len = s.size();
	FOR(i, 0, len - 1) {
		int tmp = (s[i] - '0') * pow(10, len - 1 - i);
		bool flag = false;
		int pos = 0;
		FOR(j, 0, 6) {
			if (tmp == TS_num[j]) {
				flag = true;
				pos = j;
			}
		}
		if (flag) {
			ans += TS[pos];
		}
		else if (!flag) {
			while (tmp != 0) {
				ROF(j, 6, 0) {
					if (tmp >= OS_num[j]) {
						ans += OS[j];
						tmp -= OS_num[j];
						break;
					}
				}
			}
		}
	}
	return ans;
}

int main() {
	FASTIO;
	string s1, s2;
	cin >> s1 >> s2;
	int tmp = Func1(s1) + Func1(s2);
	cout << tmp << "\n";
	cout << Func2(tmp);

	return 0;
}