#include <bits/stdc++.h>
using namespace std;
int n;
int last = INT_MIN;
int ans;
int l;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int x, y;
		cin >> x >> y;
		if (x <= last && last <= y)
			++l;
		else if(x > last)
		{
			last=x;
			++l;
		}
		else if(y<last)
		{
			ans=max(ans,l);
			l = 1;
			last = x;
		}
	}
	cout << ans;
}