#include <bits/stdc++.h>
using namespace std;
namespace worker
{
	int n, m;
	bool mp[101][101];
	int x1, x2, y1, y2;
	enum fxs
	{
		fx_null,
		fx_up,
		fx_down,
		fx_left,
		fx_right
	};
	struct node
	{
		int zwcs;
		fxs fx;
		int x, y;
		node()
		{
		}
		node(int _zwcs, fxs _fx, int _x, int _y)
		{
			zwcs = _zwcs;
			fx = _fx;
			x = _x;
			y = _y;
		}
	};
	queue<node> q;
	const int dir[5][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
	int mn[101][101];
	bool check(int x, int y)
	{
		return !mp[x][y] && x >= 1 && x <= n && y >= 1 && y <= m;
	}
	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
			{
				int x;
				cin >> x;
				mp[i][j] = x == 1;
			}
		cin >> x1 >> y1 >> x2 >> y2;
		memset(mn, 0x7f, sizeof(mn));
		q.push(node(0, fx_null, x1, y1));
		while (!q.empty())
		{
			node t = q.front();
			q.pop();
			// cout << t.x << ' ' << t.y << '\n';
			if (t.zwcs > mn[t.x][t.y])
				continue;
			else
				mn[t.x][t.y] = t.zwcs;
			if (t.fx == fx_null)
			{
				int up_x = t.x + dir[fx_up][0], up_y = t.y + dir[fx_up][1];
				if (check(up_x, up_y))
					q.push(node(0, fx_up, up_x, up_y));
				int down_x = t.x + dir[fx_down][0], down_y = t.y + dir[fx_down][1];
				if (check(down_x, down_y))
					q.push(node(0, fx_down, down_x, down_y));
				int left_x = t.x + dir[fx_left][0], left_y = t.y + dir[fx_left][1];
				if (check(left_x, left_y))
					q.push(node(0, fx_left, left_x, left_y));
				int right_x = t.x + dir[fx_right][0], right_y = t.y + dir[fx_right][1];
				if (check(right_x, right_y))
					q.push(node(0, fx_right, right_x, right_y));
			}
			else if (t.fx == fx_up)
			{
				int up_x = t.x + dir[fx_up][0], up_y = t.y + dir[fx_up][1];
				if (check(up_x, up_y))
					q.push(node(t.zwcs, fx_up, up_x, up_y));
				int left_x = t.x + dir[fx_left][0], left_y = t.y + dir[fx_left][1];
				if (check(left_x, left_y))
					q.push(node(t.zwcs + 1, fx_left, left_x, left_y));
				int right_x = t.x + dir[fx_right][0], right_y = t.y + dir[fx_right][1];
				if (check(right_x, right_y))
					q.push(node(t.zwcs + 1, fx_right, right_x, right_y));
			}
			else if (t.fx == fx_down)
			{
				int down_x = t.x + dir[fx_down][0], down_y = t.y + dir[fx_down][1];
				if (check(down_x, down_y))
					q.push(node(t.zwcs, fx_down, down_x, down_y));
				int left_x = t.x + dir[fx_left][0], left_y = t.y + dir[fx_left][1];
				if (check(left_x, left_y))
					q.push(node(t.zwcs + 1, fx_left, left_x, left_y));
				int right_x = t.x + dir[fx_right][0], right_y = t.y + dir[fx_right][1];
				if (check(right_x, right_y))
					q.push(node(t.zwcs + 1, fx_right, right_x, right_y));
			}
			else if (t.fx == fx_left)
			{
				int up_x = t.x + dir[fx_up][0], up_y = t.y + dir[fx_up][1];
				if (check(up_x, up_y))
					q.push(node(t.zwcs + 1, fx_up, up_x, up_y));
				int down_x = t.x + dir[fx_down][0], down_y = t.y + dir[fx_down][1];
				if (check(down_x, down_y))
					q.push(node(t.zwcs + 1, fx_down, down_x, down_y));
				int left_x = t.x + dir[fx_left][0], left_y = t.y + dir[fx_left][1];
				if (check(left_x, left_y))
					q.push(node(t.zwcs, fx_left, left_x, left_y));
			}
			else if (t.fx == fx_right)
			{
				int up_x = t.x + dir[fx_up][0], up_y = t.y + dir[fx_up][1];
				if (check(up_x, up_y))
					q.push(node(t.zwcs + 1, fx_up, up_x, up_y));
				int down_x = t.x + dir[fx_down][0], down_y = t.y + dir[fx_down][1];
				if (check(down_x, down_y))
					q.push(node(t.zwcs + 1, fx_down, down_x, down_y));
				int right_x = t.x + dir[fx_right][0], right_y = t.y + dir[fx_right][1];
				if (check(right_x, right_y))
					q.push(node(t.zwcs, fx_right, right_x, right_y));
			}
		}
		cout << mn[x2][y2];
		return 0;
	}
}
int main()
{
	return worker::main();
}