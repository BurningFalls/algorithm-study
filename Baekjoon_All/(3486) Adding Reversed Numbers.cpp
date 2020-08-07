#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s1, s2;
	int N;
	int sum;
	string s;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s1 >> s2;
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		sum = stoi(s1) + stoi(s2);
		s = to_string(sum);
		reverse(s.begin(), s.end());
		cout << stoi(s) << "\n";
	}

	return 0;
}