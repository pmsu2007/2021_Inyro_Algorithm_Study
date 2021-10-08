/*
백준 7576번
토마토
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>>map(1000, vector<int>(1000));
int width, height;
vector<pair<int, int>> direction = { {-1,0}, {1,0} ,{0,-1},{0,1} };


void effect(int x, int y)
{
	map[x][y] = 2; // 방문 처리
	
	for (int i = 0; i < 4; i++)
	{
		int nx = x + direction[i].first;
		int ny = y + direction[i].second;

		if (nx < 0 || ny < 0 || nx >= height || ny >= width)
			continue;
		else if (map[nx][ny] == 0)
			map[nx][ny] = 1;
	}
}

bool check(int x, int y)
{
	for (int i = 0; i < 4; i++) // 상하좌우 확인
	{
		int nx = x + direction[i].first;
		int ny = y + direction[i].second;

		if (nx < 0 || ny < 0 || nx >= height || ny >= width)
			continue;
		else if (map[nx][ny] != -1) 
			return false;
	}
	return true;
}


int main()

{
	cin >> width >> height;

	bool firstCheck = false;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
				firstCheck = true;
		}
	}

	// 0이 없으면 저장 시 이미 익어있다고 가정
	if (!firstCheck)
	{
		cout << 0;
		return 0;
	}

	queue<pair<int, int>> tomato;
	int ans = 0;
	while (true) // 하루 당 반복
	{
		// 검사
		bool noZero = false; // 다 익었을 때 check
		bool noSolution = false; // 익지 못하는 상황 check
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (map[i][j] == 1)
					tomato.push({ i,j });
				else if (map[i][j] == 0)
				{
					noZero = true;
					noSolution = check(i, j);
				}
			}
		}

		if (!noZero)
		{
			cout << ans;
			break;
		}

		if (noSolution)
		{		
			cout << -1;
			break;
		}

		while (!tomato.empty())
		{
			pair<int, int> coord = tomato.front();
			tomato.pop();

			effect(coord.first, coord.second);
		}
		ans++;
	}
}

/*
		cout << ans << '\n';
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cout << map[i][j] << " ";
			}
			cout << '\n';
		}
*/