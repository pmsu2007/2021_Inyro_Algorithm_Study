/*
이코테
상하좌우 (시뮬레이션)
*/

#include <iostream>

using namespace std;

int main()
{
	int size;
	cin >> size;
	cin.ignore(); // size 입력시 '\n'을 버퍼에서 지우는 역할

	int x = 1, y = 1;

	for (int i = 0; ; i++)
	{
		char input;
		cin.get(input); // 공백과 개행도 입력으로 받음

		if (input == '\n')
			break;
		else if (input == 'R')
		{
			if (y >= 1 && y < size)
				y++;
		}
		else if (input == 'L')
		{
			if (y > 1 && y <= size)
				y--;
		}
		else if (input == 'U')
		{
			if (x > 1 && x <= size)
				x--;
		}
		else if (input == 'D')
		{
			if (x >= 1 && x < size)
				x++;
		}
	}

	cout << x << " " << y;
	return 0;
}