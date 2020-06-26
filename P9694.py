from heapq import heappush, heappop

def path(parent, node):
    if node == -1:
        return
    path(parent, parent[node])
    print(node, end=' ')

for i in range(int(input())):
    N, M = map(int, input().split())
    graph = [[] for _ in range(M)]
    for _ in range(N):
        x, y, z = map(int, input().split())
        graph[x].append((y, z))
        graph[y].append((x, z))
    q = []
    dist = [1000000] * M
    v = [False] * M
    paren = [-1] * M
    dist[0] = 0
    heappush(q, (0, 0))
    while (q):
        _, x = heappop(q)
        if x == M - 1:
            break
        if v[x]:
            continue
        v[x] = True
        for y, w in graph[x]:
            if dist[x] + w < dist[y]:
                dist[y] = dist[x] + w
                paren[y] = x
                heappush(q, (dist[y], y))
    if dist[M - 1] == 1000000:
        print(f'Case #{i + 1}: -1')
    else:
        print(f'Case #{i + 1}: ', end='')
        path(paren, M - 1)
        print()
