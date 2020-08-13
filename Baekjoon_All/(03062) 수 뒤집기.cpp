#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int T;
	string str;
	string r_str;
	string sum_str;
	string r_sum_str;
	int num;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> str;
		num = stoi(str);
		reverse(str.begin(), str.end());
		num += stoi(str);
		sum_str = to_string(num);
		r_sum_str = sum_str;
		reverse(r_sum_str.begin(), r_sum_str.end());
		if (sum_str == r_sum_str)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}