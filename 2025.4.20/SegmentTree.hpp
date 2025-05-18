#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP

#include <vector>
#include <functional>
#include <limits>

template <typename T, typename Tag = T>
class SegmentTree
{
private:
	std::vector<T> tree;	   // 存储节点值
	std::vector<Tag> tag;	   // 存储懒标记
	std::vector<bool> has_tag; // 标记是否有懒标记
	size_t n;				   // 原始数组长度

	// 操作函数
	std::function<T(const T &, const T &)> merge;						// 区间合并操作
	std::function<void(size_t, size_t, size_t, const Tag &)> apply_tag; // 应用懒标记
	std::function<void(Tag &, const Tag &)> merge_tag;					// 合并懒标记

	inline size_t ls(size_t x) { return x << 1; }	  // 左子节点
	inline size_t rs(size_t x) { return x << 1 | 1; } // 右子节点

	void push_up(size_t p)
	{
		tree[p] = merge(tree[ls(p)], tree[rs(p)]);
	}

	void push_down(size_t p, size_t l, size_t r)
	{
		if (!has_tag[p])
			return;
		size_t mid = (l + r) >> 1;

		// 将标记传递给子节点
		if (!has_tag[ls(p)])
		{
			has_tag[ls(p)] = true;
			tag[ls(p)] = tag[p];
		}
		else
		{
			merge_tag(tag[ls(p)], tag[p]);
		}
		if (!has_tag[rs(p)])
		{
			has_tag[rs(p)] = true;
			tag[rs(p)] = tag[p];
		}
		else
		{
			merge_tag(tag[rs(p)], tag[p]);
		}

		// 更新子节点的值
		apply_tag(ls(p), l, mid, tag[p]);
		apply_tag(rs(p), mid + 1, r, tag[p]);

		// 清除当前节点的标记
		has_tag[p] = false;
	}

	void build(const std::vector<T> &arr, size_t p, size_t l, size_t r)
	{
		if (l == r)
		{
			tree[p] = arr[l - 1];
			return;
		}
		size_t mid = (l + r) >> 1;
		build(arr, ls(p), l, mid);
		build(arr, rs(p), mid + 1, r);
		push_up(p);
	}

	void update(size_t nl, size_t nr, const Tag &val, size_t p, size_t l, size_t r)
	{
		if (nl <= l && r <= nr)
		{
			if (!has_tag[p])
			{
				has_tag[p] = true;
				tag[p] = val;
			}
			else
			{
				merge_tag(tag[p], val);
			}
			apply_tag(p, l, r, val);
			return;
		}
		push_down(p, l, r);
		size_t mid = (l + r) >> 1;
		if (nl <= mid)
			update(nl, nr, val, ls(p), l, mid);
		if (nr > mid)
			update(nl, nr, val, rs(p), mid + 1, r);
		push_up(p);
	}

	T query(size_t ql, size_t qr, size_t p, size_t l, size_t r)
	{
		if (ql <= l && r <= qr)
			return tree[p];
		push_down(p, l, r);
		size_t mid = (l + r) >> 1;
		if (qr <= mid)
			return query(ql, qr, ls(p), l, mid);
		if (ql > mid)
			return query(ql, qr, rs(p), mid + 1, r);
		return merge(query(ql, qr, ls(p), l, mid),
					 query(ql, qr, rs(p), mid + 1, r));
	}

public:
	SegmentTree(size_t size,
				std::function<T(const T &, const T &)> merge_func,
				std::function<void(size_t, size_t, size_t, Tag &)> apply_func,
				std::function<void(Tag &, const Tag &)> merge_tag_func)
		: n(size), merge(merge_func), apply_tag(apply_func), merge_tag(merge_tag_func)
	{
		tree.resize(4 * size + 1);
		tag.resize(4 * size + 1);
		has_tag.resize(4 * size + 1, false);
	}

	void build(const std::vector<T> &arr)
	{
		if (arr.size() != n)
			throw std::runtime_error("Array size mismatch");
		build(arr, 1, 1, n);
	}

	void update(size_t left, size_t right, const Tag &val)
	{
		if (left > right || left < 1 || right > n)
			throw std::runtime_error("Invalid range");
		update(left, right, val, 1, 1, n);
	}

	T query(size_t left, size_t right)
	{
		if (left > right || left < 1 || right > n)
			throw std::runtime_error("Invalid range");
		return query(left, right, 1, 1, n);
	}
};

#endif // SEGMENT_TREE_HPP
