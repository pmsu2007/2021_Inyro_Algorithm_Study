/*
������
�����¿� (�ùķ��̼�)
*/

#include <iostream>

using namespace std;

int main()
{
	int size;
	cin >> size;
	cin.ignore(); // size �Է½� '\n'�� ���ۿ��� ����� ����

	int x = 1, y = 1;

	for (int i = 0; ; i++)
	{
		char input;
		cin.get(input); // ����� ���൵ �Է����� ����

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