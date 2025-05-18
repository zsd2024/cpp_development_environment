#include <bits/stdc++.h>
#include "BinaryIndexedTree.h"
using namespace std;
BinaryIndexedTree<int, plus<int>> t(0);
int n, m;
vector<int> a;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	a.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	t = a;
	for (int i = 1; i <= m; ++i)
	{
		int op, x, y;
		cin >> op >> x >> y;
		if (op == 1)
		{
			t[x] = int(t[x]) + y;
		}
		else
		{
			cout << t.get(y) - t.get(x - 1) << '\n';
		}
	}
}