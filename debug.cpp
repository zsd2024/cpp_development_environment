#include <bits/stdc++.h>
using namespace std;
int a, b, n;
int kc;
int main()
{
	cin >> a >> b >> n;
	kc = ceil(sqrt(n));
	for (int i = 1; i <= n / kc; ++i)
		cout << i << ':' << (i - 1) * kc + 1 << ' ' << i * kc << '\n';
	cout << n / kc + 1 << ':' << kc * (n / kc) + 1 << ' ' << n << '\n';
	cout << "==========\n"
		 << (a + kc * 2) / kc << ' ' << b / kc;
}
