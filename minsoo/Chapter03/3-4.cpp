/*
이코테
1이 될 때까지
*/

#include <iostream>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	int count = 0;

	while (N > 1)
	{
		if (N % K != 0)
		{
			// 한 번에 빼기
			int minus = (N / K) * K;
			if (minus > 0)
			{
				count += N - minus;
				N = minus;
			}
			else
			{
				count++;
				N -= 1;
			}
		}
		else
		{
			N /= K;
			count++;
		}
	}

	cout << count;
}

