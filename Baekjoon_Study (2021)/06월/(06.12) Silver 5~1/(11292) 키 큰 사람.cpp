#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

typedef struct _INF {
	int idx;
	string name;
	double height;
} INF;

vector<INF> v;

bool cmp(INF a, INF b) {
	if (a.height == b.height)
		return a.idx < b.idx;
	return a.height > b.height;
}

int main() {
	FASTIO;
	while (true) {
		v.clear();
		int N;
		cin >> N;
		if (N == 0)
			break;
		FOR(i, 1, N) {
			string name;
			double height;
			cin >> name >> height;
			INF tmp = { i, name, height };
			v.push_back(tmp);
		}
		sort(v.begin(), v.end(), cmp);
		double max_height = v[0].height;
		for (INF x : v) {
			if (x.height == max_height)
				cout << x.name << " ";
			else
				break;
		}
		cout << "\n";
	}
	


	return 0;
}