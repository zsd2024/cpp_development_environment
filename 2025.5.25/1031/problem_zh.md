1. 若有定义：`int a=7; float x=2.5, y=4.7`，则表达式 `x+a%3*(int) (x+y)%2` 的值是：（）
{{ select(1) }}
- 0.000000
- 2.750000
- 2.500000
- 3.500000

2. 下列属于图像文件格式的有（）
{{ select(2) }}
- WMV
- MPEG
- JPEG
- AVI

3. 二进制数 $\text{11 1011 1001 0111}$ 和 $\text{01 0110 1110 1011}$ 进行按位或运算的结果是（）。

> 编者注：原题为“逻辑或”，但是根据题意应当是按位或。
{{ select(3) }}
-  $\text{11 1111 1101 1111}$
- $\text{11 1111 1111 1101}$
- $\text{10 1111 1111 1111}$
- $\text{11 1111 1111 1111}$

4. 编译器的功能是（）
{{ select(4) }}
- 将源程序重新组合
- 将一种语言（通常是高级语言）翻译成另一种语言（通常是低级语言）
- 将低级语言翻译成高级语言 
- 将一种编程语言翻译成自然语言

5. 设变量 $x$ 为 float 型且已赋值，则以下语句中能将 $x$ 中的数值保留到小数点后两位，并将第三位四舍五入的是（）

{{ select(5) }}
- `x= (x*100+0. 5)/100.0;`
- `x=(int) (x*100+0. 5)/100.0;` 
- `x=(x/100+0. 5）*100.0;`
- `x=x*100+0. 5/100. 0;`

6. 由数字 $1, 1, 2, 4, 8, 8$ 所组成的不同的 $4$ 位数的个数是（）。
{{ select(6) }}
- 104
- 102
- 98
- 100

7. 排序的算法很多，若按排序的稳定性和不稳定性分类，则（）是不稳定排序。
{{ select(7) }}
- 冒泡排序
- 直接插入排序
- 快速排序
- 归并排序

8. $G$ 是一个非连通无向图（没有重边和自环），共有 $28$ 条边，则该图至少有 （）个顶点。
{{ select(8) }}
- 10
- 9
- 11
- 8

9. 一些数字可以颠倒过来看，例如 $0,1,8$ 颠倒过来还是本身，$6$ 颠倒过来是  $9,9$ 颠倒过来看还是 $6$,其他数字颠倒过来都不构成数字。类似的，一些多位数也可以颠倒过来看，比如 $106$ 颠倒过来是 $901$。假设某个城市的车牌只有 $5$ 位数字，每一位都可以取 $0$ 到 $9$。请问这个城市有多少个车牌倒过来恰好还是原来的车牌，并且车牌上的 $5$ 位数能被 $3$ 整除？（）

{{ select(9) }}
- 40
- 25
- 30
- 20

10. —次期末考试，某班有 $15$ 人数学得满分，有 $12$ 人语文得满分，并且有 $4$ 人语、数都是满分，那么这个班至少有一门得满分的同学有多少人？（）。

{{ select(10) }}
- 23
- 21
- 20
- 22

11. 设 $A$ 和 $B$ 是两个长为 $n$ 的有序数组，现在需要将 $A$ 和 $B$ 合并成一个排好序的数组，问任何以元素比较作为基本运算的归并算法，在最坏情况下至少要做多少次比较？（）。

{{ select(11) }}
- $n^2$
-  $n \log n$
- $2n$
- $2n - 1$

12. 以下哪个结构可以用来存储图（）
{{ select(12) }}
- 栈
- 二叉树
- 队列
- 邻接矩阵

13. 以下哪些算法不属于贪心算法？（）
{{ select(13) }}
- Dijkstra 算法 
- Floyd 算法
- Prim 算法
- Kruskal 算法

14. 有一个等比数列，共有奇数项，其中第一项和最后一项分别是 $2$ 和 $118098$，中间一项是 $486$,请问以下哪个数是可能的公比？（）

{{ select(14) }}
- 5	
-  3	
-  4	
-  2

15. 正实数构成的数字三角形排列形式如图所示。第一行的数为 $a_{1,1}$；第二行的数从左到右依次为 $a_{2,1},a_{2,2}$，第 $n$ 行的数为$a_{n,1},a_{n,2},\dots,a_{n,n}$ 从 $a_{1,1}$ 开始，每一行的数 $a_{i,j}$ 只有两条边可以分别通向下一行的两个数 $a_{i+1,j}$ 和 $a_{i+1,j+1}$。用动态规划算法找出一条从 $a_{1,1}$ 向下通到 $a_{n,1},a_{n,2},\dots,a_{n,n}$ 中某个数的路径，使得该路径上的数之和最大。

![](https://cdn.luogu.com.cn/upload/image_hosting/3fp7zcmr.png)

令 $C[i][j]$ 是从 $a_{1,1}$ 到 $a_{i,j}$ 的路径上的数的最大和，并且 $C[i][0]=C[0][j]=0$，则 $C[i][j]=$ ( )。

{{ select(15) }}
- $\max\{C[i-1][j-1],C[i-1][j]\}+a_{i,j}$
- $C[i-1][j-1]+C[i-1][j]$
- $\max\{C[i-1][j-1],C[i-1][j]\}+1$
- $\max\{C[i][j-1],C[i-1][j]\}+a_{i,j}$

16. 二、阅读程序（程序输入不超过数组或字符串定义的范围；判断题正确填√错误填X；除特殊说明外，判断题 $1.5$ 分，选择题 $4$分，共计 $40$ 分）

1.
```
#include <cstdio>
using namespace std;
int n;
int a[100];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        if (i > 1 && a[i] < a[i - 1])
            ans = i;
        while (ans < n && a[i] >= a[ans + 1])
            ++ans;
        printf("%d\n", ans);
    }
    return 0;
}
```
- 判断题  
1) 	（1 分）第 16 行输出 $ans$ 时，$ans$ 的值一定大于 $i$。（）  
2) 	（1 分）程序输出的 $ans$ 小于等于 $n$。（）  
3) 	若将第 12 行的 `<` 改为 `!=`，程序输出的结果不会改变。（）  
4) 	当程序执行到第 16 行时，若 $ans - i> 2$，则 $a[i + 1] \leq a[i]$。 （）  

- 选择题

5) （3 分）若输入的 $a$ 数组是一个严格单调递增的数列, 此程序的时间复杂度（）   
6) 最坏情况下，此程序的时间复杂度是（）。
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
- $O(\log n)$
- $O(n^2)$
- $O(n\log n)$  
- $O(n)$

{{ select(21) }}
- $O(n^2)$
- $O(\log n)$
- $O(n)$
- $O(n\log n)$

17. 2.
```
#include <iostream>
using namespace std;

const int maxn = 1000;
int n;
int fa[maxn], cnt[maxn];

int getRoot(int v) {
    if (fa[v] == v) return v;
    return getRoot(fa[v]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        fa[i] = i;
        cnt[i] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        int a, b, x, y;
        cin >> a >> b;
        x = getRoot(a);
        y = getRoot(b);
        ans += cnt[x] * cnt[y];
        fa[x] = y;
        cnt[y] += cnt[x];
    }
    cout << ans << endl;
    return 0;
}
```  
- 判断题
1)	（1 分）输入的 $a$ 和 $b$ 值应在 $[0, n-1]$的范围内。（）
2)	（1 分）第 16 行改成 `fa[i] = 0;`，不影响程序运行结果。（）
3)	若输入的 $a$ 和 $b$ 值均在 $[0, n-1]$ 的范围内，则对于任意 $0\leq i<n$ 都有 $0 \leq fa[i] <n$ （）
4)	若输入的 $a$ 和 $b$ 值均在 $[0, n-1]$ 的范围内，则对于任意 $0\leq i<n$ 都有 $1 \leq cnt[i]\leq n$ （） 

- 选择题  
5)	当 $n$ 等于50时，若 $a,b$ 的值都在 $[0,49]$ 的范围内，且在第 $25$ 行时 $x$ 总是不等于 $y$，那么输出为（）。  
6)	此程序的时间复杂度是（）。
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
- $1276$
- $1176$
- $1225$
- $1250$

{{ select(27) }}
- $O(n)$
- $O(\log n)$
- $O(n^2)$
- $O(n\log n)$

18. 3. 

$t$ 是 $s$ 的子序列的意思是：从 $s$ 中删去若干个字符，可以得到 $t$；特别的，如果 $s=t$，那么 $t$ 也是 $s$ 的子序列；空串是任何串的子序列。例如：$\texttt{acd}$ 是 $\texttt{abcde}$ 的子序列，$\texttt{acd}$ 是 $\texttt{acd}$ 的子序列，但 $\texttt{adc}$ 不是 $\texttt{abcde}$ 的子序列。

$s[x..y]$ 表示 $s[x] \cdots s[y]$ 共 $y-x+l$ 个字符构成的字符串，若 $x>y$ 则 $s[x..y]$ 是空串。$t[x..y]$ 同理。
```
#include <iostream>
#include <string>
using namespace std;
const int max1 = 202;
string s, t;
int pre[max1], suf[max1];

int main() {
    cin >> s >> t;
    int slen = s.length(), tlen = t.length();

    for (int i = 0, j = 0; i < slen; ++i) {
        if (j < tlen && s[i] == t[j]) ++j;
        pre[i] = j; // t[0..j-1] 是 s[0..i] 的子序列
    }

    for (int  i = slen - 1 , j = tlen - 1; i >= 0; --i) {
        if(j >= 0 && s[i] == t [j]) --j;
        suf[i]= j; // t[j+1..tlen-1] 是 s[i..slen-1] 的子序列
    }

    suf[slen] = tlen -1;
    int ans = 0;
    for (int i = 0, j = 0, tmp = 0; i <= slen; ++i){
        while(j <= slen && tmp >= suf[j] + 1) ++j;
        ans = max(ans, j - i - 1);
        tmp = pre[i];
    }
    cout << ans << endl;
    return 0;
}
```
提示：

- $t[0\dots pre[i]-1]$ 是 $s[0\dots i]$ 的子序列；   
- $t[suf[i]+1\dots tlen-1]$ 是 $ s[i\dots slen-1]$ 的子序列。  

- 判断题   
1)	（1分）程序输出时，`suf` 数组满足：对任意 $0 \leq i < slen, suf[i] \leq suf[i + 1]$。 （）  
2)	（2分）当 $t$ 是 $s$ 的子序列时，输出一定不为 $0$。（）  
3)	（2分）程序运行到第 $23$ 行时，$j - i - 1$ 一定不小于 $0$。（）  
4)	（2分）当 $t$ 是 $s$ 的子序列时，`pre` 数组和 `suf` 数组满足：对任意 $0 \leq i < slen, pre[i] > suf[i + 1] + 1$。	（）  

- 选择题     
5)	若 `tlen=10`，输出为 $0$，则 $slen$ 最小为（）。   
6)	若 `tlen=10`，输出为 $2$，则 $slen$ 最小为（）。
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
- 10
- 12
- 0
- 1

{{ select(33) }}
- 0
- 10
- 12
- 1

19. 三、完善程序（单选题，每小题 $3$ 分，共计 $30$ 分）

1. （匠人的自我修养）

一个匠人决定要学习 $n$ 个新技术。要想成功学习一个新技术，他不仅要拥有一定的经验值，而且还必须要先学会若干个相关的技术。学会一个新技术之后，他的经验值会增加一个对应的值。给定每个技术的学习条件和习得后获得的经验值，给定他已有的经验值，请问他最多能学会多少个新技术。  

输入第一行有两个数，分别为新技术个数 $n(l\leq n\leq 10^3)$,以及己有经验值（$\le10^7$）。 
 
接下来 $n$ 行。第 $i$ 行的两个正整数，分别表示学习第 $i$ 个技术所需的最低经验值（$\le10^7$）,以及学会第i个技术后可获得的经验值（$\leq 10^7$) 

接下来 $n$ 行。第 $i$ 行的第一个数 $m_i$（$0\le m_i<n$），表示第 $i$ 个技术的相关技术数量。紧跟着 $m$ 个两两不同的数，表示第 $i$ 个技术的相关技术编号。 

输出最多能学会的新技术个数。  

下面的程序以 $O(n^2)$ 的时间复杂度完成这个问题，试补全程序。

```
#include<cstdio>
using namespace std;
const int maxn = 1001;

int n;
int cnt[maxn];
int child [maxn][maxn];
int unlock[maxn];
int threshold[maxn], bonus[maxn];
int points;
bool find(){
    int target = -1;
    for (int i = 1; i <= n; ++i)
        if(① && ②){
            target = i;
            break;
    }
    if(target == -1)
        return false;
    unlock[target] = -1;
    ③
    for (int i = 0; i < cnt[target]; ++i)
        ④
    return true;
}

int main(){
    scanf("%d%d", &n, &points);
    for (int i = 1; i <= n; ++i){
        cnt[i] = 0;
        scanf("%d%d", &threshold[i], &bonus[i]);
    }
    for (int i = 1; i <= n; ++i){
        int m;
        scanf("%d", &m);
        ⑤
        for (int j = 0; j < m; ++j){
            int fa;
            scanf("%d", &fa);
            child[fa][cnt[fa]] = i;
            ++cnt[fa];
        }
    }

    int ans = 0;
    while(find())
        ++ans;

    printf("%d\n", ans);
    return 0;
}
```

1)	①处应填（）  

2)	②处应填（）  
 
3)	③处应填（）  

4)	④处应填（）  

5)	⑤处应填（）  

{{ select(34) }}
- `unlock[i] <= 0` 
- `unlock[i] >= 0` 
- `unlock[i] == 0` 
- `unlock[i] == -1`

{{ select(35) }}
- `threshold[i] > points` 
-  `threshold[i] >= points` 
- `points > threshold[i]` 
- `points >= threshold[i]`

{{ select(36) }}
- `target = -1` 
-  `--cnt[target]` 
- `bonus[target] = 0` 
- `points += bonus[target]`

{{ select(37) }}
- `cnt[child[target][i]] -= 1` 
- `cnt[child[target][i]] = 0` 
- `unlock[child[target][i]] -= 1` 
- `unlock[child[target][i]] = 0`

{{ select(38) }}
- `unlock[i] = cnt[i]` 
- `unlock[i] = m` 
- `unlock[i] = 0` 
- `unlock[i] = -1`

20. 2. （取石子）

Alice 和 Bob 两个人在玩取石子游戏。他们制定了 $n$ 条取石子的规则，第 $i$ 条规则为：如果剩余石子的个数大于等于 $a[i]$ 且大于等于 $b[i]$，那么他们可以取走 $b[i]$ 个石子。他们轮流取石子。如果轮到某个人取石子，而他无法按照任何规则取走石子，那么他就输了。一开始石子有 $m$ 个。请问先取石子的人是否有必胜的方法？

输入第一行有两个正整数，分别为规则个数 $n(1<n<64)$, 以及石子个数 $m( \le 10^7)$。

接下来 $n$ 行。第 $i$ 行有两个正整数 $a[i]$ 和 $b[i]$。$(1 \le a[i] \le 10^7,1 \le b[i] \le 64)$。

如果先取石子的人必胜，那么输出 $\texttt{Win}$，否则输出 $\texttt{Loss}$。

提示：  

可以使用动态规划解决这个问题。由于 $b[i]$ 不超过 $64$ ,所以可以使用 $64$ 位无符号整数去压缩必要的状态。  

status 是胜负状态的二进制压缩，trans 是状态转移的二进制压缩。
   
试补全程序。
  
代码说明： 
 
`~` 表示二进制补码运算符，它将每个二进制位的 $0$ 变为 $1$、$1$ 变为 $0$;

而 `^` 表示二进制异或运算符，它将两个参与运算的数中的每个对应的二进制位一一进行比较，若两个二进制位相同，则运算结果的对应二进制位为 $0$ ,反之为 $1$。  

ull 标识符表示它前面的数字是 unsigned long long 类型。  

```
#include <cstdio>
#include<algorithm>
using namespace std;
const int maxn = 64;
int n, m;
int a[maxn], b[maxn];
unsigned long long status, trans;
bool win;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &a[i], &b[i]);
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            if (a[i] > a[j]){
                swap(a[i], a[j]);
                swap(b[i], b[j]);
            }
    status = ①;
    trans = 0;
    for(int i = 1, j = 0; i <= m; ++i){
        while (j < n && ②){
            ③;
            ++j;
        }
        win = ④;
        ⑤;
    }

    puts(win ? "Win" : "Loss");

    return 0;
}	
```

1)	①处应填（	)	  

2)	②处应填（	)	

3)	③处应填（	)	   

4)	④处应填（	)	 

5)	⑤处应填（	)	
{{ select(39) }}
- `0`
- `~0ull`
- `~0ull^1`
- `1`

{{ select(40) }}
- `a[j] < i`
- `a[j] == i` 
- `a[j] !=i` 
- `a[j]>1`

{{ select(41) }}
- `trans |=1ull << (b[j] - 1)` 
- `status |=1ull << (b[j] - 1)` 
- `status +=1ull << (b[j] - 1)` 
- `trans +=1ull << (b[j] - 1)`

{{ select(42) }}
- `~status| trans`
- `status & trans` 
- `status | trans`
- `~status & trans`

{{ select(43) }}
- `trans =status | trans ^ win` 
- `status = trans >> 1 ^ win` 
- `trans =status ^ trans | win` 
- `status = status << 1 ^ win`

