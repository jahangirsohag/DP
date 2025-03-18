#include <iostream>

#define N 100000
#define ll long long

using namespace std;

int memo[N];
bool found[N];

int f(int n)
{
	if(found[n]) return memo[n];
	if(n == 0) return 0;
	if(n == 1) return 1;

	found[n] = true;

	return memo[n] = f(n - 1) + f(n -2);
}

int main() {
	int n;
	cin >> n;

	for(int i=0; i<=n; ++i)
	{
		cout << f(i) << " ";
	}

	return 0;
}