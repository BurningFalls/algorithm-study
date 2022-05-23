#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF int(2e9)
#define LINF ll(1e18)

map<string, double> mp;

int main() {
	FASTIO;
	mp.insert({ "A+", 4.5 });
	mp.insert({ "A0", 4.0 });
	mp.insert({ "B+", 3.5 });
	mp.insert({ "B0", 3.0 });
	mp.insert({ "C+", 2.5 });
	mp.insert({ "C0", 2.0 });
	mp.insert({ "D+", 1.5 });
	mp.insert({ "D0", 1.0 });
	mp.insert({ "F", 0.0 });

	double result = 0;
	double score_sum = 0;

	FOR(i, 1, 20) {
		string name;
		double score;
		string grade;
		cin >> name >> score >> grade;
		if (grade == "P") continue;
		result += score * mp[grade];
		score_sum += score;
	}
	result /= score_sum;

	cout << fixed << setprecision(4);
	cout << result;

	return 0;
}