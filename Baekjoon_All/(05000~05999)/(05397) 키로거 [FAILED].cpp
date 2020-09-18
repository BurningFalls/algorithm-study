#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int T;
	string str;
	int node;
	vector<char> v;
	vector<char>::iterator iter;
	cin >> T;
	for (int a = 0; a < T; a++) {
		v.clear();
		iter = v.begin();
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '<') {
				if (iter != v.begin())
					iter--;
			}
			else if (str[i] == '>') {
				if (iter != v.end())
					iter++;
			}
			else if (str[i] == '-') {
				if (iter != v.begin()) {
					iter--;
					iter = v.erase(iter);
				}
			}
			else {
				iter = v.insert(iter, str[i]);
				iter++;
			}
		}
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
		cout << "\n";
	}


	return 0;
}