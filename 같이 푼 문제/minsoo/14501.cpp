/*
น้มุ 14501น๘
ล๐ป็
*/

#include <iostream>
#include <algorithm>

using namespace std;

int term[16];
int pay[16];
int memo[16];

void DP(int num)
{
	for (int day = num; day >= 1; day--)
	{
		if (day + term[day] - 1 > num && day == num)
		{
			memo[day] = 0;
		}
		else if (day + term[day] - 1 > num && day != num)
		{
			memo[day] = memo[day + 1];
		}
		else
		{
			int temp = term[day];
			memo[day] = max(memo[day + 1], pay[day] + memo[day + temp]);
		}
	}
}

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> term[i];
		cin >> pay[i];
	}

	DP(N);

	cout << *max_element(memo, memo + N - 1);
}