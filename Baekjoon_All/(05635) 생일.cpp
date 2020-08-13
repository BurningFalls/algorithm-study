#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

int main() {
	int N;
	string name;
	int day;
	int month;
	int year;
	vector<pair<string, int>> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> name >> day >> month >> year;
		v.push_back(make_pair(name, year * 10000 + month * 100 + day));
	}
	sort(v.begin(), v.end(), compare);
	cout << v[0].first << "\n" << v[N - 1].first;

	return 0;
}