#include <bits/stdc++.h>
using namespace std;
int m, p;
int last;
vector<int> v;
vector<int> q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> p;
	for (int i = 1; i <= m; ++i)
	{
		char op;
		cin >> op;
		if (op == 'Q')
		{
			int L;
			cin >> L;
			int mx;
			for (int j = (int)q.size() - 1; j >= 0; --j)
			{
				if (q[j] < v.size() - L)
					break;
				mx = max(mx, v[q[j]]);
			}
			cout << (last = mx) << ' ';
		}
		else if (op == 'A')
		{
			int t;
			cin >> t;
			t = (t + last) % p;
			v.push_back(t);
			for (int j = (int)q.size() - 1; j >= 0; --j)
				if (v[j] < t)
					q.pop_back();
				else
					break;
			q.push_back(v.size() - 1);
		}
	}
}