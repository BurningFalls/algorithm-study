#include <bits/stdc++.h>
using namespace std;

bool start_flag;
bool flag;
bool visited[101] = { 0, };

bool Check() {
	for (int i = 1; i <= 100; i++) {
		if (visited[i] == 1 && start_flag == false && flag == false) {
			start_flag = true;
			flag = true;
		}
		else if (visited[i] == 1 && start_flag == true && flag == false) {
			return false;
		}
		else if (visited[i] == 0) {
			flag = false;
			continue;
		}
		else if (visited[i] == 1 && start_flag == true && flag == true) {
			continue;
		}
	}
	return true;
}

int main() {
	int T;
	int arr[51];
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		memset(visited, 0, sizeof(visited));
		cin >> n;
		start_flag = false;
		flag = false;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			visited[arr[i]] = 1;
		}
		if (Check())
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}