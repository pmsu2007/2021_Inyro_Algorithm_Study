/*
이코테
왕실의 나이트
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int ans = 0;
vector<vector<int>> dist = { {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}
							, {2, 1}, {2, -1}, {1, -2}, {-1, -2} };
void check(int x, int y)
{
	if ((x >= 0 && x < 8) && (y >= 0 && y < 8))
		ans++;
}

int main()
{
	string coord;
	cin >> coord;

	// 좌표를 (0,0)으로 초기화
	int x = coord[1] - '1';
	int y = coord[0] - 'a';
	
	for (int i = 0; i < 8; i++)
	{
		check(x + dist[i][0], y + dist[i][1]);
	}
	cout << ans;
}