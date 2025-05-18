#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int s1[N], h[N], v[N], sum[N], ans, n, top;
int main()
{
   cin >> n;
   for (int i = 1; i <= n; ++i)
   {
      cin >> h[i] >> v[i];
      while (top && h[s1[top]] < h[i])
         sum[i] += v[s1[top--]];
      sum[s1[top]] += v[i];
      s1[++top] = i;
   }
   for (int i = 1; i <= n; ++i)
      ans = max(ans, sum[i]);
   cout << ans;
   sort()
   return 0;
}