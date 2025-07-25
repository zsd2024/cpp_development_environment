#include <bits/stdc++.h>
using namespace std;
string n;
int m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> m)
	{
		for (int i = 1; i <= m; ++i)
		{
			string ans;
			int jw = 0;
			for (int j = 0; j < (int)n.size(); ++j)
			{
				int s = n[j] - '0' + n[n.size() - j - 1] - '0' + jw;
				jw = s / 10;
				ans.push_back(s % 10 + '0');
			}
			if (jw)
				ans.push_back(jw + '0');
			n = string(ans.rbegin(), ans.rend());
			// cout << n << '\n';
			if (n == ans)
			{
				cout << "yes\n";
				goto nxt;
			}
		}
		cout << "no\n";
	nxt:;
	}
	return 0;
}