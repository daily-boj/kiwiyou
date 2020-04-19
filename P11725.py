node_count = int(input())
nodes = [[] for _ in range(node_count)]
for _ in range(node_count - 1):
    connection = [int(x) for x in input().split(' ')]
    one = connection[0]
    other = connection[1]
    nodes[one - 1].append(other - 1)
    nodes[other - 1].append(one - 1)

next_visit = [0]
visited = [False] * node_count
parents = [0] * node_count
visited[0] = True
while len(next_visit) > 0:
    current = next_visit.pop()
    for child in nodes[current]:
        if not visited[child]:
            visited[child] = True
            parents[child] = current + 1
            next_visit.append(child)

for parent in parents[1:]:
    print(parent)
