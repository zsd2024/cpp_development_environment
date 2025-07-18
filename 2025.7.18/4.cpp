#include <bits/stdc++.h>
using namespace std;
int n, m;
struct Edge
{
	int c, u, v;
	Edge(int _c, int _u, int _v)
	{
		c = _c;
		u = _u;
		v = _v;
	}
	bool operator<(const Edge &other)
	{
		return c < other.c;
	}
};
vector<Edge> edges;
int fa[305];
int f(int x)
{
	return fa[x] == x ? x : fa[x] = f(fa[x]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		edges.push_back(Edge(c, u, v));
	}
	sort(edges.begin(), edges.end());
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	int max_edge = 0, cnt = 0;
	for (Edge edge : edges)
	{
		int fu = f(edge.u), fv = f(edge.v);
		if (fu != fv)
		{
			fa[fu] = fv;
			max_edge = max(max_edge, edge.c);
			++cnt;
			if (cnt == n - 1)
				break;
		}
	}
	if (cnt < n - 1)
		cout << "http://154.44.26.231:8888/\n";
	else
		cout << n - 1 << ' ' << max_edge << '\n';
}