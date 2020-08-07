#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int num[7];

pair<int, int> Calculate(int* arr) {
	int max_num = 0;
	int max_cnt = 0;
	for (int i = 1; i <= 6; i++)
		num[i] = 0;
	for (int i = 0; i < 4; i++) {
		num[arr[i]]++;
	}
	for (int i = 1; i <= 6; i++) {
		if (max_cnt < num[i]) {
			max_num = i;
			max_cnt = num[i];
		}
	}
	return make_pair(max_num, max_cnt);
}

int main() {
	int N;
	int arr[4];
	pair<int, int> p;
	int temp;
	int max_temp = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[j];
		}
		p = Calculate(arr);
		if (p.second == 4)
			temp = 50000 + p.first * 5000;
		else if (p.second == 3)
			temp = 10000 + p.first * 1000;
		else if (p.second == 2) {
			vector<int> v;
			bool flag = false;
			for (int i = 1; i <= 6; i++) {
				if (num[i] == 2)
					v.push_back(i);
			}
			if (v.size() == 1) {
				temp = 1000 + v[0] * 100;
			}
			else if (v.size() == 2) {
				temp = 2000 + v[0] * 500 + v[1] * 500;
			}
		}
		else if (p.second == 1)
			temp = *max_element(arr, arr + 4) * 100;
		max_temp = max(max_temp, temp);
	}
	cout << max_temp;

	return 0;
}