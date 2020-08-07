#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int T;
	string str;
	string sub_str;
	string ch_str;
	int start_node;
	cin >> T;
	cin.ignore();
	for (int i = 0; i < T; i++) {
		getline(cin, str);
		ch_str = "";
		start_node = 0;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == ' ') {
				sub_str = str.substr(start_node, j - start_node);
				reverse(sub_str.begin(), sub_str.end());
				ch_str += sub_str;
				ch_str += " ";
				start_node = j + 1;
			}
		}
		sub_str = str.substr(start_node, str.size() - start_node);
		reverse(sub_str.begin(), sub_str.end());
		ch_str += sub_str;
		cout << ch_str << "\n";
	}

	return 0;
}