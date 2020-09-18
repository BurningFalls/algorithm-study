#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	string s1, s2, s3;
	string s[10] = { "black", "brown", "red", "orange", "yellow",
	"green", "blue", "violet", "grey", "white" };
	long long int a, b, c;
	cin >> s1;
	cin >> s2;
	cin >> s3;
	for (int i = 0; i < 10; i++) {
		if (s[i] == s1) {
			a = i;
		}
		if (s[i] == s2) {
			b = i;
		}
		if (s[i] == s3) {
			c = i;
		}
	}
	cout << (long long int)(pow(10, c) * (10 * a + b)) << endl;


	return 0;
}