1. 32 位 int 类型的存储范围是（  ）？
{{ select(1) }}
- -2147483647 ~ +2147483647 
-  -2147483647 ~ +2147483648 
-  -2147483648 ~ +2147483647 
-  -2147483648 ~ +2147483648

2. 计算 $(14_8 - 1010_2) \times  D_{16} - 1101_2$ 的结果，并选择答案的十进制值：（  ）
{{ select(2) }}
- 13
- 14
- 15
- 16

3. 某公司有 $10$ 名员工，分为 $3$ 个部门：A 部门有 $4$ 名员工，B 部门有 $3$ 名员工，C 部门有 $3$ 名员工。现需要从这 $10$ 名员工中选出 $4$ 名组成一个工作小组，且每个部门至少要有 $1$ 人。问有多少种选择方式？（  ）
{{ select(3) }}
- 120
- 126
- 132
- 238

4. 以下哪个序列对应数字 $0$ 至 $8$ 的 $4$ 位二进制格雷码（Gray code）？（  ）
{{ select(4) }}
- 0000, 0001, 0011, 0010, 0110, 0111, 0101, 1000 
-  0000, 0001, 0011, 0010, 0110, 0111, 0100, 0101 
-  0000, 0001, 0011, 0010, 0100, 0101, 0111, 0110 
-  0000, 0001, 0011, 0010, 0110, 0111, 0101, 0100

5. 记 1KB 为 1024 字节（byte），1MB 为 1024KB，那么 1MB 是多少二进制位（bit）？（  ）
{{ select(5) }}
- 1000000 
-  1048576 
-  8000000 
-  8388608

6. 以下哪个不是 C++ 中的基本数据类型？（  ）
{{ select(6) }}
- int 
-  float 
-  struct 
-  char

7. 以下哪个不是 C++ 中的循环语句？（  ）
{{ select(7) }}
- for 
-  while 
-  do-while 
-  repeat-until

8. 在 C/C++ 中，`(char)('a' + 13)` 与下面的哪一个值相等？（  ）
{{ select(8) }}
- 'm' 
-  'n' 
-  'z' 
-  'l'

9. 假设有序表中有 $1000$ 个元素，则用二分法查找元素 $X$ 最多需要比较（  ）次。
{{ select(9) }}
- 25 
-  10 
-  7 
-  1

10. 下面的哪一个不是操作系统名字？（  ）
{{ select(10) }}
- Notepad 
-  Linux 
-  Windows 
-  macOS

11. 在无向图中，所有顶点的度数之和等于（  ）。
{{ select(11) }}
- 图的边数 
-  图的边数的两倍 
-  图的顶点数 
-  图的顶点数的两倍

12. 已知二叉树的前序遍历为 $[A, B, D, E, C, F, G]$，中序遍历为 $[D, B, E, A, F, C, G]$，请问该二叉树的后序遍历结果是？（  ）
{{ select(12) }}
- $[D, E, B, F, G, C, A]$ 
-  $[D, E, B, F, G, A, C]$ 
-  $[D, B, E, F, G, C, A]$ 
-  $[D, B, E, F, G, A, C]$

13. 给定一个空栈，支持入栈和出栈操作。若入栈操作的元素依次是 $1\ 2\ 3\ 4\ 5\ 6$，其中 $1$ 最先入栈，$6$ 最后入栈，下面哪种出栈顺序是不可能的？（  ）
{{ select(13) }}
- 6 5 4 3 2 1 
-  1 6 5 4 3 2 
-  2 4 6 5 3 1 
-  1 3 5 2 4 6

14. 有 $5$ 个男生和 $3$ 个女生站成一排，规定 $3$ 个女生必须相邻。问有多少种不同的排列方式？（  ）
{{ select(14) }}
- $4320$ 种 
-  $5040$ 种 
-  $3600$ 种 
-  $2880$ 种

15. 编译器的主要作用是什么？（ ）
{{ select(15) }}
- 直接执行源代码 
-  将源代码转换为机器代码 
-  进行代码调试 
-  管理程序运行时的内存

16. ### 二、阅读程序（程序输入不超过数组或字符串定义的范围；判断题正确填 √，错误填 ⨉ ；除特殊说明外，判断题 1.5 分，选择题 3 分，共计 40 分）

### 第 1 题


```cpp
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int countPrimes(int n) {
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            count++;
        }
    }
    return count;
}

int sumPrimes(int n) {
    int sum = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int x;
    cin >> x;
    cout << countPrimes(x) << " " << sumPrimes(x) << endl;
    return 0;
}
```

### 判断题

1. 当输入为 $10$ 时，程序的第一个输出为 $4$ ，第二个输出为 $17$。（）
2. 若将 `isPrime(i)` 函数中的条件改为 `i<=n/2`，输入 $20$ 时， `countPrimes(20)` 的输出将变为 $6$。（）
3. `sumPrimes` 函数计算的是从 $2$ 到 $n$ 之间的所有素数之和。

### 单选题

1. 当输入为 $50$ 时，`sumPrimes(50)` 的输出为（  ）。
2. 如果将 `for (int i = 2; i * i <= n; i++)` 改为 `for (int i = 2; i <= n; i++)`，输入 $10$ 时，程序的输出（  ）。
{{ select(16) }}
- 正确 
-  错误

{{ select(17) }}
- 正确 
-  错误

{{ select(18) }}
- 正确 
-  错误

{{ select(19) }}
- 1060 
-  328 
-  381 
-  275

{{ select(20) }}
- 将不能正确计算 $10$ 以内素数个数及其和 
-  仍然输出 $4$ 和 $17$ 
-  输出 $3$ 和 $10$ 
-  输出结果不变，但运行时间更短

17. ### 第 2 题

```cpp
#include <iostream>
#include <vector>
using namespace std;

int compute(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n+1, 0);
    dp[1] = cost[0];
    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i-1], dp[i-2]) + cost[i-1];
    }
    return min(dp[n], dp[n-1]);
}

int main() {
    int n;
    cin >> n;
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    cout << compute(cost) << endl;
    return 0;
}
```

### 判断题

1. 当输入的 `cost` 数组为 $\{10, 15, 20\}$ 时，程序的输出为 $15$。（  ）
2. 如果将 `dp[i-1]` 改为 `dp[i-3]`，程序可能会产生编译错误。（  ）
3. 程序总是输出 `cost` 数组中最小的元素。（  ）

### 单选题

1. 当输入的 `cost` 数组为 $\{1, 100, 1, 1, 1, 100, 1, 1, 100, 1\}$ 时，程序的输出为（  ）。
2. 如果输入的 `cost` 数组为 $\{10, 15, 30, 5, 5, 10, 20\}$，程序的输出为（  ）。
3. 若将代码中的 `min(dp[i-1], dp[i-2]) + cost[i-1]` 修改为 `dp[i-1] + cost[i-2]`，输入 `cost` 数组为 $\{5, 10, 15\}$ 时，程序的输出为（  ）。
{{ select(21) }}
- 正确 
-  错误

{{ select(22) }}
- 正确 
-  错误

{{ select(23) }}
- 正确 
-  错误

{{ select(24) }}
- 6 
-  7 
-  8 
-  9

{{ select(25) }}
- 25 
-  30 
-  35 
-  40

{{ select(26) }}
- 10 
-  15 
-  20 
-  25

18. ### 第 3 题

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int customFunction(int a, int b) {
    if (b == 0) {
        return a;
    }
    return a + customFunction(a, b-1);
}

int main() {
    int x, y;
    cin >> x >> y;
    int result = customFunction(x, y);
    cout << pow(result, 2) << endl;
    return 0;
}

```

### 判断题
1. 当输入为 `2 3` 时，`customFunction(2, 3)` 的返回值为 $64$。（  ）
2. （本题为错题，请选择【正确】和【错误】获得对应分数）当 $b$ 为负数时，`customFunction(a, b)` 会陷入无限递归。（  ）
3. （本题为错题，请选择【正确】和【错误】获得对应分数）当 $b$ 的值越大，程序的运行时间越长。（  ）

### 单选题

1. 当输入为 `5 4` 时，`customFunction(5, 4)` 的返回值为（  ）。
2. 如果输入 `x=3` 和 `y=3`，则程序的最终输出为（  ）。
3. （4 分）若将 `customFunction` 函数改为 `return a + customFunction(a-1, b-1);`，并输入 `3 3`，则程序的最终输出为（  ）。
{{ select(27) }}
- 正确 
-  错误

{{ select(28) }}
- 正确 
-  错误

{{ select(29) }}
- 正确 
-  错误

{{ select(30) }}
- 5 
-  25 
-  250 
-  625

{{ select(31) }}
- 27 
-  81 
-  144 
-  256

{{ select(32) }}
- 9 
-  16 
-  25 
-  36

19. ### 三、完善程序（单选题，每小题 3 分，共计 30 分）

### 第 1 题

**（判断平方数）** 问题：给定一个正整数 $n$，希望判断这个数是否为完全平方数，即存在一个正整数 $x$，使得 $x$ 的平方为 $n$。

试补全程序。

```cpp
#include<iostream>
#include<vector>
using namespace std;

bool isSquare(int num) {
    int i = ___①___;
    int bound = ___②___;
    for (; i <= bound; ++i) {
        if (___③___) {
            return ___④___;
        }
    }
    return___⑤___;
}

int main() {
    int n;
    cin >> n;
    if (isSquare(n)) {
        cout << n << " is a square number" << endl;
    } else {
        cout << n << " is not a square number" << endl;
    }
    return 0;
}
```

1. ① 处应填（  ）  
A. `1`   
B. `2`   
C. `3`   
D. `4`  
2. ② 处应填（  ）  
A. `(int)floor(sqrt(num))-1`  
B. `(int)floor(sqrt(num))`   
C. `floor(sqrt(num/2))-1`   
D. `floor(sqrt(num/2))`  
3. ③ 处应填（  ）   
A. `num = 2 * i`   
B. `num == 2 * i`   
C. `num = i * i`    
D. `num == i * i`    
4. ④ 处应填（  ）（本题有多个可能选项）   
A. `num = 2 * i`    
B. `num == 2 * i`    
C. `true`   
D. `false`
5. ⑤ 处应填（  ）    
A. `num = i * i`    
B. `num != i * i`    
C. `true`     
D. `false`   
{{ select(33) }}
- `1` 
-  `2` 
-  `3` 
-  `4`

{{ select(34) }}
- `(int)floor(sqrt(num))-1` 
-  `(int)floor(sqrt(num))` 
-  `floor(sqrt(num/2))-1` 
-  `floor(sqrt(num/2))`

{{ select(35) }}
- `num = 2 * i` 
-  `num == 2 * i` 
-  `num = i * i` 
-  `num == i * i` 

{{ select(36) }}
- `num = 2 * i` 
-  `num == 2 * i` 
-  `true` 
-  `false`

{{ select(37) }}
- `num = i * i` 
-  `num != i * i` 
-  `true` 
-  `false` 

20. ### 第 2 题

**（汉诺塔问题）** 给定三根柱子，分别标记为 A、B 和 C。初始状态下，柱子 A 上有若干个圆盘，这些圆盘从上到下按从小到大的顺序排列。任务是将这些圆盘全部移到柱子 C 上，且必须保持原有顺序不变。在移动过程中，需要遵守以下规则:
1. 只能从一根柱子的顶部取出圆盘，并将其放入另一根柱子的顶部。
2. 每次只能移动一个圆盘。
3. 小圆盘必须始终在大圆盘之上。

试补全程序。

```cpp
#include <iostream>
#include <vector>
using namespace std;

void move(char src, char tgt) {
    cout << "从柱子" << src << "挪到柱子" << tgt << endl;
}

void dfs(int i, char src, char tmp, char tgt) {
    if (i == ___①___) {
        move(___②___;
        return;
    }
    dfs(i - 1, ___③___);
    move(src, tgt);
    dfs(___⑤___, ___④___);
}

int main() {
    int n;
    cin >> n;
    dfs(n, 'A', 'B', 'C');
}
```

1. ① 处应填（  ）   
A. `0`   
B. `1`   
C. `2`   
D. `3`   
2. ② 处应填（  ）   
A. `src, tmp`   
B. `src, tgt`   
C. `tmp, tgt`   
D. `tgt, tmp`   
3. ③ 处应填（  ）   
A. `src, tmp, tgt`    
B. `src, tgt, tmp`   
C. `tgt, tmp, src`   
D. `tgt, src, tmp`
4. ④ 处应填（  ）   
A. `src, tmp, tgt`   
B. `tmp, src, tgt`   
C. `src, tgt, tmp`   
D. `tgt, src, tmp`
5. ⑤ 处应填（  ）   
A. `0`   
B. `1`   
C. `i - 1`   
D. `i`   
{{ select(38) }}
- `0` 
-  `1` 
-  `2` 
-  `3`

{{ select(39) }}
- `src, tmp` 
-  `src, tgt` 
-  `tmp, tgt` 
-  `tgt, tmp`

{{ select(40) }}
- `src, tmp, tgt` 
-  `src, tgt, tmp` 
-  `tgt, tmp, src` 
-  `tgt, src, tmp`

{{ select(41) }}
- `src, tmp, tgt` 
-  `tmp, src, tgt` 
-  `src, tgt, tmp` 
-  `tgt, src, tmp`

{{ select(42) }}
- `0` 
-  `1` 
-  `i - 1` 
-  `i`

