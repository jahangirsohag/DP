#include <iostream>

#define N 100000
#define ll long long

using namespace std;

int fib[N];

int f(int n)
{
	fib[0] = 0;
	fib[1] = 1;

	for(int i = 2; i <= n; ++i)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	return fib[n];
}

int main() {
	int n;
	cin >> n;

	for(int i = 0; i <= n; ++i)
	{
		cout << f(i) << " ";
	}

	return 0;
}