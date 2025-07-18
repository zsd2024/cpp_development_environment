#include <bits/stdc++.h>
using namespace std;
int n;
int mn = INT_MAX;
pair<int, int> sses[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> sses[i].first >> sses[i].second;
	for (int i = 1; i <= n; ++i)
	{
		int now = 0;
		int flag = true;
		for (int j = 1; j <= n; ++j)
			if (now > mn)
			{
				flag = false;
				break;
			}
			else
				now += max(abs(sses[j].first - sses[i].first), abs(sses[j].second - sses[i].second));
		if (flag)
			mn = min(mn, now);
	}
	cout << mn;
}