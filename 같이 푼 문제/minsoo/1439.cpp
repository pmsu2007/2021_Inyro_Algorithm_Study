/*
����
������ 1439��
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string bit;
	cin >> bit;

	int countZero = 0;
	int countOne = 0;

	char curBit;

	// 1, 0 ���� ������
	int index = 0;
	int strlen = bit.length();
	curBit = bit[index];

	while (index != strlen)
	{
		bool change = false;
		

		if (curBit != bit[index++])
			change = true;
		
		if (change)
		{
			if (curBit == '0')
			{
				countZero++;
				curBit = '1';
			}
			else
			{
				countOne++;
				curBit = '0';
			}
		}

	}

	// ������ ���� Ȯ��
	if (curBit == bit[strlen - 1])
	{
		if (curBit == '1')
			countOne++;
		else
			countZero++;
	}
	int ans = min(countOne, countZero);
	cout << ans;
}
