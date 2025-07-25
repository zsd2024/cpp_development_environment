#include <bits/stdc++.h>
using namespace std;
int n;
int s;
int a[101];
int ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], s += a[i];
	s /= n;
	for (int i = 1; i < n; ++i)
	{
		ans += (a[i] - s != 0);
		a[i + 1] -= (a[i] - s);
	}
	cout << ans;
}