#include <iostream>
#include <deque>
using namespace std;

int main() {
	int N, M;
	deque<int> dq;
	int arr[51];
	int cnt = 0;
	int temp;
	double mid;
	int node = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < dq.size(); j++) {
			if (dq[j] == arr[i]) {
				node = j + 1;
				break;
			}
		}
		mid = double(dq.size() + 1) / 2;
		if (mid < node) {
			temp = dq.size() - node + 1;
			cnt += temp;
			for (int j = 0; j < temp; j++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			dq.pop_front();
		}
		else if (mid >= node) {
			temp = node - 1;
			cnt += temp;
			for (int j = 0; j < temp; j++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			dq.pop_front();
		}
	}
	cout << cnt;

	return 0;
}