#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	int N;
	int A[51];
	vector<pair<int, int>> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		v.push_back(make_pair(A[i], i));
	}
	stable_sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		v[i].first = i;
	}
	stable_sort(v.begin(), v.end(), compare);
	for (int i = 0; i < N; i++) {
		cout << v[i].first << " ";
	}

	return 0;
}