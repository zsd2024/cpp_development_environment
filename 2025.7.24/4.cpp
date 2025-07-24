#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int dis[10001][100];
vector<pair<int, int>> g[10001];
int try_to_go(int start_time)
{
	memset(dis, 0x3f, sizeof(dis));
	dis[1][0] = 0;
	for (int i = 1; i <= n; ++i)
		for (const pair<int, int> &t : g[i])
		{
			int v = t.first;
			int a = t.second;
			if (a <= dis[i][k - 1])
				dis[v][0] = min(dis[i][k - 1] + 1, dis[v][0]);
			for (int j = 1; j < k; ++j)
				if (a <= dis[i][j - 1])
					dis[v][j] = min(dis[i][j - 1] + 1, dis[v][j]);
		}
	return dis[n][0];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
	{
		int u, v, a;
		cin >> u >> v >> a;
		g[u].push_back({v, a});
	}
	memset(dis, 0x3f, sizeof(dis));
	dis[1][0] = 0;
	for (int i = 1; i <= n; ++i)
		for (const pair<int, int> &t : g[i])
		{
			int v = t.first;
			dis[v][0] = min(dis[i][k - 1] + 1, dis[v][0]);
			for (int j = 1; j < k; ++j)
				dis[v][j] = min(dis[i][j - 1] + 1, dis[v][j]);
		}
}