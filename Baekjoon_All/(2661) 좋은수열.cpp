#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

bool check(string s) {
	reverse(s.begin(), s.end());
	string str1, str2;
	for (int i = 2; i <= s.size() / 2; i++) {
		str1 = s.substr(0, i);
		str2 = s.substr(i, i);
		if (str1.compare(str2) == 0) {
			return true;
		}
	}
	return false;
}

string good_sequence(int n) {
	stack<string> s;
	s.push("3");
	s.push("2");
	s.push("1");
	string current_node;
	string next_node;
	while (current_node.size() < n) {
		current_node = s.top();
		s.pop();
		if (current_node.back() == '1') {
			next_node = "3";
			current_node += next_node;
			if (check(current_node) == false) {
				s.push(current_node);
				current_node.pop_back();
				next_node = "2";
				current_node += next_node;
				if (check(current_node) == false) {
					s.push(current_node);
				}
				else {
					current_node.pop_back();
					current_node += "3";
				}
			}
			else {
				current_node.pop_back();
				next_node = "2";
				current_node += next_node;
				if (check(current_node) == false) {
					s.push(current_node);
				}
				else {
					current_node.pop_back();
				}
			}
		}
		else if (current_node.back() == '2') {
			next_node = "3";
			current_node += next_node;
			if (check(current_node) == false) {
				s.push(current_node);
				current_node.pop_back();
				next_node = "1";
				current_node += next_node;
				if (check(current_node) == false) {
					s.push(current_node);
				}
				else {
					current_node.pop_back();
					current_node += "3";
				}
			}
			else {
				current_node.pop_back();
				next_node = "1";
				current_node += next_node;
				if (check(current_node) == false) {
					s.push(current_node);
				}
				else {
					current_node.pop_back();
				}
			}
		}
		else if (current_node.back() == '3') {
			next_node = "2";
			current_node += next_node;
			if (check(current_node) == false) {
				s.push(current_node);
				current_node.pop_back();
				next_node = "1";
				current_node += next_node;
				if (check(current_node) == false) {
					s.push(current_node);
				}
				else {
					current_node.pop_back();
					current_node += "2";
				}
			}
			else {
				current_node.pop_back();
				next_node = "1";
				current_node += next_node;
				if (check(current_node) == false) {
					s.push(current_node);
				}
				else {
					current_node.pop_back();
				}
			}
		}
	}

	return current_node;
}

int main() {
	int N;
	cin >> N;
	cout << good_sequence(N) << endl;
	return 0;
}