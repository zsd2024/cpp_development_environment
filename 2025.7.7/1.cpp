#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
string s;
int main()
{
    mp[1] = 1;
    for (int i = 1; i <= 100; ++i)
    {
        mp[i] = i;
    }
    for (auto i : mp)
        cout << i.first << ' ' << i.second << '\n';
    getchar();
}
