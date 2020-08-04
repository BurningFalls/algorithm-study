#include <iostream>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;

int cnt = 0;
vector<pair<int, int>> v;

void hanoi(int n, int start, int end) {
	if (n == 1) {
		v.push_back(make_pair(start, end));
		cnt++;
	}
	else {
		hanoi(n - 1, start, 6 - start - end);
		v.push_back(make_pair(start, end));
		cnt++;
		hanoi(n - 1, 6 - start - end, end);
	}
}

int main() {
	int N;
	cin >> N;
	hanoi(N, 1, 3);
	cout << cnt << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}

	return 0;
}