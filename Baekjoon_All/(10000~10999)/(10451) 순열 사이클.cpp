#include <iostream>
using namespace std;

int N;
int arr[1001];
bool visited[1001];
int ans;

void func(int start, int end) {
	if (start == end) {
		ans++;
		return;
	}
	visited[end] = 1;
	func(start, arr[end]);
}

int main() {
	int T;
	cin >> T;
	for (int a = 0; a < T; a++) {
		ans = 0;
		for (int i = 1; i <= 1000; i++) {
			visited[i] = 0;
		}
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= N; i++) {
			if (visited[i]) continue;
			visited[i] = 1;
			func(i, arr[i]);
		}
		cout << ans << "\n";
	}



	return 0;
}