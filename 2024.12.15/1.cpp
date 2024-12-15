#include <bits/stdc++.h>
using namespace std;
string a, b;
int s = 0;
int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> a >> b)
    {
        if (a.size() == 0 || b.size() == 0)
            break;
        s = 0;
        a = a + a;
        b = b + b;
        for (int i = 0; i < a.size(); ++i)
            for (int j = 0; j < b.size(); ++j)
                if (a[i] == b[j])
                {
                    int ans = 0;
                    for (int k = i, l = j; k < a.size() && l < b.size(); ++k, ++l)
                        if (a[k] == b[l])
                            ++ans;
                        else
                            break;
                    s = max(s, ans);
                }
        cout << s << '\n';
    }
}