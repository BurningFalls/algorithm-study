#include <iostream>
#include <algorithm>
using namespace std;

int N;
int S[21][21];
int arr_start[11];
int arr_link[11];
int arr2_start[2];
int arr2_link[2];
bool visited2[11];
bool visitedN[21];
int result1 = 0;
int result2 = 0;
int minimum = -1;

void per2(int cnt) {
	if (cnt == 2) {
		result1 += S[arr2_start[0] - 1][arr2_start[1] - 1];
		result2 += S[arr2_link[0] - 1][arr2_link[1] - 1];
		return;
	}

	for (int i = 0; i < N / 2; i++) {
		if (visited2[i]) continue;
		visited2[i] = 1;
		arr2_start[cnt] = arr_start[i];
		arr2_link[cnt] = arr_link[i];
		per2(cnt + 1);
		visited2[i] = 0;
	}
}

void perN(int node, int cnt) {
	if (cnt == N / 2) {
		int j = 1;
		for (int i = 0; i < N / 2; i++) {
			while (true) {
				if (!visitedN[j]) {
					arr_link[i] = j;
					j++;
					break;
				}
				j++;
			}
		}

		per2(0);

		if (minimum == -1) {
			minimum = abs(result1 - result2);
		}
		else {
			minimum = min(minimum, abs(result1 - result2));
		}

		result1 = 0;
		result2 = 0;
		return;
	}

	for (int i = node; i <= N; i++) {
		if (visitedN[i]) continue;
		visitedN[i] = 1;
		arr_start[cnt] = i;
		perN(i + 1, cnt + 1);
		visitedN[i] = 0;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
		}
	}
	perN(1, 0);

	cout << minimum;

	return 0;
}