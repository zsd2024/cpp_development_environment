#include <bits/stdc++.h>
using namespace std;
int n;
int a[17];
int fg[5][5];
int t[17];
int s;
void dfs(int d)
{
	if (d == n * n + 1)
	{
		for (int i = 1; i <= n; ++i)
		{
			int ans = 0;
			for (int j = 1; j <= n; ++j)
				ans += fg[i][j];
			if (ans != s)
				return;
		}
		for (int i = 1; i <= n; ++i)
		{
			int ans = 0;
			for (int j = 1; j <= n; ++j)
				ans += fg[j][i];
			if (ans != s)
				return;
		}
		{
			int ans = 0;
			for (int i = 1; i <= n; ++i)
				ans += fg[i][i];
			if (ans != s)
				return;
		}
		{
			int ans = 0;
			for (int i = 1; i <= n; ++i)
				ans += fg[i][n + 1 - i];
			if (ans != s)
				return;
		}
		cout << s << '\n';
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
				cout << fg[i][j] << ' ';
			cout << '\n';
		}
		exit(0);
	}
	for (int i = 1; i <= n * n; ++i)
		if (!t[i])
		{
			fg[(d - 1) / n + 1][(d - 1) % n + 1] = i;
			// cout << (d - 1) / n + 1 << ',' << (d - 1) % n + 1 << '\n';
			t[i] = true;
			dfs(d + 1);
			t[i] = false;
			// return;
		}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n * n; ++i)
	{
		cin >> a[i];
		s += a[i];
	}
	s /= n;
	sort(a + 1, a + 1 + n * n);
	dfs(1);
}
