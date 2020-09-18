#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	int N, M;
	string str;
	int cnt;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cnt = 0;
		cin >> N >> M;
		for (int j = N; j <= M; j++) {
			str = to_string(j);
			for (int k = 0; k < str.size(); k++) {
				if (str[k] == '0')
					cnt++;
			}
		}
		cout << cnt << "\n";
	}


	return 0;
}