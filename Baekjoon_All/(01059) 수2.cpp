#include <iostream>
#include <algorithm>
using namespace std;

int cho[2];
int N;
int answer = 0;

void DFS(int start, int cnt, int end) {
	if (cnt == 2) {
		if (cho[0] <= N && N <= cho[1]) {
			answer++;
		}
		return;
	}
	if (start > end) {
		return;
	}
	for (int i = start; i <= end; i++) {
		cho[cnt] = i;
		DFS(i + 1, cnt + 1, end);
	}
}

int main() {
	int L;
	int arr[51];
	cin >> L;
	arr[0] = 0;
	for (int i = 1; i <= L; i++) {
		cin >> arr[i];
	}
	cin >> N;
	sort(arr, arr + (L + 1));
	for (int i = 0; i < L; i++) {
		if (arr[i] < N && N < arr[i + 1]) {
			DFS(arr[i] + 1, 0, arr[i + 1] - 1);
		}
	}
	cout << answer;

	return 0;
}