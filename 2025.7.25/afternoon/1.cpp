#include <bits/stdc++.h>
using namespace std;
int n;
set<string> s;
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		string str;
		cin >> str;
		s.insert(str);
	}
}