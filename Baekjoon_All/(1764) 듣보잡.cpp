#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s[500001];

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	vector<string> v;
	int N, M;
	string str;
	int len;
	int left, right, mid;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> s[i];
	sort(s, s + N);
	for (int i = 0; i < M; i++) {
		cin >> str;
		left = 0;
		right = N - 1;
		while (right - left >= 0) {
			mid = (left + right) / 2;
			if (s[mid] < str)
				left = mid + 1;
			else if (s[mid] > str)
				right = mid - 1;
			else if (s[mid] == str) {
				v.push_back(s[mid]);
				break;
			}
		}
	}
	len = v.size();
	cout << len << "\n";
	sort(v.begin(), v.end());
	for (int i = 0; i < len; i++) {
		cout << v[i] << "\n";
	}

	return 0;
}