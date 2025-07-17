#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[81][81];
pair<int, int> mh[81];
int s;
int mx;
void dfs(int nn, int nm)
{
	if (nm == m + 1)
	{
		mx = max(mx, s);
		return;
	}
	if (nn == n + 1)
	{
		dfs(1, nm + 1);
		return;
	}
	{
		s += (a[nn][++mh[nn].first] << nm);
		dfs(nn + 1, nm);
		s -= (a[nn][mh[nn].first] << nm);
		--mh[nn].first;
	}
	{
		s += (a[nn][--mh[nn].second] << nm);
		dfs(nn + 1, nm);
		s -= (a[nn][mh[nn].second] << nm);
		++mh[nn].second;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
		mh[i].first = 0;
		mh[i].second = m + 1;
	}
	dfs(1, 1);
	cout << mx;
}