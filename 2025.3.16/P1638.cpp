#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1000001];
int t[2001];
int aa, bb, mn = INT_MAX;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int x = 0, i = 1, j = 0;
    while (j < n)
    {
        while (j < n && x < m)
        {
            ++j;
            if (!t[a[j]])
                ++x;
            ++t[a[j]];
        }
        while (x == m)
        {
            if (j - i + 1 < mn)
            {
                mn = j - i + 1;
                aa = i;
                bb = j;
            }
            --t[a[i]];
            if (!t[a[i]])
                --x;
            ++i;
        }
    }
    cout << aa << ' ' << bb;
    return 0;
}