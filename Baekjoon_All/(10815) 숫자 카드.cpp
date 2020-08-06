#include <iostream>
using namespace std;

bool arr[20000001] = { 0, }; // -10000000
int m[500001];

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N, M;
	int num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr[num + 10000000] = 1;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> m[i];
	}
	for (int i = 0; i < M; i++) {
		if (arr[m[i] + 10000000])
			cout << "1 ";
		else
			cout << "0 ";
	}

	return 0;
}