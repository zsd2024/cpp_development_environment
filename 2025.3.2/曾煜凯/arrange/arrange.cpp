#include <bits/stdc++.h>
using namespace std;
ifstream fin("arrange.in");
ofstream fout("arrange.out");
int n, k;
int a[11];
bool used[11];
void dfs(int now)
{
    if (now == k + 1)
    {
        for (int i = 1; i <= k; ++i)
            fout << a[i] << ' ';
        fout << '\n';
        return;
    }
    for (int i = 1; i <= n; ++i)
        if (!used[i])
        {
            a[now] = i;
            used[i] = true;
            dfs(now + 1);
            used[i] = false;
        }
}
int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);
    fin.tie(0);
    fin >> n >> k;
    dfs(1);
}