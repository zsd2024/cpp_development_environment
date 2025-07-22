#include <bits/stdc++.h>
using namespace std;
struct comp
{
	unsigned char a, b, c, d;
	unsigned short e;
	bool operator==(comp com)
	{
		return a == com.a && b == com.b && c == com.c && d == com.d && e == com.e;
	}
} a[1001];
int n, wz;
void checks(string st, comp &com)
{
	regex reg(R"raw((0|(?:[1-9][0-9]*)).(0|(?:[1-9][0-9]*)).(0|(?:[1-9][0-9]*)).(0|(?:[1-9][0-9]*)):(0|(?:[1-9][0-9]*)))raw");
	std::smatch matches;
	if (regex_match(st, matches, reg))
	{
		int a = atoi(matches[1].str().c_str());
		int b = atoi(matches[2].str().c_str());
		int c = atoi(matches[3].str().c_str());
		int d = atoi(matches[4].str().c_str());
		int e = atoi(matches[5].str().c_str());
		if (a < 0 && a > 127)
		{
			cout << "ERR\n";
			return;
		}
		if (b < 0 && b > 127)
		{
			cout << "ERR\n";
			return;
		}
		if (c < 0 && c > 127)
		{
			cout << "ERR\n";
			return;
		}
		if (d < 0 && d > 127)
		{
			cout << "ERR\n";
			return;
		}
		if (e < 0 && e > 65535)
		{
			cout << "ERR\n";
			return;
		}
		com.a = a;
		com.b = b;
		com.c = c;
		com.d = d;
		com.e = e;
		for (int i = 1; i < wz; ++i)
			if (com == ::a[i])
			{
				cout << "FAIL\n";
				return;
			}
		cout << "OK\n";
	}
	else
		cout << "ERR\n";
}
void checkc(string st)
{
	comp com;
	regex reg(R"raw((0|(?:[1-9][0-9]*)).(0|(?:[1-9][0-9]*)).(0|(?:[1-9][0-9]*)).(0|(?:[1-9][0-9]*)):(0|(?:[1-9][0-9]*)))raw");
	std::smatch matches;
	if (regex_match(st, matches, reg))
	{
		int a = atoi(matches[1].str().c_str());
		int b = atoi(matches[2].str().c_str());
		int c = atoi(matches[3].str().c_str());
		int d = atoi(matches[4].str().c_str());
		int e = atoi(matches[5].str().c_str());
		if (a < 0 && a > 127)
		{
			cout << "ERR\n";
			return;
		}
		if (b < 0 && b > 127)
		{
			cout << "ERR\n";
			return;
		}
		if (c < 0 && c > 127)
		{
			cout << "ERR\n";
			return;
		}
		if (d < 0 && d > 127)
		{
			cout << "ERR\n";
			return;
		}
		if (e < 0 && e > 65535)
		{
			cout << "ERR\n";
			return;
		}
		com.a = a;
		com.b = b;
		com.c = c;
		com.d = d;
		com.e = e;
	}
	else
	{
		cout << "ERR\n";
		return;
	}
	for (int i = 1; i <= wz; ++i)
		if (com == a[i])
		{
			cout << i << '\n';
			return;
		}
	cout << "FAIL\n";
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		string st;
		cin >> st;
		if (st == "Server")
		{
			cin >> st;
			checks(st, a[++wz]);
		}
		else if (st == "Client")
		{
			cin >> st;
			++wz;
			checkc(st);
		}
		// cout << "a[" << wz << "]: " << '|' << (int)a[wz].a << '.' << (int)a[wz].b << '.' << (int)a[wz].c << '.' << (int)a[wz].d << ':' << (int)a[wz].e << '|' << '\n';
	}
}