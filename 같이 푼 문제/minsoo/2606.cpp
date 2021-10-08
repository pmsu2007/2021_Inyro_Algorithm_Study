/*
백준 2606
바이러스
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[101];
bool visited[101];


int ans = 0;

void dfs(int vertex)
{
	visited[vertex] = true;
	ans++;
	for (int i = 0; i < graph[vertex].size(); i++)
	{
		int y = graph[vertex][i];
		
		if (!visited[y])
			dfs(y);
	}
}

int main()
{
	int vertex, edge;

	cin >> vertex >> edge;

	// 인접 리스트 채우기
	for (int i = 0; i < edge; i++)
	{
		int front, second;
		cin >> front >> second;
		graph[front].push_back(second);
		graph[second].push_back(front);
	}

	for (int i = 1; i <= vertex; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(1);

	cout << ans - 1;
}