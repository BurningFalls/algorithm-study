#include <iostream>
#include <algorithm>
#include <math.h>
#include <deque>
using namespace std;

#define INF 987654321

int arr[10001];

bool compare(int a, int b) {
	return a > b;
}

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int T;
	int N;
	bool flag;
	int max_dif;
	deque<int> q;
	cin >> T;
	for (int a = 0; a < T; a++) {
		q.clear();
		flag = true;
		max_dif = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + N, compare);
		q.push_front(arr[0]);
		for (int i = 1; i < N; i++) {
			if (i % 2 == 1)
				q.push_front(arr[i]);
			else if (i % 2 == 0)
				q.push_back(arr[i]);
		}
		for (int i = 0; i < N - 1; i++) {
			max_dif = max(max_dif, abs(q[i] - q[i + 1]));
		}
		max_dif = max(max_dif, abs(q[N - 1] - q[0]));
		cout << max_dif << "\n";
	}

	return 0;
}