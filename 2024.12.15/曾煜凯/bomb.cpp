#include <bits/stdc++.h>
using namespace std;
int d, n;
int mx, mxn;
int qj[1025][1025];
int main()
{
    freopen("bomb.in", "r", stdin);
    freopen("bomb.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> d >> n;
    for (int N = 1; N <= n; ++N)
    {
        int x, y, i;
        cin >> x >> y >> i;
        for (int h = max(x - d, 1); h <= min(x + d, 1024 - d); ++h)
            for (int l = max(y - d, 1); l <= min(y + d, 1024 - d); ++l)
                qj[h][l] += i;
    }
    for (int i = 1; i <= 1024 - d; ++i)
        for (int j = 1; j <= 1024 - d; ++j)
            if (qj[i][j] > mx)
            {
                mx = qj[i][j];
                mxn = 1;
            }
            else if (qj[i][j] == mx)
                ++mxn;
    cout << mxn << ' ' << mx;
    return 0;
}