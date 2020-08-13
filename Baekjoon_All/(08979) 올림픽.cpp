#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(tuple <int, int, int, int> t1, tuple <int, int, int, int> t2) {
	if (get<1>(t1) == get<1>(t2)) {
		if (get<2>(t1) == get<2>(t2)) {
			return get<3>(t1) > get<3>(t2);
		}
		return get<2>(t1) > get<2>(t2);
	}
	return get<1>(t1) > get<1>(t2);
}

int main() {
	int N, K;
	int ct_num;
	int gold;
	int silver;
	int copper;
	int score = 1;
	int cnt = 0;
	vector<tuple <int, int, int, int>> v;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> ct_num >> gold >> silver >> copper;
		v.push_back(make_tuple(ct_num, gold, silver, copper));
	}
	stable_sort(v.begin(), v.end(), Compare);
	if (get<0>(v[0]) == K) {
		cout << 1;
	}
	else {
		for (int i = 1; i < N; i++) {
			if (get<1>(v[i]) != get<1>(v[i - 1]) ||
				get<2>(v[i]) != get<2>(v[i - 1]) ||
				get<3>(v[i]) != get<3>(v[i - 1])) {
				score = i + 1;
			}
			if (get<0>(v[i]) == K) {
				cout << score;
				break;
			}
		}
	}

	return 0;
}