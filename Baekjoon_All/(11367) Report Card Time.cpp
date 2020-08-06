#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string name;
	int score;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> name >> score;
		cout << name << " ";
		if (score >= 97 && score <= 100)
			cout << "A+\n";
		else if (score >= 90 && score <= 96)
			cout << "A\n";
		else if (score >= 87 && score <= 89)
			cout << "B+\n";
		else if (score >= 80 && score <= 86)
			cout << "B\n";
		else if (score >= 77 && score <= 79)
			cout << "C+\n";
		else if (score >= 70 && score <= 76)
			cout << "C\n";
		else if (score >= 67 && score <= 69)
			cout << "D+\n";
		else if (score >= 60 && score <= 66)
			cout << "D\n";
		else if (score >= 0 && score <= 59)
			cout << "F\n";
	}

	return 0;
}