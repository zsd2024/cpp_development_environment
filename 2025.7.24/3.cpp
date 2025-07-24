#include <bits/stdc++.h>
using namespace std;
int T, M;
namespace worker
{
	struct fs;
	fs yls(int p, int q);
	int gcd(int a, int b)
	{
		return b == 0 ? a : gcd(b, a % b);
	}
	struct fs
	{
		int fz, fm;
		const fs operator+(const fs &rhs) const
		{
			return yls(fz * rhs.fm + fm * rhs.fz, fm * rhs.fm);
		}
	};
	fs yls(int p, int q)
	{
		int ys = gcd(p, q);
		p /= ys;
		q /= ys;
		if (q < 0)
		{
			p = -p;
			q = -q;
		}
		return {p, q};
	}
	struct gs
	{
		fs xs;
		int ghx;
	};
	gs sqrt(int x, int y)
	{
		int zs = 1, fzs = x;
		for (int i = ::sqrt(fzs); i >= 1; --i)
			if (fzs % (i * i) == 0)
			{
				zs = i;
				fzs /= (i * i);
				break;
			}
		return {yls(zs, y), fzs};
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T >> M;
	for (int t = 1; t <= T; ++t)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int delta = b * b - 4 * a * c;
		if (delta < 0)
			cout << "NO\n";
		else
		{
			worker::fs x = worker::yls(-b, 2 * a);
			worker::gs y = worker::sqrt(delta, 2 * a);
			y.xs.fz = abs(y.xs.fz);
			if (y.ghx == 1)
			{
				worker::fs z = y.xs;
				worker::fs t = x + z;
				if (t.fz == 0)
					cout << "0\n";
				else if (t.fm == 1)
					cout << t.fz << '\n';
				else
					cout << t.fz << '/' << t.fm << '\n';
			}
			else if (y.ghx == 0)
			{
				if (x.fz == 0)
					cout << "0\n";
				else if (x.fm == 1)
					cout << x.fz << '\n';
				else
					cout << x.fz << '/' << x.fm << '\n';
			}
			else if (x.fz == 0)
			{
				worker::fs t = y.xs;
				if (t.fz == 1)
				{
					if (t.fm == 1)
						cout << "sqrt(" << y.ghx << ")\n";
					else
						cout << "sqrt(" << y.ghx << ")/" << t.fm << '\n';
				}
				else
				{
					if (t.fz == 0)
						cout << "CSP-J 2023\n";
					else if (t.fz < 0)
					{
						if (t.fm == 1)
							cout << t.fz << "*sqrt(" << y.ghx << ")\n";
						else
							cout << t.fz << "*sqrt(" << y.ghx << ")/" << t.fm << '\n';
					}
					else if (t.fz > 0)
					{
						if (t.fm == 1)
							cout << t.fz << "*sqrt(" << y.ghx << ")\n";
						else
							cout << t.fz << "*sqrt(" << y.ghx << ")/" << t.fm << '\n';
					}
				}
			}
			else
			{
				if (x.fm == 1)
					cout << x.fz;
				else
					cout << x.fz << '/' << x.fm;
				worker::fs t = y.xs;
				if (t.fz == 1)
				{
					if (t.fm == 1)
						cout << '+' << "sqrt(" << y.ghx << ")\n";
					else
						cout << '+' << "sqrt(" << y.ghx << ")/" << t.fm << '\n';
				}
				else
				{
					if (t.fz == 0)
						cout << "CSP-J 2023\n";
					else if (t.fz < 0)
					{
						if (t.fm == 1)
							cout << t.fz << "*sqrt(" << y.ghx << ")\n";
						else
							cout << t.fz << "*sqrt(" << y.ghx << ")/" << t.fm << '\n';
					}
					else if (t.fz > 0)
					{
						if (t.fm == 1)
							cout << '+' << t.fz << "*sqrt(" << y.ghx << ")\n";
						else
							cout << '+' << t.fz << "*sqrt(" << y.ghx << ")/" << t.fm << '\n';
					}
				}
			}
		}
	}
}