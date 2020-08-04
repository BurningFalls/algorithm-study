#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int len1 = s1.size();
	int len2 = s2.size();
	int a = 0;
	int b = 0;

	for (int i = 0; i < len1; i++) {
		a += (s1[i] - '0') * pow(10, i);
	}

	for (int i = 0; i < len2; i++) {
		b += (s2[i] - '0') * pow(10, i);
	}

	cout << max(a, b) << endl;

	return 0;
}