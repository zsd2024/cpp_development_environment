#include <bits/stdc++.h>
using namespace std;
int n, q;
int kc;
int a[100001];
int t[100001];
bool fk[101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	kc = ceil(sqrt(n));
	for (int i = 1; i <= n / kc; ++i)
	{
		memset(t, 0, sizeof(t));
		bool flag = true;
		for (int j = (i - 1) * kc + 1; j <= i * kc; ++j)
			if (t[a[j]])
			{
				flag = false;
				break;
			}
			else
				++t[a[j]];
		fk[i] = flag;
	}
	{
		memset(t, 0, sizeof(t));
		bool flag = true;
		for (int j = kc * (n / kc) + 1; j <= n; ++j)
			if (t[a[j]])
			{
				flag = false;
				break;
			}
			else
				++t[a[j]];
		fk[n / kc + 1] = flag;
	}
	for (int i = 1; i <= q; ++i)
	{
		int li, ri;
		cin >> li >> ri;
		bool fflag = true;
		for (int j = (li + kc * 2) / kc; j <= ri / kc; ++j)
			if (fk[j] == false)
			{
				fflag = false;
				break;
			}
		if (fflag == false)
		{
			cout << "No\n";
			continue;
		}
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