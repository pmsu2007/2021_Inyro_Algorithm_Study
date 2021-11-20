/*
백준 1932번
정수 삼각형
*/

#include <iostream>
#include <algorithm>

using namespace std;

int memo[501][501];
int N;

int DP()
{
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1)
				memo[i][j] += memo[i - 1][j];
			else if ((j > 1) && (j < i))
				memo[i][j] += max(memo[i - 1][j - 1], memo[i - 1][j]);
			else
				memo[i][j] += memo[i - 1][j - 1];
		}
	}

	return *max_element(memo[N] + 1, memo[N] + N + 1);
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> memo[i][j];
		}
	}

	cout << DP();
}

/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
*/