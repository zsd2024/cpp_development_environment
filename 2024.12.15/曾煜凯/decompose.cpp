#include <bits/stdc++.h>
using namespace std;
int N;
int now = 2;
bool fir = true;
int main()
{
    freopen("decompose.in", "r", stdin);
    freopen("decompose.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    while (N > 1)
    {
        while (N % now != 0)
            ++now;
        while (N % now == 0)
        {
            if (fir)
            {
                cout << now;
                fir = false;
            }
            else
                cout << '*' << now;
            N /= now;
        }
    }
    return 0;
}