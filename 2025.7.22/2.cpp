#include <bits/stdc++.h>
using namespace std;
int n, q;
struct point
{
	int x, data;
} a[8001], t[8001];
bool cmp(point l, point r)
{
	return l.data < r.data || (l.data == r.data && l.x < r.x);
}
int main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		a[i].x = i, cin >> a[i].data;
	for (int i = 1; i <= q; ++i)
	{
		int x;
		cin >> x;
		if (x == 1)
		{
			int x, y;
			cin >> x >> y;
			a[x].data = y;
		}
		else if (x == 2)
		{
			memcpy(t, a, sizeof(a));
			sort(t + 1, t + 1 + n, cmp);
			int x;
			cin >> x;
			for (int i = 1; i <= n; ++i)
				if (t[i].x == x)
					cout << i << '\n';
		}
	}
}