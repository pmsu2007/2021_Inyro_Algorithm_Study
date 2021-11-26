/*
이코테
전보
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

int n, m, start;
vector<pair<int, int>> graph[30001];
int d[30001];

void Dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist)
			continue;

		for (int i = 0; i < graph[now].size(); i++)
		{
			int cost = dist + graph[now][i].second;
			int target = graph[now][i].first;
			if (cost < d[target])
			{
				d[target] = cost;
				pq.push(make_pair(-cost, target));
			}
		}
	}
}

int main()
{
	cin >> n >> m >> start;

	fill(d, d + 30001, INF);

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	Dijkstra(start);

	int con = 0;
	int maxValue = 0;

	for (int i = 2; i <= n; i++)
	{
		if (d[i] == INF)
			continue;
		else
		{
			maxValue = max(maxValue, d[i]);
			con++;
		}
	}

	cout << con << " " << maxValue << '\n';
}

/*
3 2 1
1 2 4
1 3 2
*/