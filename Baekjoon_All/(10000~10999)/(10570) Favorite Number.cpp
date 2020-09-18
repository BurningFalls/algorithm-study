#include <iostream>
using namespace std;

int main() {
	int N;
	int V, S;
	int Check[1001] = { 0, };
	int maximum;
	int ans;
	cin >> N;
	for (int a = 0; a < N; a++) {
		for (int i = 1; i <= 1000; i++) {
			Check[i] = 0;
		}
		maximum = 0;
		cin >> V;
		for (int i = 0; i < V; i++) {
			cin >> S;
			Check[S]++;
		}
		for (int i = 1; i <= 1000; i++) {
			if (maximum < Check[i]) {
				maximum = Check[i];
				ans = i;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}