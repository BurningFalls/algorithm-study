#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];

int main() {
	int N, M;
	int A, B;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		v[A].push_back(B);
		v[B].push_back(A);
	}
	for (int i = 1; i <= N; i++) {
		cout << v[i].size() << "\n";
	}

	return 0;
}