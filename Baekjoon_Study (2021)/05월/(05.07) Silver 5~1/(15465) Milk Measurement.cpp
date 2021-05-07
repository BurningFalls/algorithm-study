#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

struct INF {
	int day;
	string name;
	int change;
};

vector<INF> v;

bool cmp(INF a, INF b) {
	return a.day < b.day;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int day, change;
		string name;
		cin >> day >> name >> change;
		v.push_back({ day, name, change });
	}
	sort(v.begin(), v.end(), cmp);
	int B = 7, E = 7, M = 7;
	string high = "";
	int ans = 0;
	for (INF x : v) {
		if (x.name == "Bessie")
			B += x.change;
		else if (x.name == "Elsie")
			E += x.change;
		else if (x.name == "Mildred")
			M += x.change;
		int maxi = max({ B, E, M });
		string nhigh = "";
		if (maxi == B)
			nhigh += 'B';
		if (maxi == E)
			nhigh += 'E';
		if (maxi == M)
			nhigh += 'M';
		if (high != nhigh) {
			ans++;
			high = nhigh;
		}
	}
	cout << ans;

	return 0;
}