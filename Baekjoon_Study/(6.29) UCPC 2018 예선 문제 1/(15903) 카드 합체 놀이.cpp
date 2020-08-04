#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<long long int, vector<long long int>, greater<long long int>> pq;

int main() {
	int N, M;
	long long int num;
	long long int a, b;
	long long int sum;
	long long int ans = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num;
		pq.push(num);
	}
	for (int i = 0; i < M; i++) {
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		sum = a + b;
		pq.push(sum);
		pq.push(sum);
	}
	for (int i = 0; i < N; i++) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans;

	return 0;
}