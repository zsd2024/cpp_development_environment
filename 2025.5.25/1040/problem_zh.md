1. ## 一、单项选择题（共 15 题，每题 2 分，共计 30 分；每题有且仅有一个正确选项）  
在 Linux 系统终端中，用于切换工作目录的命令为（  ）。
{{ select(1) }}
- ls
- cd
- cp
- all

2. 你同时用 time 命令和秒表为某个程序在单核 CPU 的运行计时。假如 time 命令的输出如下：
```pain
real   0m30.721s 
user   0m24.579s 
sys    0m6.123s
```
以下最接近秒表计时的时长为（ ）。
{{ select(2) }}
- 30s
- 24s
- 18s
- 6s

3. 若元素 a、b、c、d、e、f 依次进栈，允许进栈、退栈操作交替进行，但不允许连续三次退栈操作，则不可能得到的出栈序列是（  ）。
{{ select(3) }}
- dcebfa
- cbdaef
- bcaefd
- afedcb

4. 考虑对 n 个数进行排序，以下最坏时间复杂度低于 $O(n^2)$ 的排序方法是（  ）。
{{ select(4) }}
- 插入排序
- 冒泡排序
- 归并排序
- 快速排序

5. 假设在基数排序过程中，受宇宙射线的影响，某项数据异变为一个完全不同的值。请问排 序算法结束后，可能出现的最坏情况是（  ）。
{{ select(5) }}
- 移除受影响的数据后，最终序列是有序序列
- 移除受影响的数据后，最终序列是前后两个有序的子序列
- 移除受影响的数据后，最终序列是一个有序的子序列和一个基本无序的子序列
- 移除受影响的数据后，最终序列基本无序

6. 计算机系统用小端（Little Endian）和大端（Big Endian）来描述多字节数据的存储地 址顺序模式，其中小端表示将低位字节数据存储在低地址的模式、大端表示将高位字节数 据存储在低地址的模式。在小端模式的系统和大端模式的系统分别编译和运行以下 C++代码段表示的程序，将分别输出什么结果？（ ）

```
unsigned x = 0xDEADBEEF; 
unsigned char *p = (unsigned char *)&x; 
printf("%X", *p);
```

{{ select(6) }}
- EF、EF
- EF、DE
- DE、EF
- DE、DE

7. 一个深度为 5（根结点深度为 1）的完全 3 叉树，按前序遍历的顺序给结点从 1 开始编号，则第 100 号结点的父结点是第（  ）号。
{{ select(7) }}
- 95
- 96
- 97
- 98

8. 强连通图的性质不包括（ ）：
{{ select(8) }}
- 每个顶点的度数至少为 1
- 任意两个顶点之间都有边相连
- 任意两个顶点之间都有路径相连
- 每个顶点至少都连有一条边

9. 每个顶点度数均为 2 的无向图称为“2 正规图”。由编号为从 1 到 n 的顶点构成的所有 2 正规图，其中包含欧拉回路的不同 2 正规图的数量为（ ）。
{{ select(9) }}
- n!
- (n-1)!
- n!/2
- (n-1)!/2

10. 共有 8 人选修了程序设计课程，期末大作业要求由 2 人组成的团队完成。假设不区分每个团队内 2 人的角色和作用，请问共有多少种可能的组队方案。（ ）。
{{ select(10) }}
- 28
- 32
- 56
- 64

11. 小明希望选到形如“省 A·LLDDD ”的车牌号。车牌号在“·”之前的内容固定的 5 位号码中，前 2 位必须是大写英文字母，后 3 位必须是阿拉伯数字（L代表 A 至 Z，D 表示 0 至 9，两个 L 和三个 D 之间可能相同也可能不同）。请问总共有多少个可供选择的车牌号。（ ）
{{ select(11) }}
- 20280
- 52000
- 676000
- 1757600

12. 给定地址区间为 0~9 的哈希表，哈希函数为 h(x) = x % 10，采用线性探查的冲突解决策略（对于出现冲突情况，会往后探查第一个空的地址存储；若地址 9 冲突了则从地址 0 重新开始探查）。哈希表初始为空表，依次存储(71, 23, 73, 99, 44, 79, 89)后，请问 89 存储在哈希表哪个地址中。（ ）
{{ select(12) }}
- 9
- 0
- 1
- 2

13. 对于给定的 $n$，分析以下代码段对应的时间复杂度，其中最为准确的时间复杂度为（  ）。
```
int i, j, k = 0;
for (i = 0; i < n; i++) {
    for (j = 1; j < n; j*=2) {
        k = k + n / 2;
    }
}
```
{{ select(13) }}
- $O(n)$
- $O(n \log n)$
- $O(n\sqrt{n})$
- $O(n^2)$

14. 以比较为基本运算，在 n 个数的数组中找最大的数，在最坏情况下至少要做（ ）次运算。
{{ select(14) }}
- n/2
- n-1
- n
- n+1

15. ack 函数在输入参数“(2,2)”时的返回值为（）。
```
unsigned ack(unsigned m, unsigned n) {
    if (m == 0) return n + 1;
    if (n == 0) return ack(m - 1, 1);
    return ack(m - 1, ack(m, n - 1));
}
```
{{ select(15) }}
- 5
- 7
- 9
- 13

16. ## 二、阅读程序（程序输入不超过数组或字符串定义的范围；判断题正确填√，错误填×；除特殊说明外，判断题 1.5 分，选择题 3 分，共计 40 分）

### （1）
```
1  #include <iostream> 
2  #include <string> 
3  #include <vector> 
4  
5  using namespace std; 
6  
7  int f(const string &s, const string &t) 
8  { 
9      int n = s.length(), m = t.length(); 
10 
11     vector<int> shift(128, m + 1); 
12 
13     int i, j;
14 
15     for (j = 0; j < m; j++)
16         shift[t[j]] = m - j;
17 
18     for (i =0; i<= n - m; i += shift[s[i + m]]){
19         j =0;
20         while(j < m && s[i +j] == t[j]) j++;
21         if (j == m) return i;
22     }
23 
24     return -1;
25 }
26 
27 int main()
28 {
29     string a ,b;
30     cin >> a >> b;
31     cout << f(a, b) << endl;
32     return 0;
33 }
```
**假设输入字符串由 ASCII 可见字符组成，完成下面的判断题和单选题：**

**判断题**

1. （1 分）当输入为“abcde fg”时，输出为-1。
2. 当输入为“abbababbbab abab”时，输出为 4。
3. 当输入为“GoodLuckCsp2022 22”时，第 20 行的“j++”语句执行次数为 2。

**单选题**  

4. 该算法最坏情况下的时间复杂度为（  ）。  
5. **f(a, b)** 与下列（  ）语句的功能最**类似**。  
6. 当输入为“baaabaaabaaabaaaa aaaa”，第 20 行的“j++”语句执行次数为 （ ）。
{{ select(16) }}
- 正确
- 错误

{{ select(17) }}
- 正确
- 错误

{{ select(18) }}
- 正确
- 错误

{{ select(19) }}
- $O(n+m)$
- $O(n log m)$
- $O(m log n)$
- $O(nm)$

{{ select(20) }}
- a.find(b)
- a.rfind(b)
- a.substr(b)
- a.compare(b)

{{ select(21) }}
- 9
- 10
- 11
- 12

17. ### （2）
```
1  #include <iostream>
2  
3  using namespace std;
4  
5  const int MAXN = 105;
6  
7  int n, m, k, val[MAXN];
8  int temp[MAXN], cnt[MAXN];
9  
10 void init() 
11 {
12     cin >> n >> k;
13     for (int i = 0; i < n; i++) cin >> val[i];
14     int maximum = val[0];
15     for (int i = 1; i < n; i++)
16         if (val[i] > maximum) maximum = val[i];
17     m = 1;
18     while (maximum >= k) {
19         maximum /= k;
20         m++;
21     }
22 }
23 
24 void solve() 
25 {
26     int base = 1;
27     for (int i = 0; i < m; i++) {
28         for (int j = 0; j < k; j++) cnt[j] = 0;
29         for (int j = 0; j < n; j++) cnt[val[j] / base % k]++;
30         for (int j = 1; j < k; j++) cnt[j] += cnt[j - 1];
31         for (int j = n - 1; j >= 0; j--) {
32             temp[cnt[val[j] / base % k] - 1] = val[j];
33             cnt[val[j] / base % k]--;
34         }
35         for (int j = 0; j < n; j++) val[j] = temp[j];
36         base *= k;
37     }
38 }
39 
40 int main() 
41 {
42     init();
43     solve();
44     for (int i = 0; i < n; i++) cout << val[i] << ;
45     cout << endl;
46     return 0;
47 }
```
假设输入的 n 为不大于 100 的正整数，k 为不小于 2 且不大于 100 的正整数，val[i]在 int 表示范围内，完成下面的判断题和单选题：

**判断题**

1. 这是一个不稳定的排序算法。（ ）
2. 该算法的空间复杂度仅与 n 有关。（ ）
3. 该算法的时间复杂度为$O(m(n+k))$。（ ）

**单选题**

4. 当输入为“5 3 98 26 91 37 46”时，程序第一次执行到第 36 行，val[]数组的内容依次为（ ）。
5. 若 val[i]的最大值为 100，k 取（ ）时算法运算次数最少。
6. 当输入的 k 比 val[i]的最大值还大时，该算法退化为（ ）算法。
{{ select(22) }}
- 正确
- 错误

{{ select(23) }}
- 正确
- 错误

{{ select(24) }}
- 正确
- 错误

{{ select(25) }}
- 91 26 46 37 98
- 91 46 37 26 98
- 98 26 46 91 37
- 91 37 46 98 26

{{ select(26) }}
- 2
- 3
- 10
- 不确定

{{ select(27) }}
- 选择排序
- 冒泡排序
- 计数排序
- 桶排序

18. ### （3）
```
1  #include <iostream>
2  #include <algorithm>
3  
4  using namespace std;
5  
6  const int MAXL = 1000;
7  
8  int n, k, ans[MAXL];
9  
10 int main(void) 
11 {
12     cin >> n >> k;
13     if (!n) cout << 0 << endl;
14     else 
15     {
16         int m = 0;
17         while (n) 
18         {
19             ans[m++] = (n % (-k) + k) % k;
20             n = (ans[m - 1] - n) / k;
21         }
22         for (int i = m - 1; i >= 0; i--)
23             cout << char(ans[i] >= 10 ?
24                          ans[i] + 'A' - 10 :
25                          ans[i] + '0');
26         cout << endl;
27     }
28     return 0;
29 }
```
假设输入的 n 在 int 范围内，k 为不小于 2 且不大于 36 的正整数，完成下面的判断题和单选题：

**判断题**
1. 该算法的时间复杂度为$O(\log_k n)$。
2. 删除第 23 行的强制类型转换，程序的行为不变。
3. 除非输入的 n 为 0，否则程序输出的字符数为 $\lfloor \log_k|n|\rfloor+1$。

**单选题**

4. 当输入为“100 7”时，输出为（  ）。
5. 当输入为“-255 8”时，输出为（  ）。
6. 当输入为“1000000 19”时，输出为（  ）。
{{ select(28) }}
- 正确
- 错误

{{ select(29) }}
- 正确
- 错误

{{ select(30) }}
- 正确
- 错误

{{ select(31) }}
- 202
- 1515
- 244
- 1754

{{ select(32) }}
- 1400
- 1401
- 417
- 400

{{ select(33) }}
- BG939
- 87GIB
- 1CD428
- 7CF1B

19. ## 三 完善程序（单选题，每小题 3 分，共计 30 分）
**(1)（归并第 k 小）** 已知两个长度均为 n 的有序数组 a1 和 a2（均为递增序，但不保证严 格单调递增），并且给定正整数 k（1≤k≤2n），求数组 a1 和 a2 归并排序后的数组里 第 k 小的数值。

试补全程序。

```
#include <bits/stdc++.h>
using namespace std;

int solve(int *a1, int *a2, int n, int k) {
    int left1 = 0, right1 = n - 1;
    int left2 = 0, right2 = n - 1;
    while (left1 <= right1 && left2 <= right2) {
        int m1 = (left1 + right1) >> 1;
        int m2 = (left2 + right2) >> 1;
        int cnt = ①;
        if (②) {
            if (cnt < k) left1 = m1 + 1;
            else right2 = m2 - 1;
        } else {
            if (cnt < k) left2 = m2 + 1;
            else right1 = m1 - 1;
        }
    }
    if (③) {
        if (left1 == 0) {
            return a2[k - 1];
        } else {
            int x = a1[left1 - 1], ④;
            return std::max(x, y);
        } 
    } else {
            if (left2 == 0) {
                return a1[k - 1];
            } else {
                int x = a2[left2 - 1], ⑤;
                return std:: max(x, y);
            }
    }
}
```
①～⑤处应填（ ）
{{ select(34) }}
- (m1 + m2) * 2
- (m1 - 1) + (m2 - 1)
- m1 + m2
- (m1 + 1) + (m2 + 1)

{{ select(35) }}
- a1[m1] == a2[m2]
- a1[m1] <= a2[m2]
- a1[m1] >= a2[m2]
- a1[m1] != a2[m2]

{{ select(36) }}
- left1 == right1
- left1 < right1
- left1 > right1
- left1 != right1

{{ select(37) }}
- y = a1[k - left2 - 1]
- y = a1[k - left2]
- y = a2[k - left1 - 1]
- y = a2[k - left1]

{{ select(38) }}
- y = a1[k - left2 - 1]
- y = a1[k - left2]
- y = a2[k - left1 - 1]
- y = a2[k - left1]

20. **(2)（容器分水）** 有两个容器，容器 1 的容量为为 a 升，容器 2 的容量为 b 升；同时允许下列的三种操作，分别为： 

1. FILL(i)：用水龙头将容器 $i(i \in {1,2})$ 灌满水； 
2. DROP(i)：将容器 i 的水倒进下水道； 
3. POUR(i,j)：将容器 i 的水倒进容器 j（完成此操作后，要么容器 j 被灌满，要么容器 i 被清空）。 

求只使用上述的两个容器和三种操作，获得恰好 c 升水的最少操作数和操作序列。上述 a、b、c 均为不超过 100 的正整数，且 c≤max{a,b}。

试补全程序。

```
#include <bits/stdc++.h>
using namespace std;
const int N = 110;

int f[N][N];
int ans;
int a, b, c;
int init;

int dfs(int x, int y) {
    if (f[x][y] != init)
        return f[x][y];
    if (x == c || y == c)
        return f[x][y] = 0;
    f[x][y] = init - 1;
    f[x][y] = min(f[x][y], dfs(a, y) + 1);
    f[x][y] = min(f[x][y], dfs(x, b) + 1);
    f[x][y] = min(f[x][y], dfs(0, y) + 1);
    f[x][y] = min(f[x][y], dfs(x, 0) + 1);
    int t = min(a - x, y);
    f[x][y] = min(f[x][y], ①);
    t = min(x, b - y);
    f[x][y] = min(f[x][y], ②);
    return f[x][y];
}

void go(int x, int y) {
    if (③)
        return;
    if (f[x][y] == dfs(a, y) + 1) {
        cout << "FILL(1)" << endl;
        go(a, y);
    } else if (f[x][y] == dfs(x, b) + 1) {
        cout << "FILL(2)" << endl;
        go(x, b);
    } else if (f[x][y] == dfs(0, y) + 1) {
        cout << "DROP(1)" << endl;
        go (0, y);
    } else if (f[x][y] == dfs(x, 0) + 1) {
        cout << "DROP(2)" << endl;
        go(x, 0);
    } else {
        int t = min(a - x, y);
        if(f[x][y] == ④) {
            cout << "POUR(2,1)" << endl;
            go(x + t, y - t);
        } else {
            t = min(x, b - y);
            if (f[x][y] == ⑤) {
                cout << "POUR(1,2)" << endl;
                go(x - t, y + t);
            } else
                assert(0);
        }
    }
}

int main() {
    cin >> a >> b >> c;
    ans = 1 << 30;
    memset(f, 127, sizeof f);
    init = **f;
    if ((ans = dfs (0, 0)) == init - 1)
        cout << "impossible";
    else {
        cout << ans << endl;
        go (0, 0);
    }
}
```
①～⑤处应填（ ）
{{ select(39) }}
- dfs(x + t, y - t) + 1
- dfs(x + t, y - t) - 1
- dfs(x - t, y + t) + 1
- dfs(x - t, y + t) - 1

{{ select(40) }}
- dfs(x + t, y - t) + 1
- dfs(x + t, y - t) - 1
- dfs(x - t, y + t) + 1
- dfs(x - t, y + t) - 1

{{ select(41) }}
- x == c || y == c
- x == c && y == c
- x >= c || y >= c
- x >= c && y >= c

{{ select(42) }}
- dfs(x + t, y - t) + 1
- dfs(x + t, y - t) - 1
- dfs(x - t, y + t) + 1
- dfs(x - t, y + t) - 1

{{ select(43) }}
- dfs(x + t, y - t) + 1
- dfs(x + t, y - t) - 1
- dfs(x - t, y + t) + 1
- dfs(x - t, y + t) - 1

