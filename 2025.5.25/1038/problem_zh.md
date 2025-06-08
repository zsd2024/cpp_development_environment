1. 以补码存储的 $8$ 位有符号整数 $10110111$ 的十进制表示为
{{ select(1) }}
- $-73$
- $183$
- $-72$
- $72$

2. 现有一段 $24$ 分钟的视频文件，它的帧率是 $30 \text{ Hz}$，分辨率是  $1920\times1080$，每帧图像都是 $32$ 位真彩色图像，使用的视频编码算法达到了 $25\%$ 的压缩率。则这个视频文件占用的存储空间大小约是 
{{ select(2) }}
- 668GiB
- 334GiB
- 85GiB
- 500GiB

3. 链接器的功能是
{{ select(3) }}
- 把源代码转换成特定硬件平台的机器指令
- 把机器指令组合成完整的可执行程序
- 把源代码转换成可执行程序
- 把高级语言翻译成低级语言

4. 对一个 $n$ 个顶点，$m$ 条边的带正权有向简单图使用 Dijkstra 算法计算
单源最短路时，如果再使用一个可以在 $\Theta(\log n)$ 时间复杂度内查询堆内最
小值、在 $\Theta(\sqrt{n})$ 时间复杂度内合并两个堆、在 $\Theta(1)$ 时间复杂度内将堆内一个元素变小、在 $\Theta(\log n)$ 时间复杂度内弹出堆内最小值的堆优化 Dijkstra 算法，则整个 Dijkstra 算法的时间复杂度为
{{ select(4) }}
- $\Theta(n\sqrt{n} + m \log n)$
- $\Theta((n+m) \log n)$
- $\Theta(m + n \log n)$
- $\Theta(m\sqrt{n} + n \log n)$

5. 具有 $n$ 个顶点，$m$ 条边的连通图采用邻接矩阵存储结构，进行深度优先遍历运算的时间复杂度为
{{ select(5) }}
- $\Theta(n^3)$
- $\Theta(n^2)$
- $\Theta(n+m)$
- $\Theta(m^2)$

6. 下列算法中，没有运用分治思想的一项是
{{ select(6) }}
- 归并排序算法
- 求二叉树的前序遍历
- 快速排序算法
- 求二叉树的层次遍历

7. 前缀表达式 $\texttt{* + a b + c d}$ 的中缀形式是
{{ select(7) }}
- $\texttt{(a + b) * (c + d)}$
- $\texttt{a + b * c + d}$
- $\texttt{a * b + c * d}$
- $\texttt{(d + c) * (b + a)}$

8. 有 $5$ 个从 $1$ 到 $5$ 标号的小球和 $5$ 个同样标号的盒子，现将小球随机放入盒子，每个盒子仅放 $1$ 个小球，问每个盒子中的小球都与盒子标号不同的概率是
{{ select(8) }}
- $\dfrac{24}{625}$
- $\dfrac{7}{20}$
- $\dfrac{43}{120}$
- $\dfrac{11}{30}$

9. 设 x=true,y=false,z=true。以下逻辑运算表达式值为 true 的是
{{ select(9) }}
- $(\neg x \lor y) \land z$
- $(y \land z) \lor (x \land y)$
- $(x \land y) \lor z$
- $(x \land z) \land y$

10. 假设某算法的计算时间表示为递推关系式 $T(n)=3T(\dfrac{n}{2})+\Theta(n)$，$T(1)=\Theta(1)$，则算法的时间复杂度为
{{ select(10) }}
- $\Theta(n)$
- $\Theta(n^{\log_23})$
- $\Theta(n \log n)$
- $\Theta(n^{\log_23}\log n)$

11. 在一条长度为 $1$ 的线段上随机取一个点，再在以原线段的左端点和取的该点为端点的线段上随机取一个点，则以取的两个点为端点的线段的期望长度是
{{ select(11) }}
- $\dfrac{1}{2}$
- $\dfrac{1}{3}$
- $\dfrac{1}{4}$
- $\dfrac{2}{3}$

12. 以下排序算法中最好情况下时间复杂度与最坏情况下时间复杂度相同的是
{{ select(12) }}
- 选择排序
- 冒泡排序
- 插入排序
- 快速排序

13. 有 $4$ 个结点和 $4$ 条边的有标号简单无向图的数量是
{{ select(13) }}
- 15
- 16
- 6
- 4

14. 1946 年，（ ）提出了存储程序原理，奠定了现代电子计算机基本结构，开创了程序设计的新时代。
{{ select(14) }}
- 艾伦·麦席森·图灵（Alan Mathison Turing）
- 约翰·冯·诺依曼（John von Neumann）
- 克劳德·艾尔伍德·香农（Claude Elwood Shannon）
- 罗伯特·塔扬（Robert Tarjan）

15. 在计算机非专业级别软件能力认证 CSP-S 进行时，下列行为中被允许的是
{{ select(15) }}
- 使用 SSH 协议远程登录其它计算机以获取试题等文件
- 写程序在评测环境中修改输入文件
- 使用 U 盘拷贝题目及下发文件或自己的代码供赛后复盘
- 通过枚举输入文件的可能情况获得答案并写入源代码

16. **二、阅读程序（程序输入不超过数组或字符串定义的范围；判断题正确填 A，错误填 B；除特殊说明外，判断题 $2$ 分，选择题 $3$ 分，共计 $40$ 分）**

```cpp
#include <cstdio>
#include <cstring>

using namespace std;

char s[10000];
int cnt[26];

int main() {
	scanf("%s", s);
	for (int i = 0; i < strlen(s); ++i) {
		if (cnt[s[i] - 'a'] <= 50) {
			s[strlen(s)] = s[i];
		}
	++cnt[s[i] - 'a'];
	}
	printf("%s\n", s);
	return 0;
}
```

假设设初始时输入的字符串长度不超过 $500$，且不是空串。完成下面的判断题和单选题。

- 判断题

1) 将程序第 11 行中的 `++i` 改为 `i++`，程序运行结果不会改变（ ）
2) 将程序第 11 行改为 `for(int i=0,len=strlen(s);i<len;++i)`，
程序的运行结果不会改变，同时程序的运行效率将得到提升（ ）
3) 对于任意一个出现了 $\texttt a$ 到 $\texttt z$ 中所有的字符、且各字符出现的次数不小于 50 的字符串 $b$，总存在一个字符串 $a$，使得将字符串 $a$ 输入程序后的运行结果为字符串 $b$。（ ）
4) 程序的输出字符串长度一定不小于 $1300$（注：$1300=50\times 26$）。（ ）

- 单选题

5) 设输入字符串长度为 $x (1\leq x\leq 500)$，输出字符串长度为 $y$，则关于 $x$ 和 $y$ 的大小关系正确的是（ ）。     
A. 对于全部的输入字符串，都有 $x=y$。   
B. 对于全部的输入字符串，都有 $x<y$。   
C. 存在一部分输入字符串，使得 $x=y$；也存在一部分输入字符串，使得 $x<y$；但是不存在 $x>y$ 的情况。     
D. 存在一部分输入字符串，使得 $x=y$；也存在一部分输入字符串，使得 $x>y$；还存在一部分输入字符串，使得 $x<y$。

6) （$2$ 分）设字符串 $w$ 为 $\texttt{abcd...z}$，即从 $\texttt a$ 到 $\texttt z$ 在 $w$ 中依次出现一次，共 $26$ 个字符。若输入为 $w$ 重复出现两次的结果（即 $\texttt{abcdefg...zabcdefg...z}$，则输出结果为（ ）。    
A. $w$ 重复出现 50 次的结果。   
B. $w$ 重复出现 51 次的结果。    
C. $w$ 重复出现 52 次的结果。   
D. $w$ 重复出现 53 次的结果。    
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
- 正确
- 错误

{{ select(20) }}
- 对于全部的输入字符串，都有 $x=y$。
- 对于全部的输入字符串，都有 $x<y$。
- 存在一部分输入字符串，使得 $x=y$；也存在一部分输入字符串，使得 $x<y$；但是不存在 $x>y$ 的情况。
- 存在一部分输入字符串，使得 $x=y$；也存在一部分输入字符串，使得 $x>y$；还存在一部分输入字符串，使得 $x<y$。

{{ select(21) }}
- $w$ 重复出现 50 次的结果。
- $w$ 重复出现 51 次的结果。
- $w$ 重复出现 52 次的结果。
- $w$ 重复出现 53 次的结果。

17. ```cpp
#include <cstdio>
 
const int N = 5010;
const int M = 20010;
const int inf = 1073741823;

int e, bg[N], nx[M], to[M], wt[M];
inline void link(int u, int v, int w) {
    to[++e] = v;
    nx[e] = bg[u];
    wt[e] = w;
    bg[u] = e;
}

int n, m, u, v, w;
int f[N], h[N << 1];

void update(int x, int y) {
    x += n - 1;
    for (h[x] = y; x; x >>= 1)
        h[x >> 1] = f[h[x]] < f[h[x^1]] ? h[x] : h[x^1];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i != m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        link(u, v, w);
    }
    int nn = n << 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j != nn; ++j)
            h[j] = 0;
        for (int j = 0; j <= n; ++j)
            f[j] = inf;
        f[i] = 0;
        update(i, i);
        for (int j = i; true; j = h[1]) {
            if (f[j] == inf) break;
            for (int k = bg[j]; k; k = nx[k]) {
                if (f[j] + wt[k] < f[to[k]]) {
                    f[to[k]] = f[j] + wt[k];
                    update(to[k], to[k]);
                }
            }
            update(j, 0);
        }
        for (int j = 1; j <= n; ++j)
            printf("%d%c", f[j], "\n "[j != n]);
    }
    return 0;
}	
```

**以上程序的输入是一张带边权的有向图，完成下面的判断题和单选题。**

- 判断题

1) 将程序中所有的 `!=` 替换为 `<`，程序将仍然正常运行且输出的结
果不会改变。（ ）
2) 为了保证程序正常运行，输入的边数必须不大于 $2\times 10^4$。（ ）
3) 程序的输出是一个 $n\times n$ 的整数矩阵。（ ）
4) 将程序第 $34$ 行的 `j=0` 替换为 `j=1`，程序将仍然正常运行且输
出的结果不会改变。（ ）

- 单选题

5) （$2$ 分）当输入的图中所有边的边权均为一个相同的正整数，且有 $\sum w_i < 1073741823$ 时，`update` 函数被调用的次数为（ ）。

A. $\Theta(n^2)$   
B. $\Theta(nm)$   
C. $\Theta(n^2+nm)$   
D. $\Theta(n\min(n,m))$

6) 当输入的边权均为正整数时，程序在最坏情况下的时间复杂度为（ ）。

A. $\Theta(n^3)$   
B. $\Theta(n^2 \log n+nm)$    
C. $\Theta(nm \log n)$   
D. $\Theta(n^2m)$
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
- 正确
- 错误

{{ select(26) }}
- $\Theta(n^2)$
- $\Theta(nm)$
- $\Theta(n^2+nm)$
- $\Theta(n\min(n,m))$

{{ select(27) }}
- $\Theta(n^3)$
- $\Theta(n^2 \log n+nm)$
- $\Theta(nm \log n)$
- $\Theta(n^2m)$

18. ```cpp
#include <bits/stdc++.h>
using namespace std;

#define N 105
#define INF 1e9

int dis1[N][N], dis2[N][N];
int mp[N][N], n, m;

void fun1(int dis[N][N]) {
  static bool vis[N];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dis[i][j] = mp[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) vis[j] = 0;
    for (int k = 1; k <= n; k++) {
      int now = 0;
      for (int j = 1; j <= n; j++) {
        if (!vis[j] && (!now || dis[i][now] > dis[i][j]))
          now = j;
      }
      vis[now] = 1;
      for (int j = 1; j <= n; j++) {
        if(!vis[j]&&dis[i][j] > dis[i][now]+mp[now][j]){
          dis[i][j] = dis[i][now] + mp[now][j];
        }
      }
    }
  }
}
void fun2(int dis[N][N]) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dis[i][j] = mp[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) mp[i][j] = 0;
      else mp[i][j] = INF;
    }
  }
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    mp[u][v] = w;
  }
  fun1(dis1);
  fun2(dis2);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dis1[i][j] != dis2[i][j])
        ans++;
    }
  }
  cout << ans << endl;
  return 0;
}	
```

**以上程序的输入数据满足 $1 \leq n \leq 100,1 \leq m \leq \dfrac{n(n-1)}{2}$，且只保证不存在重边，即不存在 $(u_i,v_i)=(u_j,v_j)(i \neq j)$，边权 $w_i \in [1,10^6]$ 。如果 $u$ 到 $v$ 不可达，则认为距离为 $\texttt{INF}$ 。完成下面的判断题和单选题。**

- 判断题

1) 该代码的 $dis1[i][j]$ 不一定是 $i$ 到 $j$ 的最短路。（ ）
2) 输出**可能**为 $1$。（ ）
3) 将第 $19$ 行的 $k \leq n$ 修改为 $k < n$，不影响答案。(  )
4) 对于稀疏图（$n,m$ 不同阶），`fun1()` 对于单个 $i$ 求 $dis[i][j]
(1 \leq j \leq n)$，最快可以做到 $\Theta((n + m) \log m)$ 。(  )

- 单选题

5) 对于以下的输入数据，输出结果为（ ）    
``` 
5 8
3 2 2
2 4 2
1 4 3
3 1 2
4 3 3
5 2 3
1 5 1
1 2 2
``` 
A. 2   
B. 3   
C. 4   
D. 5  

6) 若输入数据 $n=5$ ，输出 $ans$ 的最大可能值为（ ）   
A. 4  
B. 5  
C. 6  
D. 7
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
- 正确
- 错误

{{ select(32) }}
- 2
- 3
- 4
- 5

{{ select(33) }}
- 4
- 5
- 6
- 7

19. **三、完善程序（单选题，每小题 $3$ 分，共计 $30$ 分）**

1.**（装备穿戴问题）** 有 $n$ 件装备，穿戴第 $i$ 件装备需要玩家的力量值至少为 $a_i$，穿戴该装备后会让玩家的力量值增加 $b_i$。现在请问玩家的初始力量值最小是多少，才能以某种顺序穿戴上所有的装备？    

输入：第一行是一个整数 $n(1 \leq n \leq 10^3)$；第二行有 $n$ 个整数，第 $i$ 个整数表示 $a_i(0 \leq a_i \leq 10^9)$；第三行有 $n$ 个整数，第 $i$ 个整数表示 $b_i(0 \leq b_i \leq 10^6)$。    

提示：使用二分+贪心的方法解决这个问题，先对装备按顺序进行排序，然后二分答案，并贪心地进行选择。    

试补全程序。  

```cpp

#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 1005;

int n;
int a[maxn], b[maxn], c[maxn];

bool Comp(const int &x, const int &y) { 
    // 你可以简单地认为括号内的内容等价于 (int x, int y)
    return ①;
}

bool check(int x) {
    for (int i = 1; i <= n; ++i) {
        int u = c[i];
        if (②) {
            x += b[u];
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) scanf("%d", b + i);
    for (int i = 1; i <= n; ++i) c[i] = i;
    sort(c + 1, c + 1 + n, Comp);
    int ans = 1145141919;
    for (int l=1, r=ans, mid=(l+r)/2; ③; mid=(l+r)/2)
        if (check(mid)) {
            ans = mid;
            ④;
        } else {
            ⑤;
        }
    printf("%d\n", ans);
    return 0;
}
```

1) ① 处应填（    ）。   
A. `a[x] > a[y]`	   
B. `a[x] < a[y]`  
C. `a[x] >= a[y]`	  
D. `a[x] <= a[y]`   

2) ② 处应填（    ）。    
A. `x < a[i]`   
B. `x < a[u]`   
C. `x >= a[i]`   
D. `x >= a[u]`   

3) ③ 处应填（    ）。         
A. `l < r`    
B. `l <= r`    
C. `check(l)`    
D. `check(r)`    

4) ④ 处应填（    ）。          
A. `r = mid - 1`    
B. `r = mid + 1`    
C. `l = mid - 1`    
D. `l = mid + 1`    

5) ⑤ 处应填（    ）。       
A. `r = mid - 1`    
B. `r = mid + 1`    
C. `l = mid - 1`    
D. `l = mid + 1`    
{{ select(34) }}
- `a[x] > a[y]`
- `a[x] < a[y]`
- `a[x] >= a[y]`
- `a[x] <= a[y]`  

{{ select(35) }}
- `x < a[i]`
- `x < a[u]`
- `x >= a[i]`
- `x >= a[u]`  

{{ select(36) }}
- `l < r`
- `l <= r`
- `check(l)`
- `check(r)` 

{{ select(37) }}
- `r = mid - 1`
- `r = mid + 1`
- `l = mid - 1`
- `l = mid + 1` 

{{ select(38) }}
- `r = mid - 1`
- `r = mid + 1`
- `l = mid - 1`
- `l = mid + 1`

20. 2. 小 A 最近喜欢上了一款音游，并希望在结算时得到特定分数，例如 $1919810$ 分。这款音游的得分计算方式如下：一共有 $n$ 个音符，将一千万（$10^7$）分平分给所有音符得到基础得分 $x=\dfrac{10^7}{n}$（保留非整数部分），其中有 $m$ 个音符根据是否击中可以获得 $x+1$ 分或者 $0$ 分，剩下的 $n-m$ 个音符根据击中精度可以获得 $x+1$，$x$，$\dfrac{x}{2}$，$0$ 分中的一个，最后将总得分向下取整即可得到最终得分。

给定 $n,m$，小 A 想知道他可以得到多少种不同的分数。

输入为两个非负整数，分别表示 $n,m$；满足，$1 \leq n \leq 10^7,0 \leq m \leq n$。输出为一个正整数表示答案。试补全程序。

```cpp
#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(m==n) {
        cout<<①<<endl;
        return 0;
    }
    long long M=10000000;
    int ans=②;
    int lst=0;
    for(int i=1;i<=n;++i) {
        for(int j=1;j>=0;--j) {
            int lower=max(0,③);
            int upper=i-j;
            int base=④;
            ans+=upper-lower+1;
            if(lower+base<=lst) ans-=lst-(lower+base)+1;
            lst=⑤;
        }
    }
    cout<<ans<<endl;
    return 0;
}
```

1) ① 处应填（    ）。    
A. `-1`    
B. `n-1`    
C. `n`    
D. `n+1`    

2) ② 处应填（    ）。   
A. `-1`   
B. `0`    
C. `1`     
D. `n`

3) ③ 处应填（    ）。    
A. `i - (n - m) - 1`    
B. `i - (n - m) - j`    
C. `i - (n - m)`    
D. `i - (n - m) + 1`     

4) ④ 处应填（    ）。    
A. `(2*i+j) * M / (2*n)`   
B. `(2*i-j) * M / (2*n)`    
C. `i * M / n + j * M / (2*n)`   
D. `i * M / n - j * M / (2*n)`    

5) ⑤ 处应填（    ）。    
A. `base + upper`     
B. `base + upper + 1`    
C. `base + lower`     
D. `base + lower + 1`    
{{ select(39) }}
- `-1`
- `n-1`
- `n`
- `n+1` 

{{ select(40) }}
- `-1`
- `0`
- `1`
- `n`

{{ select(41) }}
- `i - (n - m) - 1`
- `i - (n - m) - j`
- `i - (n - m)`
- `i - (n - m) + 1`   

{{ select(42) }}
- `(2*i+j) * M / (2*n)`
- `(2*i-j) * M / (2*n)`
- `i * M / n + j * M / (2*n)`
- `i * M / n - j * M / (2*n)`  

{{ select(43) }}
- `base + upper`
- `base + upper + 1`
- `base + lower`
- `base + lower + 1`    

