/*
이코테
음료수 얼려 먹기
*/

#include <iostream>
#include <vector>

using namespace std;

int row, col;
vector<vector<int>> map(1001, vector<int>(1001));

bool dfs(int x, int y)
{
	if (x < 0 || y < 0 || x >= row || y >= col)
		return false;
	else if (map[x][y] != 1 )
	{
		map[x][y] = 1;
		dfs(x + 1, y);
		dfs(x - 1, y);
		dfs(x, y + 1);
		dfs(x, y - 1);
		return true;
	}
	return false;
}



int main()
{
	cin >> row >> col;
	
	int ans = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (dfs(i, j))
				ans++;
		}
	}

	cout << ans;

}

/*
input
3 3
0 0 0
1 0 1
0 1 0

15 14
0 0 0 0 0 1 1 1 1 0 0 0 0 0
1 1 1 1 1 1 0 1 1 1 1 1 1 0
1 1 0 1 1 1 0 1 1 0 1 1 1 0
1 1 0 1 1 1 0 1 1 0 0 0 0 0
1 1 0 1 1 1 1 1 1 1 1 1 1 1
1 1 0 1 1 1 1 1 1 1 1 1 0 0 
1 1 0 0 0 0 0 0 0 1 1 1 1 1
0 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 1 1 1 1 1
0 1 1 1 1 1 1 1 1 1 1 0 0 0
0 0 0 1 1 1 1 1 1 1 1 0 0 0
0 0 0 0 0 0 0 1 1 1 1 0 0 0
1 1 1 1 1 1 1 1 1 1 0 0 1 1
1 1 1 0 0 0 1 1 1 1 1 1 1 1
1 1 1 0 0 0 1 1 1 1 1 1 1 1
*/