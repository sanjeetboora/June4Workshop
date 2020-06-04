#include <bits/stdc++.h>
using namespace  std;

int fibRecursive(int n) {
	//base case
	if (n == 0 or n == 1) {
		return n;
	}

	//recursive
	int nthFibonacci = fibRecursive(n - 1) + fibRecursive(n - 2);
	return nthFibonacci;
}
int dp[100] = {0};
int fipTopDown(int n) {
	//base case
	if (n == 0 or n == 1) {
		dp[n] = n;
		return n;
	}

	if (dp[n] != 0) {
		return dp[n];
	}

	int nthFibonacci = fipTopDown(n - 1) + fipTopDown(n - 2);
	dp[n] = nthFibonacci;

	return dp[n];
}
int fibBottomUp(int n) {
	int dp[100] = {0};
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n ; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}




int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	cout << fibRecursive(n) << endl;
	cout << fipTopDown(n) << endl;
	cout << fibBottomUp(n) << endl;



	return 0;
}