#include <bits/stdc++.h>
using namespace std;
/// @brief 带计算的逻辑表达式
string s;
/// @brief andd 表示形如 a&b 的“短路”，orr 表示形如 a|b 的“短路”
int andd, orr;
/// @brief and_dep[i] 表示在深度 i 下的最后一个“&”的位置，or_dep[i] 表示在深度 i 下的最后一个“|”的位置
int and_dep[1000001], or_dep[1000001];
/// @brief and_ch[i] 表示在 s[i] 之前最后一个“&”的位置，or_ch[i] 表示在 s[i] 之前最后一个“|”的位置
int and_ch[1000001], or_ch[1000001];
/// @brief 当前深度
int depth;
/// @brief 计算函数
/// @param l 要计算的字符串的起始位置
/// @param r 要计算的字符串结束位置
/// @return 字符串 s 中 [l,r] 部分的计算结果
bool calc(int l, int r)
{
	// 先寻找最后一个或运算
	if (or_ch[r] > l /*确保在当前范围内*/ && s[or_ch[r]] == '|' /*确保不是默认值 0*/)
	{
		// 计算左半部分
		int l_val = calc(l, or_ch[r] - 1);
		// “短路”处理
		if (l_val == true)
		{
			++orr;
			return true;
		}
		// 计算右半部分
		int r_val = calc(or_ch[r] + 1, r);
		// 直接计算
		return l_val || r_val;
	}
	// 再寻找最后一个与运算
	if (and_ch[r] > l /*确保在当前范围内*/ && s[and_ch[r]] == '&' /*确保不是默认值 0*/)
	{
		// 计算左半部分
		int l_val = calc(l, and_ch[r] - 1);
		// “短路”处理
		if (l_val == false)
		{
			++andd;
			return false;
		}
		// 计算右半部分
		int r_val = calc(and_ch[r] + 1, r);
		// 直接计算
		return l_val && r_val;
	}
	// 注：因为与运算优先级更高，而递归是倒序处理的（回溯后再计算），所以应该先或运算
	// 去除外层括号
	if (s[l] == '(' && s[r] == ')')
		return calc(l + 1, r - 1);
	// 注：最后去除外层括号是因为外层括号不一定是一组，如：
	// (1|0)&(0&1)
	// 如果最先去除就会变成：
	// 1|0)&(0&1
	// 单字符处理
	if (l == r)
		return (s[(l + r) / 2] == '1');
	// 这行应该不会执行
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	// 输入，没有空格，无需 getline
	cin >> s;
	for (size_t i = 0; i < s.size(); ++i)
	{
		switch (s[i])
		{
		// 左括号增加深度
		case '(':
			++depth;
			break;
		// 右括号减小深度
		case ')':
			--depth;
			break;
		// 更新与运算当前深度的最后位置
		case '&':
			and_dep[depth] = i;
			break;
		// 更新或运算当前深度的最后位置
		case '|':
			or_dep[depth] = i;
			break;
		default:
			break;
		}
		// 更新与运算当前字符的最后位置
		and_ch[i] = and_dep[depth];
		// 更新或运算当前字符的最后位置
		or_ch[i] = or_dep[depth];
	}
	// 输出
	cout << calc(0, s.size() - 1) << '\n'
		 << andd << ' ' << orr << '\n';
}