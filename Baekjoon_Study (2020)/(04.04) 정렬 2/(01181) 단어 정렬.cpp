#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string& a, string& b) {
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N;
	vector<string> v;
	string s;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), compare);
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}

	return 0;
}