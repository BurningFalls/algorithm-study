#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int arr[101] = { 0, };

bool compare(tuple<int, int, int> a, tuple<int, int, int> b) {
	return get<2>(a) > get<2>(b);
}

int main() {
	int N;
	vector<tuple<int, int, int>> v; // get<0> v
	int a, b, c;
	int cnt = 0;
	int i = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		v.push_back(make_tuple(a, b, c));
	}
	sort(v.begin(), v.end(), compare);
	while (cnt < 3) {
		if (arr[get<0>(v[i])] != 2) {
			arr[get<0>(v[i])]++;
			cnt++;
			cout << get<0>(v[i]) << " " << get<1>(v[i]) << "\n";
		}
		i++;
	}

	return 0;
}