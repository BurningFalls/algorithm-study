#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	int a, b, c;
	int arr[101];
	vector<int> v;
	for (int i = 1; i <= 100; i++) {
		arr[i] = i;
	}
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		v.clear();
		cin >> a >> b >> c;
		for (int j = c; j <= b; j++) {
			v.push_back(arr[j]);
		}
		for (int j = a; j < c; j++) {
			v.push_back(arr[j]);
		}
		for (int j = a; j <= b; j++) {
			arr[j] = v[j - a];
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
	}



	return 0;
}