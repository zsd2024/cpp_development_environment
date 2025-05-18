#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
unsigned long long n /*序列长度*/, m /*操作次数*/, a[MAXN + 1] /*序列内容*/;
long long t[MAXN * 4 + 1] /*节点值（区间最大值）*/, tag[MAXN * 4 + 1] /*节点标记（懒标记）*/, tag_set[MAXN * 4 + 1] /*区间赋值标记*/;
bool lazy_tag[MAXN * 4 + 1] /*区间加法标记*/, lazy_tag_set[MAXN * 4 + 1] /*区间赋值标记*/;

/// @brief 节点x的左子节点
/// @param x 节点编号
/// @return 节点x的左子节点编号
inline long long ls(long long x)
{
	// printf("ls(%lld)\n{\n", x);
	// printf("}\n");
	return x << 1;
}

/// @brief 节点x的右子节点
/// @param x 节点编号
/// @return 节点x的右子节点编号
inline long long rs(long long x)
{
	// printf("rs(%lld)\n{\n", x);
	// printf("}\n");
	return x << 1 | 1;
}

/// @brief 维护区间最大值
/// @param x 节点编号
void push_up(long long x)
{
	// printf("push_up(%lld)\n{\n", x);
	t[x] = max(t[ls(x)], t[rs(x)]);
	// printf("}\n");
}

/// @brief 建树
/// @param p 节点编号
/// @param l 区间左端点
/// @param r 区间右端点
void build(long long p, long long l, long long r)
{
	// printf("build(%lld, %lld, %lld)\n{\n", p, l, r);
	tag[p] = 0;
	tag_set[p] = 0;
	if (l == r) // 叶子节点
	{
		t[p] = a[l]; // 叶子节点的值等于序列上对应位置的值
		// printf("}\n");
		return;
	}
	long long mid = (l + r) >> 1; // 中间位置
	build(ls(p), l, mid);		  // 左子树
	build(rs(p), mid + 1, r);	  // 右子树
	push_up(p);					  // 更新父节点的值
								  // printf("}\n");
}

/// @brief 将区间[l,r]的值加上k（l,r刚好对应节点p的区间左、右端点）
/// @param p 节点编号
/// @param l 区间左端点
/// @param r 区间右端点
/// @param k 加上的值
inline void f(long long p, long long l, long long r, long long k)
{
	// printf("f(%lld, %lld, %lld, %lld)\n{\n", p, l, r, k);
	tag[p] += k;		// 记录懒标记
	lazy_tag[p] = true; // 记录懒标记
	t[p] += k;			// 更新节点值
						// printf("}\n");
}

/// @brief 将区间[l,r]的值赋值为k（l,r刚好对应节点p的区间左、右端点）
/// @param p 节点编号
/// @param l 区间左端点
/// @param r 区间右端点
/// @param k 赋值的值
inline void set_val(long long p, long long l, long long r, long long k)
{
	// printf("set_val(%lld, %lld, %lld, %lld)\n{\n", p, l, r, k);
	tag[p] = 0;				// 清空加法懒标记
	lazy_tag[p] = false;	// 清空加法懒标记
	tag_set[p] = k;			// 记录赋值懒标记
	lazy_tag_set[p] = true; // 记录赋值懒标记
	t[p] = k;				// 更新节点值
							// printf("}\n");
}

/// @brief 向下更新
/// @param p 节点编号
/// @param l 区间左端点
/// @param r 区间右端点
void push_down(long long p, long long l, long long r)
{
	// printf("push_down(%lld, %lld, %lld)\n{\n", p, l, r);
	long long mid = (l + r) >> 1; // 中间位置
	if (lazy_tag_set[p])		  // 如果有赋值懒标记
	{
		set_val(ls(p), l, mid, tag_set[p]);		// 左子树
		set_val(rs(p), mid + 1, r, tag_set[p]); // 右子树
		tag_set[p] = 0;							// 赋值懒标记清零
		lazy_tag_set[p] = false;				// 赋值懒标记清零
	}
	if (lazy_tag[p]) // 如果有加法懒标记
	{
		f(ls(p), l, mid, tag[p]);	  // 左子树
		f(rs(p), mid + 1, r, tag[p]); // 右子树
		tag[p] = 0;					  // 加法懒标记清零
		lazy_tag[p] = false;		  // 加法懒标记清零
	}
	// printf("}\n");
}

/// @brief 将区间[nl,nr]的值加上k
/// @param nl 区间左端点
/// @param nr 区间右端点
/// @param l 节点p的区间左端点
/// @param r 节点p的区间右端点
/// @param p 节点编号
/// @param k 加上的值
void update(long long nl, long long nr, long long l, long long r, long long p, long long k)
{
	//	cout<<nl<<' '<<nr<<' '<<l<<' '<<r<<'\n';
	// printf("update(%lld, %lld, %lld, %lld, %lld, %lld)\n{\n", nl, nr, l, r, p, k);
	if (nl <= l && r <= nr) // 区间[nl,nr]完全包含节点p的区间[l,r]
	{
		f(p, l, r, k);
		// printf("}\n");
		return; // 结束该层递归
	}
	push_down(p, l, r);						  // 向下更新
	long long mid = (l + r) >> 1;			  // 中间位置
	if (nl <= mid)							  // 区间[nl,nr]与节点p的区间[l,mid]有交集
		update(nl, nr, l, mid, ls(p), k);	  // 递归更新左子树
	if (nr > mid)							  // 区间[nl,nr]与节点p的区间[mid+1,r]有交集
		update(nl, nr, mid + 1, r, rs(p), k); // 递归更新右子树
	push_up(p);								  // 更新父节点的值
											  // printf("}\n");
}

/// @brief 将区间[nl,nr]的值赋值为k
/// @param nl 区间左端点
/// @param nr 区间右端点
/// @param l 节点p的区间左端点
/// @param r 节点p的区间右端点
/// @param p 节点编号
/// @param k 赋值的值
void update_set(long long nl, long long nr, long long l, long long r, long long p, long long k)
{

	// printf("update_set(%lld, %lld, %lld, %lld, %lld, %lld)\n{\n", nl, nr, l, r, p, k);
	if (nl <= l && r <= nr) // 区间[nl,nr]完全包含节点p的区间[l,r]
	{
		set_val(p, l, r, k); // 更新节点值
		// printf("}\n");
		return; // 结束该层递归
	}
	push_down(p, l, r);							  // 向下更新
	long long mid = (l + r) >> 1;				  // 中间位置
	if (nl <= mid)								  // 区间[nl,nr]与节点p的区间[l,mid]有交集
		update_set(nl, nr, l, mid, ls(p), k);	  // 递归更新左子树
	if (nr > mid)								  // 区间[nl,nr]与节点p的区间[mid+1,r]有交集
		update_set(nl, nr, mid + 1, r, rs(p), k); // 递归更新右子树
	push_up(p);									  // 更新父节点的值
												  // printf("}\n");
}

/// @brief 查询区间[nl,nr]的最大值
/// @param qx 区间左端点
/// @param qy 区间右端点
/// @param l 节点p的区间左端点
/// @param r 节点p的区间右端点
/// @param p 节点编号
/// @return 区间[nl,nr]的最大值
long long query(long long qx, long long qy, long long l, long long r, long long p)
{
	// printf("query(%lld, %lld, %lld, %lld, %lld)\n{\n", qx, qy, l, r, p);
	if (qx <= l && r <= qy) // 区间[qx,qy]完全包含节点p的区间[l,r]
	{
		// printf("}\n");
		return t[p]; // 直接返回节点值（区间最大值）
	}
	push_down(p, l, r);									  // 向下更新
	long long mid = (l + r) >> 1;						  // 中间位置
	long long res = LLONG_MIN;							  // 结果初始化为-9223372036854775808
	if (qx <= mid)										  // 区间[qx,qy]与节点p的区间[l,mid]有交集
		res = max(res, query(qx, qy, l, mid, ls(p)));	  // 递归查询左子树
	if (qy > mid)										  // 区间[qx,qy]与节点p的区间[mid+1,r]有交集
		res = max(res, query(qx, qy, mid + 1, r, rs(p))); // 递归查询右子树
	// printf("}\n");
	return res; // 返回结果
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (unsigned long long i = 1; i <= n; ++i)
		cin >> a[i];
	build(1, 1, n); // 建树
	for (unsigned long long i = 1; i <= m; ++i)
	{
		int op;
		cin >> op;
		if (op == 1) // 区间赋值操作
		{
			long long x, y, k;
			cin >> x >> y >> k;
			update_set(x, y, 1, n, 1, k);
		}
		else if (op == 2) // 区间加操作
		{
			long long x, y, k;
			cin >> x >> y >> k;
			update(x, y, 1, n, 1, k);
		}
		else if (op == 3) // 区间查询操作
		{
			long long x, y;
			cin >> x >> y;
			cout << query(x, y, 1, n, 1) << '\n';
		}
	}
	return 0;
}