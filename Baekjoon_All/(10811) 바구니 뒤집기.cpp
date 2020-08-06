#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	int a, b;
	int arr[101];
	vector<int> v;
	for (int i = 1; i <= 100; i++) {
		arr[i] = i;
	}
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		v.clear();
		cin >> a >> b;
		for (int j = a; j <= b; j++) {
			v.push_back(arr[j]);
		}
		reverse(v.begin(), v.end());
		for (int j = a; j <= b; j++) {
			arr[j] = v[j - a];
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
	}



	return 0;
}