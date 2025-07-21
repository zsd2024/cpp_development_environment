#include <bits/stdc++.h>
using namespace std;
int n;
struct pos
{
	int x, y;
} city[5001];
inline double dis(int a, int b)
{
	return sqrt((city[a].x - city[b].x) * (city[a].x - city[b].x) + (city[a].y - city[b].y) * (city[a].y - city[b].y));
}
bool is_in_tree[5001];
int ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> city[i].x >> city[i].y;
}