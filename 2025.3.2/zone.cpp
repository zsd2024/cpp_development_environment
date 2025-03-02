#include <bits/stdc++.h>
using namespace std;
ifstream fin("zone.in");
ofstream fout("zone.out");
int N, M;
bool mp[101][101];
bool vis[101][101];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int ans = 0;
void dfs(int x, int y)
{
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && !vis[nx][ny] && mp[nx][ny])
            dfs(nx, ny);
    }
}
int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);
    fin.tie(0);
    fin >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
        {
            char ch;
            fin >> ch;
            mp[i][j] = ch == '#';
        }
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (mp[i][j] && !vis[i][j])
            {
                dfs(i, j);
                ++ans;
            }
    fout << ans;
}