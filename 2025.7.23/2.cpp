#include <bits/stdc++.h>
using namespace std;
int k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k;
	for (int K = 1; K <= k; ++K)
	{
		long long n, e, d;
		cin >> n >> e >> d;
		// n = p * q
		// ed = p * q - p - q + 2
		// ed = n - p - q + 2
		long long j = n, h = n + 2 - e * d;
		long long sqr_c = h * h - j * 4;
		if (sqr_c >= 0)
		{
			long double c_d = sqrtl(sqr_c);
			if (c_d == floor(c_d))
			{
				long long c = c_d;
				long long p = (h - c) / 2, q = (h + c) / 2;
				if (p > 0 && q > 0)
					cout << p << ' ' << q << '\n';
				else
					cout << "NO\n";
			}
			else
				cout << "NO\n";
		}
		else
			cout << "NO\n";
	}
}