'''
graph = [
    [],
    [2,5],
    [1,3,5],
    [2],
    [7],
    [1,2,6],
    [5],
    [4],
]
com = 7
edge = 6
'''

com = int(input())
edge = int(input())
graph = []
for i in range(com+1):
    graph.append([])
for i in range(edge):
    a,b = map(int, input().split(" "))
    graph[a].append(b)
    graph[b].append(a)

endNum = 0
def comDfs(graph, v, visited):
    global endNum
    visited[v] = True
    print("v=",v)
    for i in graph[v]:
        if not visited[i]:
            endNum+=1
            comDfs(graph,i,visited)

comVisited = [False] * (com+1)

comDfs(graph,1,comVisited)
print(endNum)