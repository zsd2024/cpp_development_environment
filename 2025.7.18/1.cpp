#include <bits/stdc++.h>
using namespace std;
int n, m;
bool t[201];
int wz;
int main()
{
	cin >> n >> m;
	wz = 1;
	memset(t, 1, sizeof(t));
	for (int i = 1; i <= m; ++i)
	{
		int zj = (i * i * i) % 5 + 1;
		while (true)
		{
			zj -= t[++wz];
			if (zj == 0)
				break;
			if (wz >= n)
			{
				wz = 1;
				break;
			}
		}
		if (wz == 1)
		{
			--i;
			continue;
		}
		// cout << i << ':' << wz << '\n';
		t[wz] = 0;
		if (i == m)
		{
			cout << wz;
			break;
		}
		if (t[wz + 1])
			++wz;
	}
}