#ifndef BINARY_INDEXED_TREE_H
#define BINARY_INDEXED_TREE_H

#include <vector>
#include <functional>
#include <cassert>

template <typename T, typename Operation = std::plus<T>>
class BinaryIndexedTree {
private:
    std::vector<T> tree;
    int size;
    Operation op;
    T identity;

public:
    // 构造函数
    BinaryIndexedTree(int n, T identity = T(), Operation op = Operation())
        : size(n), identity(identity), op(op) {
        tree.assign(n + 1, identity);
    }

    // 从数组初始化
    template <typename Container>
    BinaryIndexedTree(const Container& data, T identity = T(), Operation op = Operation())
        : BinaryIndexedTree(data.size() - 1, identity, op) {
        for (size_t i = 1; i < data.size(); ++i) {
            add(i, data[i]);
        }
    }

    // 更新单个位置：加上增量 delta
    void add(int index, T delta) {
        assert(index > 0 && index <= size);
        for (; index <= size; index += index & -index) {
            tree[index] = op(tree[index], delta);
        }
    }

    // 查询前缀和 [1, index]
    T get(int index) const {
        assert(index >= 0 && index <= size);
        T result = identity;
        for (; index > 0; index -= index & -index) {
            result = op(result, tree[index]);
        }
        return result;
    }

    // 更新单个位置：设置为新值
    void update(int index, T newValue) {
        assert(index > 0 && index <= size);
        T currentValue = get(index) - get(index - 1);
        add(index, newValue - currentValue);
    }

    // 重载赋值运算符，用于从数组初始化
    template <typename Container>
    BinaryIndexedTree& operator=(const Container& data) {
        assert(data.size() - 1 == size);
        tree.assign(size + 1, identity);
        for (size_t i = 1; i < data.size(); ++i) {
            add(i, data[i]);
        }
        return *this;
    }

    // 下标访问（只读）
    T operator[](int index) const {
        assert(index > 0 && index <= size);
        return get(index) - get(index - 1);
    }

    // 下标访问（可写）
    T& operator[](int index) {
        static T temp;
        temp = (*this)[index];
        return temp; // 返回临时变量，避免直接修改
    }
};

#endif // BINARY_INDEXED_TREE_H