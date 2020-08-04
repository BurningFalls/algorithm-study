#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int* arr = new int[N];
	int sum;
	int maximum = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				sum = arr[i] + arr[j] + arr[k];
				if (sum <= M) {
					maximum = max(maximum, sum);
				}
			}
		}
	}*/

	vector<int> index;
	int k = 3;
	bool flag = true;

	for (int i = 0; i < k; i++) {
		index.push_back(1);
	}
	for (int i = k; i < N; i++) {
		index.push_back(0);
	}
	sort(index.begin(), index.end());
	while (flag) {
		sum = 0;
		for (int i = 0; i < index.size(); i++) {
			if (index[i] == 1) {
				sum += arr[i];
			}
		}
		if (sum <= M) {
			maximum = max(maximum, sum);
		}
		flag = next_permutation(index.begin(), index.end());
	}

	cout << maximum;

	return 0;
}