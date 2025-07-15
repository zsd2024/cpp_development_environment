#include <bits/stdc++.h>
using namespace std;
int n;
int a[202];
int t[202];
int s, ans = INT_MAX;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], s += a[i];
	s /= n;
	memcpy(a + n + 1, a + 1, n * sizeof(int));
	memcpy(t + 1, a + 1, 2 * n * sizeof(int));
	for (int x = 1; x <= n; ++x)
	{
		int ans = 0;
		memcpy(a + 1, t + 1, 200 * sizeof(int));
		for (int i = x; i < x - 1 + n; ++i)
			a[i + 1] += (a[i] - s), ans += abs(a[i] - s), a[i] = s;
		// cout << ans << '\n';
		::ans = min(ans, ::ans);
	}
	cout << ans;
}