#include <bits/stdc++.h>
using namespace std;
int n;
int ans1, ans2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while (n)
	{
		++ans1;
		if (n % 3 == 1 && !ans2)
			ans2 = ans1;
		n -= (n + 2) / 3;
	}
	cout << ans1 << ' ' << ans2 << '\n';
}