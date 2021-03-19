#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool Check(string s1, string s2) {
	int len1 = s1.size();
	int len2 = s2.size();
	if (len1 != len2)
		return false;
	int arr1[26] = { 0, };
	int arr2[26] = { 0, };
	FOR(i, 0, len1 - 1) {
		arr1[s1[i] - 'a']++;
		arr2[s2[i] - 'a']++;
	}
	FOR(i, 0, 25) {
		if (arr1[i] != arr2[i])
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		string s1, s2;
		cin >> s1 >> s2;
		if (Check(s1, s2))
			cout << "Possible";
		else
			cout << "Impossible";
		cout << "\n";
	}


	return 0;
}