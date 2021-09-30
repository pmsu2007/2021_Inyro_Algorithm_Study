/*
이코테
미로 탈출
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

#define MAX 200
using namespace std;

vector<vector<int>> map(MAX, vector<int>(MAX));
vector <pair<int, int>> direction = { {1, 0},{-1,0}, {0,1},{0,-1} };

int row, col;

int bfs(int x, int y)
{
	pair<int, int> coord;
	queue<pair<int, int>> q;

	int step = 1;
	coord = { x, y };
	q.push(coord);
	
	while (!q.empty())
	{
		auto locate = q.front();
		q.pop();
		
		for (int i = 0; i < direction.size(); i++)
		{
			pair<int, int> next_locate = { locate.first + direction[i].first,
								locate.second + direction[i].second };
			if (next_locate.first < 0 || next_locate.second < 0 || next_locate.first >= row || next_locate.second >= col)
				continue;
			else if (map[next_locate.first][next_locate.second] == 1)
			{
				map[next_locate.first][next_locate.second] = map[locate.first][locate.second] + 1;
				q.push(next_locate);
			}
		}
	}
	
	return map[row - 1][col - 1];
}

int main()
{
	cin >> row >> col;

	for (int i = 0; i < row; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < col; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}

	cout << bfs(0, 0) << '\n';

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << '\n';
	}
}

/*
5 6
101010
111111
000001
111111
111111
*/