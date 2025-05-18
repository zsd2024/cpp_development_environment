#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
long long n /*序列长度*/, m /*模数*/, q /*操作次数*/, a[MAXN + 1] /*序列内容*/;
long long t[MAXN * 4 + 1] /*节点值(区间和)*/, 
         add_tag[MAXN * 4 + 1] /*加法懒标记*/,
         mul_tag[MAXN * 4 + 1] /*乘法懒标记*/;

// 更新节点值
void push_up(long long p) {
    t[p] = (t[p << 1] + t[p << 1 | 1]) % m;
}

// 初始化乘法懒标记为1
void build(long long p, long long l, long long r) {
    mul_tag[p] = 1;
    add_tag[p] = 0;
    if (l == r) {
        t[p] = a[l] % m;
        return;
    }
    long long mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    push_up(p);
}

// 给节点p打上乘法和加法标记
void push_tag(long long p, long long l, long long r, long long mul, long long add) {
    t[p] = (t[p] * mul + add * (r - l + 1)) % m;
    mul_tag[p] = mul_tag[p] * mul % m;
    add_tag[p] = (add_tag[p] * mul + add) % m;
}

// 向下传递懒标记
void push_down(long long p, long long l, long long r) {
    if (mul_tag[p] == 1 && add_tag[p] == 0) return;
    long long mid = (l + r) >> 1;
    push_tag(p << 1, l, mid, mul_tag[p], add_tag[p]);
    push_tag(p << 1 | 1, mid + 1, r, mul_tag[p], add_tag[p]);
    mul_tag[p] = 1;
    add_tag[p] = 0;
}

// 区间乘法
void update_mul(long long nl, long long nr, long long l, long long r, long long p, long long k) {
    if (nl <= l && r <= nr) {
        push_tag(p, l, r, k, 0);
        return;
    }
    push_down(p, l, r);
    long long mid = (l + r) >> 1;
    if (nl <= mid) update_mul(nl, nr, l, mid, p << 1, k);
    if (nr > mid) update_mul(nl, nr, mid + 1, r, p << 1 | 1, k);
    push_up(p);
}

// 区间加法
void update_add(long long nl, long long nr, long long l, long long r, long long p, long long k) {
    if (nl <= l && r <= nr) {
        push_tag(p, l, r, 1, k);
        return;
    }
    push_down(p, l, r);
    long long mid = (l + r) >> 1;
    if (nl <= mid) update_add(nl, nr, l, mid, p << 1, k);
    if (nr > mid) update_add(nl, nr, mid + 1, r, p << 1 | 1, k);
    push_up(p);
}

// 区间查询
long long query(long long nl, long long nr, long long l, long long r, long long p) {
    if (nl <= l && r <= nr) return t[p];
    push_down(p, l, r);
    long long mid = (l + r) >> 1, ans = 0;
    if (nl <= mid) ans = (ans + query(nl, nr, l, mid, p << 1)) % m;
    if (nr > mid) ans = (ans + query(nl, nr, mid + 1, r, p << 1 | 1)) % m;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> q >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    build(1, 1, n);
    
    while (q--) {
        long long op, x, y, k;
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            update_mul(x, y, 1, n, 1, k % m);
        } else if (op == 2) {
            cin >> x >> y >> k;
            update_add(x, y, 1, n, 1, k % m);
        } else {
            cin >> x >> y;
            cout << query(x, y, 1, n, 1) << '\n';
        }
    }
    return 0;
}