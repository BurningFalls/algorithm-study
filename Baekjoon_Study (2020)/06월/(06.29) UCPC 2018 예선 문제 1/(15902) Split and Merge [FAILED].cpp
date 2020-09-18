#include <iostream>
#include <vector>
using namespace std;

int L;
vector<int> ch_pos;
bool visited[3001] = { 0, };
int len;
vector<int> v1, v2;
int ans = 0;
int a, b;

long long int fac(int num) {
	long long int ans = 1;
	for (int i = 1; i <= num; i++) {
		ans = (ans * i) % 1000000007;
	}
	return ans;
}

int main() {
	int N, M;
	int num;
	int cnt = 0;
	long long int temp;
	cin >> L;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (i == 0) {
			if (num == 2)
				v1.push_back(0);
		}
		else {
			if (num == 1)
				v1.push_back(1);
			else if (num == 2) {
				v1.push_back(1);
				v1.push_back(0);
			}
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		if (i == 0) {
			if (num == 2)
				v2.push_back(0);
		}
		else {
			if (num == 1)
				v2.push_back(1);
			else if (num == 2) {
				v2.push_back(1);
				v2.push_back(0);
			}
		}
	}

	for (int i = 0; i < L - 1; i++) {
		if (v1[i] == 1 && v2[i] == 0)
			a++;
		else if (v1[i] == 0 && v2[i] == 1)
			b++;
	}

	temp = (fac(a) * fac(b)) % 1000000007;

	cout << a + b << " " << fac(a + b) / temp;

	return 0;
}