#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int qzh[100001];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int x;
		cin >> x;
		qzh[i] = qzh[i - 1] + x;
	}
	cin >> m;
	for (int i = 1; i <= m; ++i)
	{
		int l, r;
		cin >> l >> r;
		cout << qzh[r] - qzh[l - 1] << endl;
	}
	return 0;
}