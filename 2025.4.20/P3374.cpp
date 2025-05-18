#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
int n, m;
long long a[MAXN], tree[MAXN * 4];

// 构建线段树
void build(int p, int l, int r)
{
	if (l == r)
	{
		tree[p] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
	tree[p] = tree[p * 2] + tree[p * 2 + 1];
}

// 单点修改：将位置pos的值加上val
void update(int p, int l, int r, int pos, long long val)
{
	if (l == r)
	{
		tree[p] += val;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid)
		update(p * 2, l, mid, pos, val);
	else
		update(p * 2 + 1, mid + 1, r, pos, val);
	tree[p] = tree[p * 2] + tree[p * 2 + 1];
}

// 区间查询：查询区间[ql, qr]的和
long long query(int p, int l, int r, int ql, int qr)
{
	if (ql <= l && r <= qr)
		return tree[p];
	int mid = (l + r) >> 1;
	long long sum = 0;
	if (ql <= mid)
		sum += query(p * 2, l, mid, ql, qr);
	if (qr > mid)
		sum += query(p * 2 + 1, mid + 1, r, ql, qr);
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	build(1, 1, n);

	while (m--)
	{
		int op, x, y;
		cin >> op >> x >> y;
		if (op == 1)
		{
			// 将第x个数加上y
			update(1, 1, n, x, y);
		}
		else
		{
			// 输出区间[x,y]的和
			cout << query(1, 1, n, x, y) << '\n';
		}
	}
	return 0;
}