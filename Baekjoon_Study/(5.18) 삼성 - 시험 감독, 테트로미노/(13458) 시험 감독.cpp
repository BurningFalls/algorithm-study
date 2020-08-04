#include <iostream>
using namespace std;

int arr[1000001];

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N;
	int B, C;
	long long int answer = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		if (arr[i] <= B)
			answer++;
		else if (arr[i] > B) {
			arr[i] -= B;
			answer++;
			if (arr[i] % C == 0)
				answer += arr[i] / C;
			else if (arr[i] % C != 0)
				answer += arr[i] / C + 1;
		}
	}
	cout << answer;

	return 0;
}