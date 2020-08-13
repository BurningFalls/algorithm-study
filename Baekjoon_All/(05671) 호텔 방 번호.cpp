#pragma warning(disable: 4996)
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, M;
	int sum;
	string str;
	bool flag;
	int temp;
	bool visited[10];
	bool arr[5001] = { 0, };
	for (int i = 1; i <= 5000; i++) {
		flag = true;
		for (int j = 0; j <= 9; j++)
			visited[j] = 0;
		str = to_string(i);
		for (int j = 0; j < str.size(); j++) {
			temp = (str[j] - '0');
			if (visited[temp]) {
				flag = false;
				break;
			}
			else {
				visited[temp] = 1;
			}
		}
		if (flag)
			arr[i] = 1;
	}
	while (scanf("%d%d", &N, &M) != EOF) {
		sum = 0;
		for (int i = N; i <= M; i++) {
			sum += arr[i];
		}
		cout << sum << "\n";
	}

	return 0;
}