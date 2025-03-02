#include <bits/stdc++.h>
using namespace std;
ifstream fin("acng.in");
ofstream fout("acg.out");
int N;
int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);
    fin.tie(0);
    fin >> N;
    for (int i = 1;; ++i)
    {
        if (N % 2 == 1)
            N = N * 3 + 1;
        else
            N /= 2;
        if (N == 1)
        {
            fout << i;
            break;
        }
    }
}