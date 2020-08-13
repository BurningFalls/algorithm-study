#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N;
	string str;
	int num;
	queue<int> q;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push") {
			cin >> num;
			q.push(num);
		}
		else if (str == "front") {
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.front() << "\n";
		}
		else if (str == "back") {
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.back() << "\n";
		}
		else if (str == "size") {
			cout << q.size() << "\n";
		}
		else if (str == "empty") {
			if (q.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (str == "pop") {
			if (q.empty())
				cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
	}

	return 0;
}