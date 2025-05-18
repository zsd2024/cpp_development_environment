#include <iostream>
#include <vector>
#include "SegmentTree.hpp"
using namespace std;

// 测试区间最大值和区间加
void test_max_add()
{
	cout << "测试区间最大值和区间加：" << endl;
	vector<long long> arr = {1, 3, 5, 7, 9, 11};

	// 创建线段树，用于维护区间最大值
	SegmentTree<long long> st(arr.size(),
							  // merge函数：取两个值的最大值
							  [](const long long &a, const long long &b)
							  { return max(a, b); },
							  // apply_tag函数：将区间每个数加上val
							  [&st](size_t p, size_t l, size_t r, const long long &val)
							  { st.tree[p] += val; },
							  // merge_tag函数：合并两个加法标记
							  [](long long &old_tag, const long long &new_tag)
							  { old_tag += new_tag; });

	// 建树
	st.build(arr);

	cout << "初始区间[1,6]最大值: " << st.query(1, 6) << endl;

	// 区间加操作：将区间[2,4]中的每个数加2
	st.update(2, 4, 2LL);
	cout << "将区间[2,4]中的每个数加2后，区间[1,6]最大值: " << st.query(1, 6) << endl;

	// 查询子区间
	cout << "区间[2,5]最大值: " << st.query(2, 5) << endl;
}

// 测试区间和和区间乘
void test_sum_multiply()
{
	cout << "\n测试区间和和区间乘：" << endl;
	vector<long long> arr = {1, 2, 3, 4, 5};

	// 创建线段树，用于维护区间和
	SegmentTree<long long> st(arr.size(),
							  // merge函数：求和
							  [](const long long &a, const long long &b)
							  { return a + b; },
							  // apply_tag函数：将区间每个数乘以val
							  [&st](size_t p, size_t l, size_t r, const long long &val)
							  { st.tree[p] *= val; },
							  // merge_tag函数：合并两个乘法标记
							  [](long long &old_tag, const long long &new_tag)
							  { old_tag *= new_tag; });

	// 建树
	st.build(arr);

	cout << "初始区间[1,5]和: " << st.query(1, 5) << endl;

	// 区间乘操作：将区间[2,4]中的每个数乘2
	st.update(2, 4, 2LL);
	cout << "将区间[2,4]中的每个数乘2后，区间[1,5]和: " << st.query(1, 5) << endl;

	// 查询子区间
	cout << "区间[2,4]和: " << st.query(2, 4) << endl;
}

int main()
{
	test_max_add();
	test_sum_multiply();
	return 0;
}
