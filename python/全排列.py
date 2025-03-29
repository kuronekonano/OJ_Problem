vis = [0] * 100
ans = []


def dfs(n, len):
    if len == n:
        print(ans)
        return 0
    for i in range(n):
        if vis[i] == 0:
            vis[i] = 1
            ans.append(i + 1)
            dfs(n, len + 1)
            ans.pop()
            vis[i] = 0


if __name__ == "__main__":
    dfs(4, 0)
