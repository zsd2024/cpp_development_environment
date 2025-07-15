#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[100001];
int t[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= sqrt(n); ++i)
	{
		memset(t, 0, sizeof(t));
		bool flag = true;
		for (int j = (i - 1) * sqrt(n) + 1; j <= i * sqrt(n); ++j)
			if (t[a[j]])
			{
				flag = false;
				break;
			}
			else
				++t[a[j]];
	}
	for (int i = 1; i <= q; ++i)
	{
		int li, ri;
		cin >> li >> ri;
		memset(t, 0, sizeof(t));
		bool flag = true;
		for (int j = li; j <= ri; ++j)
			if (t[a[j]])
			{
				flag = false;
				break;
			}
			else
				++t[a[j]];
		cout << (flag ? "Yes\n" : "No\n");
	}
}