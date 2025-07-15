#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (; n != 0; cin >> n)
		cout << (n % 2 == 0 ? "Alice\n" : "Bob\n");
}