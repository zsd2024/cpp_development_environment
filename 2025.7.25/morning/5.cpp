#include <bits/stdc++.h>
using namespace std;
int v, p;
int a[301];
int wz[31];
int mn = INT_MAX;
void dfs(int d)
{
	if (d == p + 1)
	{
		int s = 0;
		for (int i = 1; i <= v; ++i)
		{
			int mn = INT_MAX;
			for (int j = 1; j <= p; ++j)
				mn = min(mn, abs(a[i] - a[wz[j]]));
			s += mn;
		}
		mn = min(mn, s);
	}
	for (int i = wz[d - 1] + 1; i <= v; ++i)
	{
		wz[d] = i;
		dfs(d + 1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> v >> p;
	for (int i = 1; i <= v; ++i)
		cin >> a[i];
	dfs(1);
	cout << mn;
}