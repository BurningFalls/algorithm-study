#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int N;
	string str;
	int num;
	queue<int> q;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push") {
			cin >> num;
			q.push(num);
		}
		else if (str == "front") {
			if (q.empty())
				v.push_back(-1);
			else
				v.push_back(q.front());
		}
		else if (str == "back") {
			if (q.empty())
				v.push_back(-1);
			else
				v.push_back(q.back());
		}
		else if (str == "size") {
			v.push_back(q.size());
		}
		else if (str == "empty") {
			if (q.empty())
				v.push_back(1);
			else
				v.push_back(0);
		}
		else if (str == "pop") {
			if (q.empty())
				v.push_back(-1);
			else {
				v.push_back(q.front());
				q.pop();
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}



	return 0;
}