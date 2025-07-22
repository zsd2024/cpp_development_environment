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
	{
		if (st[0] == '0' && isdigit(st[1]))
		{
			cout << "ERR\n";
			return;
		}
		int x = st.find(".");
		if (x == string::npos)
		{
			cout << "ERR\n";
			return;
		}
		int a = stoi(st.substr(0, x));
		if (a > 255)
		{
			cout << "ERR\n";
			return;
		}
		com.a = a;
		st.erase(0, x + 1);
	}

	{
		if (st[0] == '0' && isdigit(st[1]))
		{
			cout << "ERR\n";
			return;
		}
		int x = st.find(".");
		if (x == string::npos)
		{
			cout << "ERR\n";
			return;
		}
		int b = stoi(st.substr(0, x));
		if (b > 255)
		{
			cout << "ERR\n";
			return;
		}
		com.b = b;
		st.erase(0, x + 1);
	}

	{
		if (st[0] == '0' && isdigit(st[1]))
		{
			cout << "ERR\n";
			return;
		}
		int x = st.find(".");
		if (x == string::npos)
		{
			cout << "ERR\n";
			return;
		}
		int c = stoi(st.substr(0, x));
		if (c > 255)
		{
			cout << "ERR\n";
			return;
		}
		com.c = c;
		st.erase(0, x + 1);
	}

	{
		if (st[0] == '0' && isdigit(st[1]))
		{
			cout << "ERR\n";
			return;
		}
		int x = st.find(":");
		if (x == string::npos)
		{
			cout << "ERR\n";
			return;
		}
		int d = stoi(st.substr(0, x));
		if (d > 255)
		{
			cout << "ERR\n";
			return;
		}
		com.d = d;
		st.erase(0, x + 1);
	}

	{
		if (st[0] == '0' && isdigit(st[1]))
		{
			cout << "ERR\n";
			return;
		}
		int e = stoi(st);
		if (e > 65535)
		{
			cout << "ERR\n";
			return;
		}
		com.e = e;
	}

	for (int i = 1; i < wz; ++i)
		if (com == a[i])
		{
			cout << "FAIL\n";
			return;
		}
	cout << "OK\n";
}
void checkc(string st)
{
	comp com;
	{
		if (st[0] == '0' && isdigit(st[1]))
		{
			cout << "ERR\n";
			return;
		}
		int x = st.find(".");
		if (x == string::npos)
		{
			cout << "ERR\n";
			return;
		}
		int a = stoi(st.substr(0, x));
		if (a > 255)
		{
			cout << "ERR\n";
			return;
		}
		com.a = a;
		st.erase(0, x + 1);
	}

	{
		if (st[0] == '0' && isdigit(st[1]))
		{
			cout << "ERR\n";
			return;
		}
		int x = st.find(".");
		if (x == string::npos)
		{
			cout << "ERR\n";
			return;
		}
		int b = stoi(st.substr(0, x));
		if (b > 255)
		{
			cout << "ERR\n";
			return;
		}
		com.b = b;
		st.erase(0, x + 1);
	}

	{
		if (st[0] == '0' && isdigit(st[1]))
		{
			cout << "ERR\n";
			return;
		}
		int x = st.find(".");
		if (x == string::npos)
		{
			cout << "ERR\n";
			return;
		}
		int c = stoi(st.substr(0, x));
		if (c > 255)
		{
			cout << "ERR\n";
			return;
		}
		com.c = c;
		st.erase(0, x + 1);
	}

	{
		if (st[0] == '0' && isdigit(st[1]))
		{
			cout << "ERR\n";
			return;
		}
		int x = st.find(":");
		if (x == string::npos)
		{
			cout << "ERR\n";
			return;
		}
		int d = stoi(st.substr(0, x));
		if (d > 255)
		{
			cout << "ERR\n";
			return;
		}
		com.d = d;
		st.erase(0, x + 1);
	}

	{
		if (st[0] == '0' && isdigit(st[1]))
		{
			cout << "ERR\n";
			return;
		}
		int e = stoi(st);
		if (e > 65535)
		{
			cout << "ERR\n";
			return;
		}
		com.e = e;
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