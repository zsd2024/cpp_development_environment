#include <bits/stdc++.h>
using namespace std;
int n;
int f[31][31];
int dfs(int sy, int now)
{
    if (sy < 0)
        return 0;
    if (sy == 0)
        return 1;
    if (f[sy][now])
        return f[sy][now];
    return f[sy][now] = dfs(sy - 1, now + 1) + dfs(sy - 1, now + 1) + dfs(sy - 2, now + 2);
}
int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cout << dfs(n - 1, 1);
    return 0;
}