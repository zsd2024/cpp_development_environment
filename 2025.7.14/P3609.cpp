#include <bits/stdc++.h>
using namespace std;
int n, k;
struct SS
{
	char data;
	SS(char data = 'U') { this->data = data; }
	bool operator<(const SS &other) const
	{
		return data == 'S' && other.data == 'H' || data == 'P' && other.data == 'S' || data == 'H' && other.data == 'P';
	}
	bool operator>(const SS &other) const
	{
		return other < *this;
	}
	bool operator==(const SS &other) const
	{
		return data == other.data;
	}
} ss[100001];
const SS h = 'H', s = 'S', p = 'P';
int mx;
void dfs(int d, int kk, int y, SS nss)
{
	if (d == n + 1)
	{
		mx = max(mx, y);
		return;
	}
	if (ss[d - 1] == ss[d] || kk == k)
		dfs(d + 1, kk, y + (ss[d] > nss), nss);
	else if (nss == h)
	{
		if (ss[d] == h)
			dfs(d + 1, kk + 1, y + 1, p);
		else if (ss[d] == p)
			dfs(d + 1, kk + 1, y + 1, s);
		else
			dfs(d + 1, kk, y + 1, h);
	}
	else if (nss == s)
	{
		if (ss[d] == h)
			dfs(d + 1, kk + 1, y + 1, p);
		else if (ss[d] == s)
			dfs(d + 1, kk + 1, y + 1, h);
		else
			dfs(d + 1, kk, y + 1, s);
	}
	else if (nss == p)
	{
		if (ss[d] == s)
			dfs(d + 1, kk + 1, y + 1, h);
		else if (ss[d] == p)
			dfs(d + 1, kk + 1, y + 1, s);
		else
			dfs(d + 1, kk, y + 1, p);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> ss[i].data;
	dfs(1, 0, 0, h);
	dfs(1, 0, 0, s);
	dfs(1, 0, 0, p);
	cout << mx;
}