#include <bits/stdc++.h>
using namespace std;
int n, l, r;
int main()
{
	cin >> n >> l >> r;
	if (r - l >= n - 1)
		cout << n - 1;
	else if (l % n + (r - l) >= n - 1)
		cout << n - 1;
	else
		cout << l % n + (r - l);
}