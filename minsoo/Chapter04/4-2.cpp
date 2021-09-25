/*
이코테
시각 (완전 탐색)
*/

#include <iostream>

using namespace std;

int check[15] = { 3, 13, 23, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 43, 53 };
int checkHour[3] = { 3, 13, 23 };

int main()
{
	int N;
	cin >> N;

	int count = 0;
	int H_index = 0;

	/*
	for (int hour = 0; hour <= N; hour++)
	{
		if (hour == checkHour[H_index])
		{
			H_index++;
			count += 3600;
		}
		else
			count += 1575; // 15 * 60 + 45 * 15
	}
	*/

	for (int hour = 0; hour <= N; hour++)
	{
		for (int min = 0; min < 60; min++)
		{
			for (int sec = 0; sec < 60; sec++)
			{
				if (hour % 10 == 3 || min/10 == 3 || min % 10 == 3 || sec /10 == 3 || sec % 10 == 3)
				count++;
			}
		}
	}
	cout << count;
	

}

