#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
long long n, m, a[MAXN];
long long t[MAXN * 4], tag[MAXN * 4];

inline long long ls(long long x) { return x << 1; }
inline long long rs(long long x) { return x << 1 | 1; }

void push_up(long long p)
{
	t[p] = t[ls(p)] + t[rs(p)];
}

void build(long long p, long long l, long long r)
{
	tag[p] = 0;
	if (l == r)
	{
		t[p] = a[l];
		return;
	}
	long long mid = (l + r) >> 1;
	build(ls(p), l, mid);
	build(rs(p), mid + 1, r);
	push_up(p);
}

void push_down(long long p, long long l, long long r)
{
	if (tag[p])
	{
		long long mid = (l + r) >> 1;
		tag[ls(p)] += tag[p];
		tag[rs(p)] += tag[p];
		t[ls(p)] += tag[p] * (mid - l + 1);
		t[rs(p)] += tag[p] * (r - mid);
		tag[p] = 0;
	}
}

void update(long long nl, long long nr, long long l, long long r, long long p, long long k)
{
	if (nl <= l && r <= nr)
	{
		t[p] += k * (r - l + 1);
		tag[p] += k;
		return;
	}
	push_down(p, l, r);
	long long mid = (l + r) >> 1;
	if (nl <= mid)
		update(nl, nr, l, mid, ls(p), k);
	if (nr > mid)
		update(nl, nr, mid + 1, r, rs(p), k);
	push_up(p);
}

long long query(long long qx, long long qy, long long l, long long r, long long p)
{
	if (qx <= l && r <= qy)
	{
		return t[p];
	}
	push_down(p, l, r);
	long long mid = (l + r) >> 1, ans = 0;
	if (qx <= mid)
		ans += query(qx, qy, l, mid, ls(p));
	if (qy > mid)
		ans += query(qx, qy, mid + 1, r, rs(p));
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
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
			long long k;
			cin >> k;
			update(x, y, 1, n, 1, k);
		}
		else
		{
			cout << query(x, y, 1, n, 1) << '\n';
		}
	}
	return 0;
}