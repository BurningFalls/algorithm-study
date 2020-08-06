#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

bool compare(tuple<string, int, int, int> a, tuple<string, int, int, int> b) {
	if (get<1>(a) == get<1>(b)) {
		if (get<2>(a) == get<2>(b)) {
			if (get<3>(a) == get<3>(b)) {
				return get<0>(a) < get<0>(b);
			}
			return get<3>(a) > get<3>(b);
		}
		return get<2>(a) < get<2>(b);
	}
	return get<1>(a) > get<1>(b);
}

int main() {
	int N;
	vector<tuple<string, int, int, int>> v;
	string name;
	int ks, es, ms;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> name >> ks >> es >> ms;
		v.push_back(make_tuple(name, ks, es, ms));
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < N; i++) {
		cout << get<0>(v[i]) << "\n";
	}

	return 0;
}