/*
������
���� ����
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define DIRECTION 4

vector<pair<int, int>> steps = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int main()
{
	int width, length; // ����, ����
	cin >> width >> length;
	
	int direction; // ����
	pair<int, int> locate; // ��ġ�� ��ǥ
	cin >> locate.first >> locate.second >> direction;

	vector<vector<int>> map(length, vector<int>(width));
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> map[i][j];
		}
	}

	int ans = 1;
	
	map[locate.first][locate.second] = 1; // �湮 ó��

	while (true)
	{
		// ���� ����
		bool block = false; 
		int count = 0;
		
		for (int i = 0; i < DIRECTION; i++)
		{
			direction = (direction - 1 + DIRECTION) % DIRECTION; // ���� ���� ȸ��
			count++;

			pair <int, int> next_locate = { locate.first + steps[direction].first, locate.second + steps[direction].second };

			if (map[next_locate.first][next_locate.second] == 0)
			{
				locate = next_locate; // �̵�
				map[next_locate.first][next_locate.second] = 1; // �湮 ó��
				ans++; // ������ Ƚ��
				break;
			}

			if (count == 4) // ��� ���� Ž��
			{
				direction = (direction + 2 + DIRECTION) % DIRECTION; // �ݴ� ����
				pair <int, int> next_locate = { locate.first + steps[direction].first, locate.second + steps[direction].second };

				if (map[next_locate.first][next_locate.second] == 0) 
				{
					locate = next_locate;
					ans++;
					break;
				}
				else if (map[next_locate.first][next_locate.second] == 1) // �ٴ�
				{
					block = true;
					break;
				}
			}
		}
		if (block)
			break;
	}
	
	std::cout << ans;
}

/*
direction 
0 : ���� locate.first -- 
1 : ���� locate.second ++
2 : ���� locate.first ++
3 : ���� locate.second --

���� ����
for�� ���� �� ���� �� ��ã�� �� 

input:

4 4
1 1 0
1 1 1 1
1 0 0 1
1 1 0 1
1 1 1 1
*/