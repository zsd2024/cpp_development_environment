#include <bits/stdc++.h>
using namespace std;
int n, m, r;
struct node
{
	int parent;
	int v_sum;
} tree[720001];
vector<int> g[720001];
bool vis[720001];
void build(int x)
{
	vis[x] = true;
	for (const int &y : g[x])
	{
		if (!vis[y])
		{
			tree[y].parent = x;
			build(y);
			tree[x].v_sum += tree[y].v_sum;
		}
	}
}
void add(int a, int x)
{
	tree[a].v_sum += x;
	int y = tree[a].parent;
	while (y != 0)
	{
		tree[y].v_sum += x;
		y = tree[y].parent;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; ++i)
		cin >> tree[i].v_sum;
	for (int i = 1; i < n; ++i)
	{
		int f, t;
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	build(r);
	for (int i = 1; i <= m; ++i)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int a, x;
			cin >> a >> x;
			add(a, x);
		}
		else if (op == 2)
		{
			int a;
			cin >> a;
			cout << tree[a].v_sum << ' ';
		}
	}
}