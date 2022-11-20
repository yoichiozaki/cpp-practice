from heapq import heappop, heappush

def dijkstra(G, start):
    has_visited = set()
    suspended = list()
    dist = [float("inf") for _ in range(len(G))]

    has_visited.add(start)
    dist[start] = 0
    suspended.append((dist[start], start))

    while len(suspended) != 0:
        cost, node = heappop(suspended)
        for (neighbor, cost_added) in G[node]:
            if neighbor not in has_visited and dist[neighbor] > cost + cost_added:
                dist[neighbor] = cost + cost_added
                heappush(suspended, (dist[neighbor], neighbor))
                has_visited.add(neighbor)
    return dist

def main():
    N, M = map(int, input().split())
    G = [[] for _ in range(N)]
    rG = [[] for _ in range(N)]
    for _ in range(M):
        u, v, w = map(int, input().split())
        u -= 1
        v -= 1
        G[u].append((v, w))
        rG[v].append((u, w))
    for i in range(N):
        dist0 = dijkstra(G, 0)
        if dist0[i] == float("inf"):
            print(-1)
            continue
        dist1 = dijkstra(rG, N - 1)
        if dist1[i] == float("inf"):
            print(-1)
            continue
        print(dist0[i] + dist1[i])

main()