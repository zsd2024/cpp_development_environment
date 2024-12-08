#include <bits/stdc++.h>
using namespace std;
int t;
int n, m, k;
int x[501]/*价格*/, y[501]/*数量*/, z[501]/*价值*/;
int dp[501][501];
int main()
{
    freopen("chowhound.in", "r", stdin);
    freopen("chowhound.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    for (int T = 1; T <= t; ++T)
    {
        cin >> m >> n >> k;
        for (int i = 1; i <= m; ++i)
            cin >> x[i] >> y[i] >> z[i];
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                for (int l = 1; l <= y[i]; ++l)
                    if (j - l * x[i] >= 0)
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - l * x[i]] + l * z[i]);
        cout << dp[k][n] << endl;
    }
}