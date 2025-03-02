#include <bits/stdc++.h>
using namespace std;
ifstream fin("recipe.in");
ofstream fout("recipe.out");
int n, L, R;
int a[41];
int ans = 0;
void dfs(int now, int sum)
{
    if (L <= sum && sum <= R)
        ++ans;
    if (now == n + 1 || sum > R)
        return;
    dfs(now + 1, sum + a[now]);
    dfs(now + 1, sum);
}
int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);
    fin.tie(0);
    fin >> n >> L >> R;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    dfs(1, 0);
    fout << ans;
}