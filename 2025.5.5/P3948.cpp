#include <bits/stdc++.h>
using namespace std;
namespace Main
{
	int n /*序列大小*/, opt /*操作次数*/, mod /*取模数*/, min /*最小值*/, max /*最大值*/;
	long long cf[80002] /*差分数组*/, a[80001] /*原数组*/;
	bool check[80001] /*标记数组*/;
	int check_qzh[80001] /*前缀和标记数组*/;
	int Final;
	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
		cin >> n >> opt >> mod >> min >> max;
		for (int i = 1; i <= opt; ++i)
		{
			char ch;
			cin >> ch;
			if (ch == 'A')
			{
				int l, r, x;
				cin >> l >> r >> x;
				cf[l] += x;
				cf[r + 1] -= x;
			}
			else if (ch == 'Q')
			{
				int l, r;
				cin >> l >> r;
				int ans = 0;
				long long sum = 0;
				for (int j = 1; j < l; ++j)
					sum = sum + cf[j];
				for (int j = l; j <= r; ++j)
				{
					sum = sum + cf[j];
					int val = sum * j % mod;
					if (min <= val && val <= max)
						++ans;
				}
				cout << ans << '\n';
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			a[i] = a[i - 1] + cf[i];
			int val = a[i] * i % mod;
			if (min <= val && val <= max)
				check[i] = true;
			else
				check[i] = false;
		}
		for (int i = 1; i <= n; ++i)
			check_qzh[i] = check_qzh[i - 1] + check[i];
		cin >> Final;
		for (int i = 1; i <= Final; ++i)
		{
			int l, r;
			cin >> l >> r;
			cout << check_qzh[r] - check_qzh[l - 1] << '\n';
		}
		return 0;
	}
}
int main()
{
	return Main::main();
}