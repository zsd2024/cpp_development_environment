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
		if (::t[x])
	}
}