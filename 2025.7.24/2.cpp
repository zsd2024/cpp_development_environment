#include <bits/stdc++.h>
using namespace std;
int n, d;
int jl, q;
int v[100001];
int a[100001];
vector<int> stations;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> d;
	for (int i = 1; i < n; ++i)
		cin >> v[i];
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	stations.push_back(1);
	for (int i = 2, prize = a[1]; i < n; ++i)
		if (a[i] < prize)
		{
			prize = a[i];
			stations.push_back(i);
		}
	stations.push_back(n);
	for (size_t i = 0; i + 1 < stations.size(); ++i)
	{
		int vs = 0;
		for (int j = stations[i]; j < stations[i + 1]; ++j)
			vs += v[j];
		int jyl = ((vs - jl) + (d - 1)) / d;
		// cout << stations[i] << ' ' << vs << ' ' << stations[i + 1] << ' ' << jyl << '\n';
		q += jyl * a[stations[i]];
		jl += d * jyl;
		jl -= vs;
	}
	cout << q << '\n';
}