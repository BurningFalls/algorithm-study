#include <iostream>
#include <vector>
using namespace std;

int arr[1000001] = { 0, };

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N, M;
	int what, a, b;
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		arr[i] = i + 1;
	}
	for (int i = 0; i < M; i++) {
		cin >> what >> a >> b;
		if (what == 0) {
			for (int j = 0; j <= N; j++) {
				if (arr[j] == arr[b])
					arr[j] = arr[a];
			}
		}
		else if (what == 1) {
			if (arr[a] == arr[b])
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}