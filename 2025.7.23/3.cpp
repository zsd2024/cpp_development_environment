#include <bits/stdc++.h>
using namespace std;
/// @brief ��������߼����ʽ
string s;
/// @brief andd ��ʾ���� a&b �ġ���·����orr ��ʾ���� a|b �ġ���·��
int andd, orr;
/// @brief and_dep[i] ��ʾ����� i �µ����һ����&����λ�ã�or_dep[i] ��ʾ����� i �µ����һ����|����λ��
int and_dep[1000001], or_dep[1000001];
/// @brief and_ch[i] ��ʾ�� s[i] ֮ǰ���һ����&����λ�ã�or_ch[i] ��ʾ�� s[i] ֮ǰ���һ����|����λ��
int and_ch[1000001], or_ch[1000001];
/// @brief ��ǰ���
int depth;
/// @brief ���㺯��
/// @param l Ҫ������ַ�������ʼλ��
/// @param r Ҫ������ַ�������λ��
/// @return �ַ��� s �� [l,r] ���ֵļ�����
bool calc(int l, int r)
{
	// ��Ѱ�����һ��������
	if (or_ch[r] > l /*ȷ���ڵ�ǰ��Χ��*/ && s[or_ch[r]] == '|' /*ȷ������Ĭ��ֵ 0*/)
	{
		// ������벿��
		int l_val = calc(l, or_ch[r] - 1);
		// ����·������
		if (l_val == true)
		{
			++orr;
			return true;
		}
		// �����Ұ벿��
		int r_val = calc(or_ch[r] + 1, r);
		// ֱ�Ӽ���
		return l_val || r_val;
	}
	// ��Ѱ�����һ��������
	if (and_ch[r] > l /*ȷ���ڵ�ǰ��Χ��*/ && s[and_ch[r]] == '&' /*ȷ������Ĭ��ֵ 0*/)
	{
		// ������벿��
		int l_val = calc(l, and_ch[r] - 1);
		// ����·������
		if (l_val == false)
		{
			++andd;
			return false;
		}
		// �����Ұ벿��
		int r_val = calc(and_ch[r] + 1, r);
		// ֱ�Ӽ���
		return l_val && r_val;
	}
	// ע����Ϊ���������ȼ����ߣ����ݹ��ǵ�����ģ����ݺ��ټ��㣩������Ӧ���Ȼ�����
	// ȥ���������
	if (s[l] == '(' && s[r] == ')')
		return calc(l + 1, r - 1);
	// ע�����ȥ�������������Ϊ������Ų�һ����һ�飬�磺
	// (1|0)&(0&1)
	// �������ȥ���ͻ��ɣ�
	// 1|0)&(0&1
	// ���ַ�����
	if (l == r)
		return (s[(l + r) / 2] == '1');
	// ����Ӧ�ò���ִ��
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	// ���룬û�пո����� getline
	cin >> s;
	for (size_t i = 0; i < s.size(); ++i)
	{
		switch (s[i])
		{
		// �������������
		case '(':
			++depth;
			break;
		// �����ż�С���
		case ')':
			--depth;
			break;
		// ���������㵱ǰ��ȵ����λ��
		case '&':
			and_dep[depth] = i;
			break;
		// ���»����㵱ǰ��ȵ����λ��
		case '|':
			or_dep[depth] = i;
			break;
		default:
			break;
		}
		// ���������㵱ǰ�ַ������λ��
		and_ch[i] = and_dep[depth];
		// ���»����㵱ǰ�ַ������λ��
		or_ch[i] = or_dep[depth];
	}
	// ���
	cout << calc(0, s.size() - 1) << '\n'
		 << andd << ' ' << orr << '\n';
}