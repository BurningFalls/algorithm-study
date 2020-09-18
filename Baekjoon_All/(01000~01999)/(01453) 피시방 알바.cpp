#include <iostream>
using namespace std;

int main() {
	int N;
	bool visited[101] = { 0, };
	int num;
	int cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (visited[num])
			cnt++;
		else
			visited[num] = 1;
	}
	cout << cnt;

	return 0;
}