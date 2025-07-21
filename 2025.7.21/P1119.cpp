#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int t[200];
vector<pair<int, int>> v[200];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> t[i];
	for (int M = 1; M <= m; ++M)
	{
		int i, j, w;
		cin >> i >> j >> w;
		v[i].push_back({j, w});
		v[j].push_back({i, w});
	}
	cin >> q;
	for (int i = 1; i <= q; ++i)
	{
		int x, y, t;
		cin >> x >> y >> t;
		if (::t[x] > t || ::t[y] > t)
		{
			cout << "-1\n";
			continue;
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		vector<bool> visited(n, false);
		vector<int> dis(n, 0);
		dis[x] = 0;
		q.push({0, x});

		while (!q.empty())
		{
			auto [d, u] = q.top();
			q.pop();
			if (visited[u])
				continue;
			visited[u] = true;

			for (const pair<int, int> &edge : v[u])
			{
				int v = edge.first;
				int w = edge.second;
				if (!visited[v] && ::t[v] <= t && dis[v] > dis[u] + w)
				{
					dis[v] = dis[u] + w;
					q.push({dis[v], v});
				}
			}
		}
	}
}