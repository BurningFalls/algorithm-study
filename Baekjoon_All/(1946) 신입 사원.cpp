#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int T;
	int N;
	vector<pair<int, int>> v;
	int score1, score2;
	int max_score;
	int cnt;
	cin >> T;
	for (int a = 0; a < T; a++) {
		v.clear();
		cnt = 1;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> score1 >> score2;
			v.push_back(make_pair(score1, score2));
		}
		sort(v.begin(), v.end());
		max_score = v[0].second;
		for (int i = 1; i < N; i++) {
			if (max_score > v[i].second) {
				max_score = v[i].second;
				cnt++;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}