#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v[100001];
bool arr[100001];
bool arr2[100001];
bool arr3[100001];

int main() {
	int k, a;
	int num;
	int cnt;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> num;
			v[i].push_back(num);
		}
	}
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr2[i] = arr[i];
	}
	for (int i = M - 1; i >= 0; i--) {
		cnt = 0;
		for (int j = 0; j < v[i].size(); j++) {
			if (arr[v[i][j]] == 0)
				cnt++;
		}
		if (cnt != 0) {
			for (int j = 0; j < v[i].size(); j++) {
				arr[v[i][j]] = 0;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		arr3[i] = arr[i];
	}
	for (int i = 0; i < M; i++) {
		cnt = 0;
		for (int j = 0; j < v[i].size(); j++) {
			if (arr[v[i][j]] == 1)
				cnt++;
		}
		if (cnt != 0) {
			for (int j = 0; j < v[i].size(); j++) {
				arr[v[i][j]] = 1;
			}
		}
	}

	cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (arr[i] == arr2[i])
			cnt++;
	}
	if (cnt == N) {
		cout << "YES\n";
		for (int i = 1; i <= N; i++) {
			cout << arr3[i] << " ";
		}
	}
	else {
		cout << "NO";
	}

	return 0;
}