#include <iostream>
#include <deque>
using namespace std;

int main() {
	int N;
	int len;
	deque<int> dq;
	int num;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}
	while (true) {
		cout << dq.front() << " ";
		dq.pop_front();

		len = dq.size();
		if (len == 0)
			break;
		else if (len == 1) {
			cout << dq[0];
			break;
		}

		dq.push_back(dq.front());
		dq.pop_front();
	}

	return 0;
}