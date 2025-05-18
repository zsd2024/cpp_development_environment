#include <iostream>
using namespace std;
const int MAXN = 105;
int n, a;
int l[MAXN], r[MAXN], c[MAXN];
long long ans = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> a;
	for (int i = 0; i < n; ++i)
		cin >> l[i] >> r[i] >> c[i];
	int total = 1 << n;
	for (int now = 0; now < total; ++now)
	{
		int s = 0;
		long long lr = 0;
		for (int i = 0; i < n; ++i)
		{
			if (now & (1 << i))
			{
				s += l[i];
				lr += 1LL * l[i] * 1000000000LL - c[i];
			}
		}
		if (s <= a)
			ans = max(ans, lr);
	}
	cout << ans;
	return 0;
}