/*
이코테
미래 도시
*/

#include <iostream>

#define INF 1e9

using namespace std;

int n, m;
int graph[101][101];

int main()
{
	cin >> n >> m;

	for (int i = 0; i < 101; i++)
	{
		fill(graph[i], graph[i] + 101, INF);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				graph[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	int x, k;
	cin >> x >> k;

	for (int c = 1; c <= n; c++)
	{
		for (int a = 1; a <= n; a++)
		{
			for (int b = 1; b <= n; b++)
			{
				if (a == 1 && b == k && c == x)
					continue;
				graph[a][b] = min(graph[a][b], graph[a][c] + graph[c][b]);
			}
		}
	}

	int ans = graph[1][k] + graph[k][x];

	if (ans >= INF)
		cout << -1;
	else
		cout << ans;
}

/*
5 7
1 2 
1 3
1 4
2 4
3 4
3 5
4 5 
4 5

4 2
1 3
2 4
3 4


5 4
1 2
1 3
3 4
4 5
4 5
*/