#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000001];
string t;
long long s;
int main()
{
    freopen("tourism.in", "r", stdin);
    freopen("tourism.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        s = 0;
        int m;
        cin >> m;
        for (int j = 1; j <= m; ++j)
        {
            cin >> t >> a[j];
            s += a[j];
        }
        sort(a + 1, a + m + 1);
        if (m % 2 == 0)
            if ((long long)(a[m / 2] + a[m / 2 + 1]) * (m / 2) == s)
                cout << "YES\n";
            else
                cout << "NO\n";
        else if ((long long)(a[m / 2 + 1]) * m == s)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}