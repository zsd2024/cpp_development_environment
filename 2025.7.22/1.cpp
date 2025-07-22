#include <bits/stdc++.h>
using namespace std;
int n, l, r;
int main()
{
	cin >> n >> l >> r;
	if (r - l /*可以拿的糖果范围*/ >= n - 1 /*最多能拿到的奖励数量*/) // 如果范围更大，那么一定可以得到最多的奖励
		cout << n - 1;
	else if (l % n + (r - l) >= n - 1) // 如果恰好能得到最多奖励的糖果数量在范围内
		cout << n - 1;
	else
		cout << l % n + (r - l);
}