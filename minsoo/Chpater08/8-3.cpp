/*
이코테
바닥 공사
*/

#include <iostream>

using namespace std;

int memo[1001];

int DP(int size)
{
	memo[1] = 1;
	memo[2] = 3;

	for (int i = 3; i <= size; i++)
	{
		// 점화식
		memo[i] = (memo[i - 1] + 2 * memo[i - 2]) % 796796;
	}

	return memo[size];
}


int main()
{
	int N;
	cin >> N;

	cout << DP(N) << '\n';
}

