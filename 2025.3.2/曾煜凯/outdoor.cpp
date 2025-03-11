#include <bits/stdc++.h>
using namespace std;
ifstream fin("outdoor.in");
ofstream fout("outdoor.out");
int K, N, M;
int cy[101];
vector<int> e[101];
bool can_go_[101][101];
bool can_not_go_[101][101];
bool vis[101];
bool can_go(int from, int to)
{
    if (can_go_[from][to])
        return true;
    if (can_not_go_[from][to])
        return false;
    vis[from] = true;
    for (size_t i = 0; i < e[from].size(); ++i)
        if (!vis[e[from][i]] && (can_go(e[from][i], to) || e[from][i] == to))
            return vis[from] = false, can_go_[from][to] = true, true;
    return vis[from] = false, can_not_go_[from][to] = true , false;
}
int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);
    fin.tie(0);
    fin >> K >> N >> M;
    for (int i = 1; i <= K; ++i)
        fin >> cy[i];
    for (int i = 1; i <= M; ++i)
    {
        int from, to;
        fin >> from >> to;
        e[from].push_back(to);
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        bool flag = true;
        for (int j = 1; j <= K; ++j)
        {
            memset(vis, 0, sizeof(vis));
            if (!can_go(j, i))
                flag = false;
        }
        if (flag)
            ++ans;
    }
    fout << ans;
}