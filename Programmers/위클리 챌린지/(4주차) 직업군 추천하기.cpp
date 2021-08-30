#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

map<pair<string, string>, int> mp;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
	string answer = "";
	stringstream stream;
	FOR(i, 0, table.size() - 1) {
		string s;
		int cnt = 0;
		stream.clear();
		stream.str(table[i]);
		string occupation;
		while (stream >> s) {
			cnt++;
			if (cnt == 1)
				occupation = s;
			else
				mp[{occupation, s}] = 7 - cnt;
		}
	}
	string arr[5] = { "SI", "CONTENTS", "HARDWARE", "PORTAL", "GAME" };
	int maxi = 0;
	FOR(i, 0, 4) {
		int sum = 0;
		FOR(j, 0, languages.size() - 1) {
			if (!mp.count({arr[i], languages[j]})) continue;
			sum += mp[{arr[i], languages[j]}] * preference[j];
		}
		if (maxi < sum) {
			maxi = sum;
			answer = arr[i];
		}
		else if (maxi == sum)
			answer = min(answer, arr[i]);
	}

	return answer;
}

int main() {
	FASTIO;
	vector<string> table = { "SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA" };
	vector<string> languages = { "JAVA", "JAVASCRIPT" };
	vector<int> preference = { 7, 5 };
	cout << "\n";
	cout << solution(table, languages, preference);

	return 0;
}