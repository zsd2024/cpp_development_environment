#include <bits/stdc++.h>
using namespace std;

int andd, orr; // 短路计数
string s;	   // 表达式输入

const int maxlen = 1e6 + 1;
int ac[maxlen], oc[maxlen]; // 深度对应最近 '&' 和 '|' 位置
int an[maxlen], on[maxlen]; // 每个字符当前深度最近运算符全局位置

// 计算子表达式 [l, r] 值
int calc(int l, int r)
{
	// 优先检查最外层 '|'
	if (on[r] >= l && s[on[r]] == '|')
	{
		int a = calc(l, on[r] - 1);
		if (a == 1)
		{
			cout << on[r] << ' ' << s.substr(l, r - l + 1) << '\n';
			orr++;
			return 1;
		}
		int b = calc(on[r] + 1, r);
		return a || b;
	}
	// 再检查最外层 '&'
	if (an[r] >= l && s[an[r]] == '&')
	{
		int a = calc(l, an[r] - 1);
		if (a == 0)
		{
			andd++;
			return 0;
		}
		int b = calc(an[r] + 1, r);
		return a && b;
	}
	// 括号剥离
	if (s[l] == '(' && s[r] == ')')
		return calc(l + 1, r - 1);
	// 基本情况：单字符
	return s[l] - '0';
}

int main()
{
	cin >> s;
	int depth = 0;
	// 预处理运算符位置
	for (int i = 0; i < (int)s.length(); ++i)
	{
		if (s[i] == '(')
			depth++;
		else if (s[i] == ')')
			depth--;
		else if (s[i] == '|')
			oc[depth] = i;
		else if (s[i] == '&')
			ac[depth] = i;
		on[i] = oc[depth];
		an[i] = ac[depth];
	}
	// 计算全表达式值并输出
	int result = calc(0, s.length() - 1);
	cout << result << "\n"
		 << andd << " " << orr;
	return 0;
}