#include <bits/stdc++.h>
using namespace std;
int andd /*与运算的“短路”*/, orr /*或运算的“短路”*/;
string s /*表达式*/;
const int maxlen = (int)1e6 + 1;
int ac[maxlen], oc[maxlen], an[maxlen], on[maxlen], r;
/// @brief 计算函数
/// @param l 表达式起始位置
/// @param r 表达式结束位置
/// @return 表达式的值
int calc(int l, int r)
{
	if (on[r] >= l && s[on[r]] == '|')
	{
		int a = calc(l, on[r] - 1);
		if (a == 1)
		{
			++orr;
			return 1;
		}
		else
		{
			int b = calc(on[r] + 1, r);
			return (a || b);
		}
	}
	if (an[r] >= l && s[an[r]] == '&')
	{
		int a = calc(l, an[r] - 1);
		if (a == 0)
		{
			++andd;
			return 0;
		}
		else
		{
			int b = calc(an[r] + 1, r);
			return (a && b);
		}
	}
	if (s[l] == '(' && s[r] == ')')
		return calc(l + 1, r - 1);
	else
		return s[l] - '0';
}
int main()
{
	cin >> s;
	int c = 0 /*括号深度*/;
	for (int i = 0; i < s.length(); ++i) // 遍历每个字符
	{
		if (s[i] == '(')
			++c;
		else if (s[i] == ')')
			--c;
		else if (s[i] == '|')
			oc[c] = i;
		else if (s[i] == '&')
			ac[c] = i;
		on[i] = oc[c];
		an[i] = ac[c];
	}
	r = calc(0, s.length() - 1);
	cout << r << '\n'
		 << andd << ' ' << orr;
}