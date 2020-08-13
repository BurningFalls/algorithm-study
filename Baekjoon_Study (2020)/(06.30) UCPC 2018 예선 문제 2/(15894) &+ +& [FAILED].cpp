#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int A[1000001];
int B[1000001];
string sA[1000001];
string sB[1000001];

string Change_Two(int num) {
	string str = "";
	while (num) {
		if (num % 2 == 0)
			str += "0";
		else if (num % 2 == 1)
			str += "1";
		num /= 2;
	}
	return str;
}

int main() {
	string s1, s2, s3, s4, s5 = "";
	int temp_sum;
	int sum = 0;
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sA[i] = Change_Two(A[i]);
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		sB[i] = Change_Two(B[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp_sum = 0;
			s1 = sA[i];
			s2 = sB[j];
			for (int k = 0; k < min(s1.size(), s2.size()); k++) {
				if (s1[k] == '1' && s2[k] == '1')
					temp_sum += int(pow(2, k));
			}
			sum = (sum + temp_sum) % 1999;

			if (i == 0 && j == 0) {
				s4 = Change_Two(A[0] + B[0]);
			}
			else {
				s3 = Change_Two(A[i] + B[i]);
				s5 = "";
				for (int k = 0; k < min(s3.size(), s4.size()); k++) {
					if (s3[k] == '1' && s4[k] == '1')
						s5 += "1";
					else
						s5 += "0";
				}
				s4 = s5;
			}
		}
	}
	cout << sum << " ";
	for (int i = 0; i < s4.size(); i++) {
		if (s4[i] == '1')
			ans += int(pow(2, i));
	}
	cout << ans;

	return 0;
}