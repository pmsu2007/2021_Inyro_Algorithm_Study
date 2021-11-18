/*
이코테 
1로 만들기
*/

#include <iostream>
#include <algorithm>
using namespace std;

int memo[30001];

int DP(int num)
{
	memo[1] = 0;
	int a, b, c, d;
	for (int i = 2; i <= num; i++)
	{
		a = b = c = d = 30001;

		a = memo[i - 1] + 1;
		
		if (i % 5 == 0)
			b = memo[i / 5] + 1;
		if (i % 3 == 0)
			c = memo[i / 3] + 1;
		if (num % 2 == 0)
			d = memo[i / 2] + 1;

		memo[i] = min({ a,b,c,d });
	}

	return memo[num];
}

int main()
{
	int num;
	cin >> num;

	cout << DP(num) << '\n';
}