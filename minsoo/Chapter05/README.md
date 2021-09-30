## DFS / BFS 



### 그래프 탐색이란 ?

​	하나의 정점으로부터 시작하여 차례대로 모든 정점을 한 번씩 방문하는 것

- ### DFS : Depth First Search (깊이 우선 탐색) 

  <img src="https://upload.wikimedia.org/wikipedia/commons/7/7f/Depth-First-Search.gif" alt="img" style="zoom:80%;" />

  시작 정점에서 다음 브랜치로 넘어가기 전에 해당 브랜치를 완벽하게 탐색하고 넘어가는 방법

  **스택** 또는 **재귀함수**로 구현한다.

  

  ### 과정 

  1. 탐색 시작 노드를 스택에 삽입하고 방문 처리한다
  2. 스택의 최상단 노드에 방문하지 않은 인접한 노드가 하나라도 있다면 그 노드를 스택에 넣고 방문처리한다. 방문하지 않은 인접 노드가 없으면 스택에서 최상단 노드를 꺼낸다.
  3. 2번의 과정을 수행할 수 없을 때 까지 반복한다.

  

  ### 주의사항 

  인접한 노드 중에서 방문하지 않은 노드가 여러 개 있으면 번호가 낮은 순서부터 처리한다.

  

  ### 코드

  ```c++
  #include <iostream>
  #include <vector>
  #include <stack>
  
  // index 0은 사용하지 않으므로 배열 크기를 하나 크게 잡자
  bool visited[9];
  std::vector<int> graph[9];
  
  void dfs(int start) // 재귀 ver.
  {
      visited[start] = true;
      std::cout << x << " ";
      for (int i = 0; i < graph[start].size(); i++) // 인접 정점만큼 탐색
      {
          int y = graph[start][i]; 
          if(!visited[y]) 
              dfs(y); // 재귀적으로 방문
      }
  }
  
  void dfs(int start) // 스택 ver.
  {
  	std::stack<int> s;
  	s.push(start);
  	dfs_visited[start] = true;
  	std::cout << start << " ";
  
  	while (!s.empty())
  	{
  		int y = s.top(); // 스택의 최상단 노드
  		
  		int i;
  		for (i = 0; i < graph[y].size(); i++)
  		{
  			int z = graph[y][i];
  			if (!dfs_visited[z])
  			{
  				dfs_visited[z] = true;
  				s.push(z); 
  				std::cout << z << " ";
  				break;
  			}
  
  			if (i == graph[y].size() - 1) // 모두 방문한 경우
  			{
  				s.pop();
  			}
  		}
  	}
  }
  ```
  
  
  
- ### BFS : Breadth First Search (너비 우선 탐색)

  <img src="https://upload.wikimedia.org/wikipedia/commons/5/5d/Breadth-First-Search-Algorithm.gif" alt="img" style="zoom:80%;" />

  시작 정점으로부터 가장 가까운 정점을 먼저 방문하고 멀리 떨어져 있는 정점을 나중에 방문하는 방법

  **큐**를 이용해서 구현한다.

  

  ### 과정 

  1. 탐색 시작 노드를 큐에 삽입하고 방문 처리한다
  2. 큐에서 노드를 꺼낸 뒤에 해당 노드의 인접 노드 중 방문하지 않은 노드를 모두 큐에 삽입 후 방문 처리한다
  3. 2번의 과정을 수행할 수 없을 때 까지 반복한다.

  

  

  ###  코드

  ```c++
  #include <iostream>
  #include <vector>
  #include <queue>
  
  // index 0은 사용하지 않으므로 배열을 하나 크게 잡자
  bool visited[9];
  std::vector<int> graph[9];
  
  void bfs(int start)
  {
      std::queue<int> q;
     	q.push(start); // 첫 노드를 큐에 삽입
      visited[start] = true; // 첫 노드를 방문처리
      
      while(!q.empty())
      {
          int x = q.front();// 큐에서 하나의 원소를 뽑아 출력
        	q.pop();
          std::cout << x << " ";
        	for (int i = 0; i < graph[x].size(); i++)
          {
              int y = graph[x][i];
              if (!visited[y])
              {
                  q.push(y);
                  visited[y]= true;
              }
          }
      }
  }
  ```
  



### 요약

|           | DFS            | BFS              |
| :-------- | :------------- | ---------------- |
| 동작 원리 | 스택           | 큐               |
| 구현 방법 | 재귀 함수 이용 | 큐 자료구조 이용 |

- BFS가 DFS 보다 빠르게 동작한다.

- 1차원 배열이나 2차원 배열에서 탐색 문제를 만나면 그래프의 형태로 치환해서 해결할 수 도 있다.

