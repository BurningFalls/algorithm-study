#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string A, B;
	int cnt;
	int max_cnt = 0;
	cin >> A >> B;
	for (int i = 0; i <= B.size() - A.size(); i++) {
		cnt = 0;
		for (int j = 0; j < A.size(); j++) {
			if (B[i + j] == A[j])
				cnt++;
		}
		max_cnt = max(max_cnt, cnt);
	}
	cout << A.size() - max_cnt;

	return 0;
}