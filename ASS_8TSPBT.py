V = 4

def tsp(graph, v, curr_pos, n, count, cost, ans):
    if count == n and graph[curr_pos][0]:
        ans[0] = min(ans[0], cost + graph[curr_pos][0])
        return

    for i in range(n):
        if not v[i] and graph[curr_pos][i]:
            v[i] = True
            tsp(graph, v, i, n, count + 1, cost + graph[curr_pos][i], ans)
            v[i] = False

if __name__ == "__main__":
    n = 4
    graph = [
        [0, 10, 15, 20],
        [10, 0, 35, 25],
        [15, 35, 0, 30],
        [20, 25, 30, 0]
    ]
    v = [False] * n
    v[0] = True
    ans = [float('inf')]
    tsp(graph, v, 0, n, 1, 0, ans)
    print("The cost of the most efficient tour =", ans[0])
