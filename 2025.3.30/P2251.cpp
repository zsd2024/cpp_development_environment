#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100001];
deque<int> q; // 单调队列取最小值
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
    {
        while (!q.empty() && a[q.back()] >= a[i])
            q.pop_back();
        q.push_back(i);
    }
    for (int i = m + 1; i <= n; ++i)
    {
        cout << a[q.front()] << '\n';
        while (!q.empty() && q.front() <= i - m)
            q.pop_front();
        while (!q.empty() && a[q.back()] >= a[i])
            q.pop_back();
        q.push_back(i);
    }
    cout << a[q.front()] << '\n';
}