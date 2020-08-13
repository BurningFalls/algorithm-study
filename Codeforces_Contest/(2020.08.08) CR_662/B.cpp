#include <bits/stdc++.h>
using namespace std;

int eight_cnt, six_cnt, four_cnt, two_cnt;

void Change(int num, bool flag) {
	if (flag) {
		if (num == 8) {
			eight_cnt++;
			six_cnt--;
		}
		else if (num == 6) {
			six_cnt++;
			four_cnt--;
		}
		else if (num == 4) {
			four_cnt++;
			two_cnt--;
		}
		else if (num == 2)
			two_cnt++;
	}
	else if (!flag) {
		if (num == 7) {
			eight_cnt--;
			six_cnt++;
		}
		else if (num == 5) {
			six_cnt--;
			four_cnt++;
		}
		else if (num == 3) {
			four_cnt--;
			two_cnt++;
		}
		else if (num == 1)
			two_cnt--;
	}
}

int main() {
	int n;
	int num;
	int q;
	char z;
	int x;
	map<int, int> m;
	eight_cnt = 0;
	six_cnt = 0;
	four_cnt = 0;
	two_cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (!m.count(num))
			m.insert(make_pair(num, 1));
		else {
			m[num] += 1;
			Change(m[num], true);
		}
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> z >> x;
		if (z == '+') {
			if (!m.count(x))
				m.insert(make_pair(x, 1));
			else {
				m[x] += 1; 
				Change(m[x], true);
			}
		}
		else if (z == '-') {
			if (m[x] == 1)
				m.erase(x);
			else {
				m[x] -= 1;
				Change(m[x], false);
			}
		}
		if (eight_cnt >= 1)
			cout << "YES";
		else if (eight_cnt == 0) {
			if (six_cnt >= 2)
				cout << "YES";
			else if (six_cnt == 1) {
				if (four_cnt >= 1)
					cout << "YES";
				else if (four_cnt == 0) {
					if (two_cnt >= 1)
						cout << "YES";
					else if (two_cnt == 0)
						cout << "NO";
				}
			}
			else if (six_cnt == 0) {
				if (four_cnt >= 2)
					cout << "YES";
				else if (four_cnt == 1) {
					if (two_cnt >= 2)
						cout << "YES";
					else
						cout << "NO";
				}
				else if (four_cnt == 0) {
					cout << "NO";
				}
			}
		}
		cout << "\n";
	}

	return 0;
}