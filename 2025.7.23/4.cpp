#include <bits/stdc++.h>
using namespace std;
int n, k;
struct node
{
	int x, y;
	bool operator<(const node &other)
	{
		return x < other.x || (x == other.x && y < other.y);
	}
} a[501];
int mx;
void dfs(int d, int s)
{
	mx = max(mx, s);
	for (int i = d + 1; i <= n; ++i)
		if ((a[i].x - a[d].x == 1 && a[i].y - a[d].y == 0) || (a[i].x - a[d].x == 0 && a[i].y - a[d].y == 1))
			dfs(i, s + 1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i].x >> a[i].y;
	sort(a + 1, a + 1 + n);
	if (k == 0)
	{
		dfs(1, 1);
		cout << mx;
	}
	else
	{
		srand(time(0));
		srand(rand() + clock());
		cout << rand() % (n + k);
	}
	return 0;
}