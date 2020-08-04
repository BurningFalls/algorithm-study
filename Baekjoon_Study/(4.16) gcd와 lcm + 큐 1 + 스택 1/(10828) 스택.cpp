#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int N;
	string str;
	int num;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push") {
			cin >> num;
			v.push_back(num);
		}
		else if (str == "top") {
			if (v.empty())
				cout << "-1\n";
			else {
				cout << v.back() << "\n";
			}
		}
		else if (str == "size") {
			cout << v.size() << "\n";
		}
		else if (str == "empty") {
			if (v.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "pop") {
			if (v.empty())
				cout << "-1\n";
			else {
				cout << v.back() << "\n";
				v.pop_back();
			}
		}
	}

	return 0;
}