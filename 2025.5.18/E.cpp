#include <bits/stdc++.h>
using namespace std;
int n;
string A, B;
int main()
{
	cin >> n;
	cin >> A >> B;

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (A[i] == B[i])
			continue;
		int j;
		for (j = i + 1; j < n && A[j] != B[i]; ++j);
		for (; j > i; --j)
		{
			swap(A[j], A[j - 1]);
			++ans;
		}
	}
	cout << ans;
	return 0;
}