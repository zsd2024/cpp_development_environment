#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int pfs[30];
int t[801];
int dfs(int s)
{
	if (s > n)
		return 0;
	if (s == n)
		return 1;
	if (t[s])
		return t[s];
	int ans = 0;
	for (int i = 1; i * i <= n - s; ++i)
		ans += dfs(s + i * i);
	return t[s] = ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i * i <= 800; ++i)
		pfs[i] = i * i;
	cout << dfs(0);
}