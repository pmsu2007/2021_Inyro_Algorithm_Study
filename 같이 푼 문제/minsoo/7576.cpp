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
vector<pair<int, int>> direction = { {-1,0}, {1,0} ,{0,-1}, {0,1} };

queue<pair<int, int>> curTomato;
queue<pair<int, int>> nextTomato;

int main()

{
	cin >> width >> height;

	int countZero = 0;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
				countZero++;
			else if (map[i][j] == 1)
			{
				curTomato.push(make_pair(i, j));
			}
		}
	}

	int ans = 0; 
	while (true)
	{
		// 종료 조건
		if (curTomato.empty() && nextTomato.empty())
			break;

		while (!curTomato.empty())
		{
			pair<int, int> currentCoord = curTomato.front();
			curTomato.pop();
			map[currentCoord.first][currentCoord.second] = 2; // 방문처리

			for (int i = 0; i < 4; i++)
			{
				int nrow = currentCoord.first + direction[i].first;
				int ncol = currentCoord.second + direction[i].second;

				if (nrow < 0 || ncol < 0 || nrow >= height || ncol >= width)
					continue;
				else if (map[nrow][ncol] == 0)
				{
					countZero--;
					map[nrow][ncol] = 1;
					nextTomato.push(make_pair(nrow, ncol));
				}
			}
		}

		// 하루 체크
		ans++;
		while (!nextTomato.empty())
		{
			pair<int, int> temp = nextTomato.front();
			nextTomato.pop();
			curTomato.push(temp);
		}
	}

	if (countZero > 0)
		cout << -1 << '\n';
	else
		cout << ans - 1 << '\n';
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

		입력받을 때 1은 큐에 넣고 0의 개수 세기

*/