#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int arr[21];
	vector<int> temp;
	int a, b;
	for (int i = 1; i <= 20; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++) {
		temp.clear();
		cin >> a >> b;
		for (int j = a; j <= b; j++) {
			temp.push_back(arr[j]);
		}
		reverse(temp.begin(), temp.end());
		for (int j = a; j <= b; j++) {
			arr[j] = temp[j - a];
		}
	}
	for (int i = 1; i <= 20; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}