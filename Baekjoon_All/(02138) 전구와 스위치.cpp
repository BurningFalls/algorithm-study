#include <iostream>
#include <vector>
using namespace std;

char arr1[100001], arr2[100001], arr3[100001];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N;
	int idx = 0;
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr1[i];
		arr3[i] = arr1[i];
	}
	for (int i = 0; i < N; i++)
		cin >> arr2[i];
	while (idx < N - 1) {
		if (arr1[idx] != arr2[idx]) {
			for (int i = idx; i < idx + 3; i++) {
				if (i >= N)
					break;
				if (arr1[i] == '0')
					arr1[i] = '1';
				else if (arr1[i] == '1')
					arr1[i] = '0';
			}
			ans++;
		}
		idx++;
	}
	if (arr1[N - 1] != arr2[N - 1]) {
		idx = 0;
		ans = 1;
		for (int i = 0; i <= 1; i++) {
			if (arr3[i] == '0')
				arr3[i] = '1';
			else if (arr3[i] == '1')
				arr3[i] = '0';
		}
		while (idx < N - 1) {
			if (arr3[idx] != arr2[idx]) {
				for (int i = idx; i < idx + 3; i++) {
					if (i >= N)
						break;
					if (arr3[i] == '0')
						arr3[i] = '1';
					else if (arr3[i] == '1')
						arr3[i] = '0';
				}
				ans++;
			}
			idx++;
		}
		if (arr3[N - 1] != arr2[N - 1])
			cout << -1;
		else
			cout << ans;
	}
	else
		cout << ans;

	return 0;
}