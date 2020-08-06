#pragma warning(disable: 4996)
#include <iostream>
#include <time.h>
using namespace std;

int main() {
	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = gmtime(&timer);
	cout << t->tm_year + 1900 << "\n";
	cout << t->tm_mon + 1 << "\n";
	cout << t->tm_mday;

	return 0;
}