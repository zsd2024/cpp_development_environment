#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[8001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= q; ++i)
	{
		int x;
		cin >> x;
		if (x == 1)
		{
			int x, y;
			cin >> x >> y;
			a[x] = y;
		}
		else if (x == 2)
		{
			int x;
			cin >> x;
			int id = n;
			for (int i = 1; i <= n; ++i)
				if (a[i] > a[x])
					--id;
			cout << id << '\n';
		}
	}
}