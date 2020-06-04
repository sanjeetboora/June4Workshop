#include <bits/stdc++.h>
using namespace  std;

int uniquePathsRecursive(int i, int j, int m, int n) {
	if (i >= m and j < n) {//invalid path
		return 0;
	}
	if (i < m and j >= n) {//invalid path
		return 0;
	}
	if (i == m - 1 and j == n - 1) {
		return 1;
	}

	int uniquePaths = uniquePathsRecursive(i, j + 1, m, n) +  uniquePathsRecursive(i + 1, j, m, n);
	return uniquePaths;

}

int dp[100][100] = {0};
int uniquePathsTopDown(int i, int j, int m, int n) {
	if (i >= m and j < n) {//invalid path
		return 0;
	}
	if (i < m and j >= n) {//invalid path
		return 0;
	}
	if (i == m - 1 and j == n - 1) {
		return 1;
	}
	if (dp[i][j] != 0) {
		return dp[i][j];
	}

	int uniquePaths = uniquePathsTopDown(i, j + 1, m, n) +  uniquePathsTopDown(i + 1, j, m, n);
	dp[i][j] = uniquePaths;

	return uniquePaths;

}


int uniquePathsBottomUp(int m, int n) {
	int dp[100][100] = {0};

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == 0 or j == 0)
			{
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}

	return dp[m - 1][n - 1];
}


int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int m, n;
	cin >> m >> n;

	cout << uniquePathsRecursive(0, 0, m, n) << endl;
	cout << uniquePathsTopDown(0, 0, m, n) << endl;
	cout << uniquePathsBottomUp(m, n) << endl;


	return 0;
}