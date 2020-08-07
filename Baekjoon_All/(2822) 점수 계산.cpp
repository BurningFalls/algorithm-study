#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int arr[8];
	int temp_arr[8];
	int sum = 0;
	vector<int> v;
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
		temp_arr[i] = arr[i];
	}
	sort(arr, arr + 8);
	for (int i = 7; i >= 3; i--) {
		sum += arr[i];
		for (int j = 0; j < 8; j++) {
			if (arr[i] == temp_arr[j]) {
				v.push_back(j + 1);
				break;
			}
		}
	}
	cout << sum << endl;;
	sort(v.begin(), v.end());
	for (int i = 0; i < 5; i++) {
		cout << v[i] << " ";
	}

	return 0;
}