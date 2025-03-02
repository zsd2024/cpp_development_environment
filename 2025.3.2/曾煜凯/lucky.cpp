#include <bits/stdc++.h>
using namespace std;
ifstream fin("lucky.in");
ofstream fout("lucky.out");
int m, n;
bool is_ss(int x)
{
    if (x <= 1)
        return false;
    for (int i = 2; i <= sqrt(x); ++i)
        if (x % i == 0)
            return false;
    return true;
}
bool is_lucky(int x)
{
    while (x)
    {
        if (!is_ss(x))
            return false;
        x /= 10;
    }
    return true;
}
int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);
    fin.tie(0);
    fin >> m >> n;
    for (int i = m; i <= n; ++i)
        if (is_lucky(i))
            fout << i << '\n';
}