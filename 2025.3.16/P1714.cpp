#include <bits/stdc++.h>
using namespace std;
int n, m;
int p[500001];
int x, mx;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    for (int i = 1; i <= m; ++i)
        x += p[i];
    mx = x;
    for (int i = m + 1; i <= n; ++i)
    {
        x = x - p[i - m] + p[i];
        mx = max(mx, x);
    }
    cout << mx << '\n';
    return 0;
}