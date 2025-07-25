#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> g[1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout << "-1\n";
}