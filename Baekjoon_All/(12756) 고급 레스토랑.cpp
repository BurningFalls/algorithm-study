#include <iostream>
using namespace std;

int main() {
	int A_attack, A_life;
	int B_attack, B_life;
	cin >> A_attack >> A_life;
	cin >> B_attack >> B_life;

	while (A_life > 0 && B_life > 0) {
		A_life -= B_attack;
		B_life -= A_attack;
	}
	if (A_life <= 0 && B_life <= 0) {
		cout << "DRAW";
	}
	else if (A_life <= 0) {
		cout << "PLAYER B";
	}
	else if (B_life <= 0) {
		cout << "PLAYER A";
	}

	return 0;
}