#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int main() {
	struct tm* t = NULL;
	time_t timer = time(NULL);

	t = localtime(&timer);

	cout << t->tm_year + 1900;
	cout << "-";
	if (t->tm_mon + 1 < 10) {
		cout << "0";
	}
	cout << t->tm_mon + 1;
	cout << "-";
	if (t->tm_mday + 1 < 10) {
		cout << "0";
	}
	cout << t->tm_mday;

	return 0;
}