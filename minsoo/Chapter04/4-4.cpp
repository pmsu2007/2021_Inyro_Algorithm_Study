/*
이코테
게임 개발
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define DIRECTION 4

vector<pair<int, int>> steps = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int main()
{
	int width, length; // 가로, 세로
	cin >> width >> length;
	
	int direction; // 방향
	pair<int, int> locate; // 위치한 좌표
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
	
	map[locate.first][locate.second] = 1; // 방문 처리

	while (true)
	{
		// 종료 조건
		bool block = false; 
		int count = 0;
		
		for (int i = 0; i < DIRECTION; i++)
		{
			direction = (direction - 1 + DIRECTION) % DIRECTION; // 왼쪽 방향 회전
			count++;

			pair <int, int> next_locate = { locate.first + steps[direction].first, locate.second + steps[direction].second };

			if (map[next_locate.first][next_locate.second] == 0)
			{
				locate = next_locate; // 이동
				map[next_locate.first][next_locate.second] = 1; // 방문 처리
				ans++; // 움직인 횟수
				break;
			}

			if (count == 4) // 모든 방향 탐색
			{
				direction = (direction + 2 + DIRECTION) % DIRECTION; // 반대 방향
				pair <int, int> next_locate = { locate.first + steps[direction].first, locate.second + steps[direction].second };

				if (map[next_locate.first][next_locate.second] == 0) 
				{
					locate = next_locate;
					ans++;
					break;
				}
				else if (map[next_locate.first][next_locate.second] == 1) // 바다
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
0 : 북쪽 locate.first -- 
1 : 동쪽 locate.second ++
2 : 남쪽 locate.first ++
3 : 서쪽 locate.second --

종료 조건
for문 끝날 때 까지 길 못찾을 때 

input:

4 4
1 1 0
1 1 1 1
1 0 0 1
1 1 0 1
1 1 1 1
*/