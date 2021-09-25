/*
이코테
숫자 카드 게임
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int row, col;
	cin >> row >> col;

	vector<vector<int>> card(row, vector<int>(col, 0));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> card[i][j];
		}
	}

	int max = 0;

	for (int i = 0; i < row; i++)
	{
		int temp = *min_element(card[i].begin(), card[i].end()); // 행들의 최소 값 중 최대 값 구하기
		if (max < temp)
			max = temp;
	}
	
	cout << max;

	return 0;
}