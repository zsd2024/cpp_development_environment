#include <bits/stdc++.h>
using namespace std;
int a, b;
long long t = 1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b;
	// a = 1 时答案总是 1
	if (a == 1)
	{
		cout << "1\n";
		return 0;
	}
	// 暴力模拟
	for (int i = 1; i <= b; ++i)
	{
		t *= a;
		// 判断范围是否超限
		if (t > (long long)1e9)
		{
			cout << "-1\n";
			return 0;
		}
	}
	cout << t << '\n';
	return 0;
}