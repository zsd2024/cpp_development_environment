#include <bits/stdc++.h>
using namespace std;

/// @brief 全局变量: T 表示测试用例数量，M 表示系数的绝对值上限
int T, M;

namespace worker
{
	/// @brief 分数结构体，用于表示有理数 p/q
	struct fs;

	/// @brief 创建并化简一个分数
	/// @param p 分子
	/// @param q 分母
	/// @return 化简并规范化符号后的分数对象
	fs yls(int p, int q);

	/// @brief 求两个整数的最大公约数(GCD)
	/// @param a 整数 a
	/// @param b 整数 b
	/// @return a 和 b 的最大公约数
	int gcd(int a, int b)
	{
		// 如果 b 为 0，最大公约数就是 a；否则递归计算 gcd(b, a % b)
		return b == 0 ? a : gcd(b, a % b);
	}

	/// @brief 分数结构体，包含分子和分母
	struct fs
	{
		/// @brief 分子
		int fz;
		/// @brief 分母
		int fm;

		/// @brief 分数相加运算符重载
		/// @param rhs 右侧加数分数
		/// @return 相加后化简的分数
		const fs operator+(const fs &rhs) const
		{
			// 十字相乘后再化简
			return yls(fz * rhs.fm + fm * rhs.fz, fm * rhs.fm);
		}
	};

	/// @brief 创建并化简一个分数，确保分母正，符号在分子
	/// @param p 分子
	/// @param q 分母
	/// @return 化简且规范化符号后的分数对象
	fs yls(int p, int q)
	{
		// 求分子分母的最大公约数
		int ys = gcd(p, q);
		// 同时除以最大公约数进行化简
		p /= ys;
		q /= ys;
		// 如果分母为负数，把负号移动到分子
		if (q < 0)
		{
			p = -p;
			q = -q;
		}
		// 返回一个 fs 分数对象
		return {p, q};
	}

	/// @brief 二次根式结果结构体
	struct gs
	{
		/// @brief 有理数部分 q1
		fs xs;
		/// @brief 根号内剩余整数 r
		int ghx;
	};

	/// @brief 对根号内的值进行平方因子提取并生成 gs 结构
	/// @param x 根号内原始值
	/// @param y 根号外的分母
	/// @return 提取平方因子后的二次根式结果，包含化简分数 xs 和剩余根号 ghx
	gs sqrt(int x, int y)
	{
		// zs: 可被提取的平方因子部分，fzs: 提取后剩余根号内值
		int zs = 1, fzs = x;
		// 从最大可能因子 ::sqrt(fzs) 向下寻找
		for (int i = ::sqrt(fzs); i >= 1; --i)
			if (fzs % (i * i) == 0)
			{
				// 找到最大的 i 使 i*i 能整除 fzs
				zs = i;
				fzs /= (i * i);
				break; // 提取完成后退出循环
			}
		// 返回提取后的分数部分 zs/y 和剩余根号内的值 fzs
		return {yls(zs, y), fzs};
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 读取测试用例数量 T 和系数绝对值上限 M
	cin >> T >> M;
	// 对每一个测试用例进行处理
	for (int t = 1; t <= T; ++t)
	{
		// 读取一元二次方程的系数 a, b, c
		int a, b, c;
		cin >> a >> b >> c;

		// 计算判别式 delta = b^2 - 4ac
		int delta = b * b - 4 * a * c;
		// 如果判别式小于 0，则无实数解
		if (delta < 0)
			cout << "NO\n";
		else
		{
			// x = -b/(2a) 的有理化简表示
			worker::fs x = worker::yls(-b, 2 * a);
			// 对 sqrt(delta)/(2a) 进行平方因子提取
			worker::gs y = worker::sqrt(delta, 2 * a);
			// 确保根式分数的分子为正
			y.xs.fz = abs(y.xs.fz);

			if (y.ghx == 1)
			{
				// 如果剩余根号值为 1，则整体为有理数
				worker::fs z = y.xs;  // 提取后的有理数部分
				worker::fs t = x + z; // 两部分相加
				if (t.fz == 0)		  // 结果为 0
					cout << "0\n";
				else if (t.fm == 1) // 整数
					cout << t.fz << '\n';
				else // 分数 p/q
					cout << t.fz << '/' << t.fm << '\n';
			}
			else if (y.ghx == 0)
			{
				// 如果剩余根号值为 0，则去掉根号部分，只保留 x
				if (x.fz == 0)
					cout << "0\n";
				else if (x.fm == 1)
					cout << x.fz << '\n';
				else
					cout << x.fz << '/' << x.fm << '\n';
			}
			else if (x.fz == 0)
			{
				// 如果 x 分子为 0，仅输出根号部分
				worker::fs t = y.xs; // 根号前的系数分数
				if (t.fz == 1)
				{
					if (t.fm == 1)
						cout << "sqrt(" << y.ghx << ")\n";
					else
						cout << "sqrt(" << y.ghx << ")/" << t.fm << '\n';
				}
				else
				{
					if (t.fz == 0)
						cout << "CSP-J 2023\n";
					else if (t.fz < 0)
					{
						if (t.fm == 1)
							cout << t.fz << "*sqrt(" << y.ghx << ")\n";
						else
							cout << t.fz << "*sqrt(" << y.ghx << ")/" << t.fm << '\n';
					}
					else // t.fz > 0
					{
						if (t.fm == 1)
							cout << t.fz << "*sqrt(" << y.ghx << ")\n";
						else
							cout << t.fz << "*sqrt(" << y.ghx << ")/" << t.fm << '\n';
					}
				}
			}
			else
			{
				// 一般情况，同时输出 x 和根号部分
				if (x.fm == 1)
					cout << x.fz;
				else
					cout << x.fz << '/' << x.fm;
				worker::fs t = y.xs; // 根号前的系数分数
				if (t.fz == 1)
				{
					if (t.fm == 1)
						cout << '+' << "sqrt(" << y.ghx << ")\n";
					else
						cout << '+' << "sqrt(" << y.ghx << ")/" << t.fm << '\n';
				}
				else
				{
					if (t.fz == 0)
						cout << "CSP-J 2023\n";
					else if (t.fz < 0)
					{
						if (t.fm == 1)
							cout << t.fz << "*sqrt(" << y.ghx << ")\n";
						else
							cout << t.fz << "*sqrt(" << y.ghx << ")/" << t.fm << '\n';
					}
					else // t.fz > 0
					{
						if (t.fm == 1)
							cout << '+' << t.fz << "*sqrt(" << y.ghx << ")\n";
						else
							cout << '+' << t.fz << "*sqrt(" << y.ghx << ")/" << t.fm << '\n';
					}
				}
			}
		}
	}
}
