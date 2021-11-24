## 최단 경로 (Shortest Path)

가장 짧은 경로를 찾는 알고리즘

- 최단 경로를 구해야 하는 상황
  1. 한 지점에서 다른 특정 지점까지의 최단 경로를 구해야 하는 경우
  2. 모든 지점에서 다른 모든 지점까지의 최단 경로를 모두 구해야 하는 경우

### 다익스트라 최단 경로 알고리즘 (Dijkstra Algorithm)

그래프에서 여러 개의 노드가 있을 때, 특정한 노드에서 출발하여 다른 노드로 가는 각각의 최단 경로를 구해주는 알고리즘. '음의 간선'이 없을 때 정상적으로 작동한다.

- 과정
  1. 출발 노드를 설정
  2. 최단 거리 테이블을 초기화
  3. 방문하지 않은 노드 중 최단 거리가 가장 짧은 노드를 선택
  4. 선택한 노드를 거쳐 다른 노드로 가는 비용을 계산하여 최단 거리 테이블을 갱신
  5. 위 과정에서 3번과 4번을 반복

최단 경로를 구하는 과정에서 '각 노드에 대한 현재까지의 최단 거리' 정보를 항상 1차원 리스트에 저장하며 리스트를 계속 갱신한다.

- 구현 방법

  "**한 단계당 하나의 노드에 대한 최단 거리를 확실히 찾는 것**"

  

  1. 구현하기 쉽지만 느리게 동작하는 코드 : 일차원 배열 

     O(V^2^)의 시간 복잡도를 가지며, V는 노드의 개수를 의미한다. 

     각 노드에 대한 최단 거리를 담는 1차원 리스트를 선언하고 단계마다 '방문하지 않은 노드 중에서 최단 거리가 가장 짧은 노드를 선택'하기 위해 매 단계마다 1차원 리스트의 모든 원소를 순차 탐색한다.

     ```C++
     #include <iostream>
     #include <vector>
     
     #define INF 1e9
     
     using namespace std;
     
     // 노드의 개수(n), 간선의 개수(m), 시작 노드 번호(start)
     
     int n, m, start;
     // 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
     vector<pair<int, int>> graph[100001];
     
     // 방문한 적이 있는지 체크하는 목적의 배열 
     bool visited[100001];
     
     // 최단 거리 테이블 
     int d[100001];
     
     // 방문하지 않은 노드 중에서, 가장 최단 거리가 짧은 노드의 번호를 반환
     int getSmallestNode() {
     	int min_value = INF;
     	int index = 0;
     	for (int i = 1; i <= n; i++)
     	{
     		if (d[i] < min_value && !visited[i])
     		{
     			min_value = d[i];
     			index = i;
     		}
     	}
     	return index;
     }
     
     void dijkstra(int start) {
     
     	d[start] = 0;
     	visited[start] = true;
     
     	// 시작 정점과 연결되어 있는 정점들 까지의 거리 초기화
     	for (int j = 0; j < graph[start].size(); j++)
     	{
     		d[graph[start][j].first] = graph[start][j].second;
     	}
     
     	// 시작 노드를 제외한 전체 n - 1개의 노드에 대해 반복
     	for (int i = 0; i < n - 1; i++)
     	{
     		// 현재 최단 거리가 가장 짧은 노드를 꺼내서, 방문 처리
     		int now = getSmallestNode();
     		visited[now] = true;
     		// 현재 노드와 연결된 다른 노드 확인
     		for (int j = 0; j < graph[now].size(); j++)
     		{
     			int cost = d[now] + graph[now][j].second;
     			// 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
     			if (cost < d[graph[now][j].first])
     				d[graph[now][j].first] = cost;
     			
     		}
     	}
     }
     ```

     

  2. 구현하기에 조금 더 까다롭지만 빠르게 동작하는 코드 : 우선순위 큐

     O(ElogV)의 시간 복잡도를 가지며, V는 노드의 개수 E는 간선의 개수를 의미한다

     이전의 다익스트라 알고리즘은 '최단 거리가 가장 짧은 노드'를 찾기 위해서 순차 탐색을 해야 했지만, **최소 힙을 이용한 우선순위 큐**로 더 빠른 시간 안에 '최단 거리가 가장 짧은 노드'를 구할 수 있다.
     
     ```C++
     #include <iostream>
     #include <vector>
     #include <queue>
     #include <utility>
     
     #define INF 1e9
     using namespace std;
     
     // 노드의 개수(N), 간선의 개수(M), 시작 노드 번호(Start)
     int n, m, start;
     
     // 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
     vector<pair<int, int>> graph[100001]; 
     
     // 최단 거리 테이블 만들기
     int d[100001];
     
     void Dijkstra(int start)
     {
     	priority_queue<pair<int, int>> pq;
     	// 시작 노드로 가기 위한 최단 경로는 0으로 설정 후 큐에 삽입
     	pq.push(make_pair(0, start));
     	d[start] = 0;
     
     	while (!pq.empty())
     	{
     		// 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
     		int dist = -pq.top().first;
     		int now = pq.top().second;
     		pq.pop();
     
     		// 현재 노드가 이미 처리된 적이 있는 노드라면 무시
     		if (d[now] < dist)
     			continue;
     
     		// 현재 노드와 연결된 다른 인접한 노드들을 확인
     		for (int i = 0; i < graph[now].size(); i++)
     		{
     			int cost = dist + graph[now][i].second;
     			int target = graph[now][i].first; // 현재 노드와 연결된 다른 인접한 노드
     			// 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
     			if (cost < d[target])
     			{
     				d[target] = cost;
     				pq.push(make_pair(-cost, target));
     			}
     		}
     	}
     }
     ```

### 플로이드 워셜 알고리즘 (Floyd-Warshall Algorithm)

'모든 지점에서 다른 모든 지점까지의 최단 경로를 모두 구해야 하는 경우'에 사용하는 알고리즘이다. 단계마다 '거쳐 가는 노드'를 기준으로 알고리즘을 수행한다. `Dijkstra`알고리즘과 달리 매번 방문하지 않은 노드 중에서 최단 거리를 갖는 노드를 찾을 필요가 없다. 

다이나믹 프로그래밍이라는 특징이 있으므로 각 단계마다 **점화식에 맞게** 이차원 배열을 갱신하면 된다. 

> D~ab~ = min (D~ab~, D~ak~ + D~kb~)

노드의 개수가 N개일 때 알고리즘 상으로 N번의 단계를 수행하며, 단계마다 O(N^2^)의 연산을 통해 '현재 노드를 거쳐가는' 모든 경로를 고려한다. 따라서 시간 복잡도는 O(N^3^)이다.

- 코드

```c++
#include <iostream>
#include <algorithm>

#define INF 1e9
using namespace std;

// 노드의 개수(N), 간선의 개수(M)
int n, m;


int graph[501][501];


int main()
{
	cin >> n >> m;

	// 최단 거리 테이블을 모두 무한으로 초기화
	for (int i = 0; i < 501; i++)
	{
		fill(graph[i], graph[i] + 501, INF);
	}

	// 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화
	for (int a = 1; a <= n; a++)
	{
		for (int b = 1; b <= n; b++)
		{
			if (a == b) graph[a][b] = 0;
		}
	}

	// 각 간선에 대한 정보를 입력 받아, 테이블 초기화
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u][v] = w;
	}

	// 점화식에 따라 플로이드 워셜 알고리즘을 수행
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	// 수행된 결과를 출력
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			// 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
			if (graph[a][b] == INF) {
				cout << "INFINITY" << ' ';
			}
			// 도달할 수 있는 경우 거리를 출력
			else {
				cout << graph[a][b] << ' ';
			}
		}
		cout << '\n';
	}
}
```

