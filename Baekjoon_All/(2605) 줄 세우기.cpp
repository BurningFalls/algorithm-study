#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int N;
	int num;
	int temp;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		v.push_back(i);
		for (int j = i - 1; j >= i - num; j--) {
			temp = v[j];
			v[j] = v[j - 1];
			v[j - 1] = temp;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << v[i] << " ";
	}

	return 0;
}