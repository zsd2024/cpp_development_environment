#include <bits/stdc++.h>
using namespace std;
int k, n;
struct node
{
	int s, yy, ly;
};
int ans;
int a[51];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	while (true)
	{
		queue<node> q;
		q.push(node{0, 0, 1});
		while (q.size())
		{
			node t = q.front();
			q.pop();
			if (t.yy < k)
				for (int i = t.ly; i <= n; ++i)
					if (t.s + a[i] == ans + 1)
					{
						++ans;
						goto ok;
					}
					else if (t.s + a[i] < ans + 1)
						q.push(node{t.s + a[i], t.yy + 1, i});
		}
		cout << ans << '\n';
		break;
	ok:;
	}
}