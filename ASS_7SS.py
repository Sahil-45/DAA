def display(v):
    for i in range(len(v)):
        print(v[i], end=" ")
    print()

def print_subsets_rec(arr, i, target_sum, p):
    if i == 0 and target_sum != 0 and dp[0][target_sum]:
        p.append(arr[i])
        display(p)
        return
    if arr[i] == target_sum:
        display(p)
        return
    if i == 0 and target_sum == 0:
        display(p)
        return

    if dp[i - 1][target_sum]:
        b = p.copy()
        print_subsets_rec(arr, i - 1, target_sum, b)

    if target_sum >= arr[i] and dp[i - 1][target_sum - arr[i]]:
        p.append(arr[i])
        print_subsets_rec(arr, i - 1, target_sum - arr[i], p)

def print_all_subsets(arr, n, target_sum):
    if n == 0 or target_sum < 0:
        return

    global dp
    dp = [[False] * (target_sum + 1) for _ in range(n)]
    dp[0][0] = True

    if arr[0] <= target_sum:
        dp[0][arr[0]] = True

    for i in range(1, n):
        for j in range(target_sum + 1):
            dp[i][j] = dp[i - 1][j] or (j >= arr[i] and dp[i - 1][j - arr[i]])

    if not dp[n - 1][target_sum]:
        print(f"There are no subsets with sum {target_sum}")
        return

    p = []
    print_subsets_rec(arr, n - 1, target_sum, p)

if __name__ == "__main__":
    arr = [1, 2, 5, 6, 8]
    n = len(arr)
    target_sum = 9
    print_all_subsets(arr, n, target_sum)
