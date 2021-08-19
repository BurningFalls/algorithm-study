#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

long long solution(int price, int money, int count)
{
	ll answer = max(0LL, (ll)price * ((ll)count + 1) * (ll)count / 2 - (ll)money);
	return answer;
}