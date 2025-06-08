1. 一个 $32$ 位整型变量占用（   ）个字节。 
{{ select(1) }}
- 4
- 8
- 32
- 128

2. 二进制数 $11.01$ 在十进制下是（   ）。 
{{ select(2) }}
- 3.25
- 4.125
- 6.25
- 11.125

3. 下面的故事与（   ）算法有着异曲同工之妙。  
从前有座山，山里有座庙，庙里有个老和尚在给小和尚讲故事：“从前有座山，山里有座庙，庙里有个老和尚在给小和尚讲故事：‘从前有座山，山里有座庙，庙里有个老和尚给小和尚讲故事……’”
{{ select(3) }}
- 枚举
- 递归
- 贪心
- 分治

4. 1948 年，（   ）将热力学中的熵引入信息通信领域，标志着信息论研究的开端。 
{{ select(4) }}
- 冯·诺伊曼（John von Neumann） 
- 图灵（Alan Turing） 
- 欧拉（Leonhard Euler） 
- 克劳德·香农（Claude Shannon）

5. 已知一棵二叉树有 $2013$ 个节点，则其中至多有（   ）个节点有 $2$ 个子节点。 
{{ select(5) }}
- 1006 
- 1007
- 1023 
- 1024

6. 在一个无向图中，如果任意两点之间都存在路径相连，则称其为连通图。右图是一个有 $5$ 个顶点、$8$ 条边的连通图。若要使它不再是连通图，至少要删去其中的（   ）条边。   
![](http://luogu-ipic.oss-cn-shanghai.aliyuncs.com/youti/34.png)
{{ select(6) }}
- 2
- 3
- 4
- 5

7. 斐波那契数列的定义如下：$F_1 = 1, F_2 = 1, F_n = F_{n - 1} + F_{n - 2} (n \geq 3)$。如果用下面的函数计算斐波那契数列的第 $n$ 项，则其时间复杂度为（   ）。 
```cpp
int F(int n) 
{ 
 if (n <= 2) 
  return 1; 
 else 
  return F(n - 1) + F(n - 2); 
}
```
{{ select(7) }}
- $O(1)$ 
- $O(n)$ 
- $O(n^2)$ 
- $O(F_n)$

8. 二叉查找树具有如下性质：每个节点的值都大于其左子树上所有节点的值、小于其右子 树上所有节点的值。那么，二叉查找树的（   ）是一个有序序列。 
{{ select(8) }}
- 先序遍历
- 中序遍历
- 后序遍历
- 宽度优先遍历

9. 将 $(2, 6, 10, 17)$ 分别存储到某个地址区间为 $0\sim 10$ 的哈希表中，如果哈希函数 $h(x) =$ （   ），将不会产生冲突，其中 $a \bmod b$ 表示 $a$ 除以 $b$ 的余数。 
{{ select(9) }}
- $x \bmod 11$
- $x^2 \bmod 11$
- $(2x) \bmod 11$
- $ \lfloor  \sqrt{x} \rfloor \bmod 11$，其中 $\lfloor  \sqrt{x} \rfloor $ 表示 $\sqrt{x} $ 下取整

10. IPv4 协议使用 32 位地址，随着其不断被分配，地址资源日趋枯竭。因此，它正逐渐被 使用（   ）位地址的 IPv6 协议所取代。 
{{ select(10) }}
- 40
- 48
- 64
- 128

11. 二分图是指能将顶点划分成两个部分，每一部分内的顶点间没有边相连的简单无向图。 那么，$12$ 个顶点的二分图至多有（   ）条边。
{{ select(11) }}
- 18
- 24
- 36
- 66

12. （   ）是一种通用的字符编码，它为世界上绝大部分语言设定了统一并且唯一的二进制编码，以满足跨语言、跨平台的文本交换。目前它已经收录了超过十万个不同字符。
 
{{ select(12) }}
- ASCII
- Unicode
- GBK 2312
- BIG5

13. 把 $64$ 位非零浮点数强制转换成 $32$ 位浮点数后，不可能（   ）。 
{{ select(13) }}
- 大于原数
- 小于原数
- 等于原数
- 与原数符号相反

14. 对一个 $n$ 个顶点、$m$ 条边的带权有向简单图用 Dijkstra 算法计算单源最短路时，如果不使用堆或其它优先队列进行优化，则其时间复杂度为（   ）。 
{{ select(14) }}
- $O(mn + n^3)$
- $O(n^2)$
- $O((m + n) \log n)$
- $O((m + n^2) \log n)$

15. $T(n)$ 表示某个算法输入规模为 $n$ 时的运算次数。如果 $T(1)$ 为常数，且有递归式 $T(n) = 2\times T(\dfrac{n}{2}) + 2n$，那么 $T(n) =$ （   ）。 
{{ select(15) }}
- $\Theta(n)$
-  $\Theta (n \log n)$ 
-  $\Theta(n^2)$ 
-  $\Theta(n^2 \log n)$

16. 下列程序中，正确计算 $1, 2,\dots, 100$ 这 $100$ 个自然数之和 $sum$（初始值为 $0$）的是（   ）。 
{{ select(16) }}
- `for (i = 1; i <= 100; i++)   sum += i;`
- `i = 1;   while (i > 100) {    sum += i;    i++;}`
- `i = 1;   do {    sum += i;    i++;     } while (i <= 100); `
- `i = 1;   do {    sum += i;    i++;   } while (i > 100);`

17. （   ）的平均时间复杂度为 $O(n \log n)$，其中 $n$ 是待排序的元素个数。 
{{ select(17) }}
- 快速排序
- 插入排序
- 冒泡排序
- 归并排序

18. 以 $A_0$ 作为起点，对下面的无向图进行深度优先遍历时（遍历的顺序与顶点字母的下标无关），最后一个遍历到的顶点可能是（   ）。   
![](http://luogu-ipic.oss-cn-shanghai.aliyuncs.com/youti/36.png)
{{ select(18) }}
- $A_1$
- $A_2$
- $A_3$
- $A_4$

19. （   ）属于 NP 类问题。 
{{ select(19) }}
- 存在一个 P 类问题
- 任何一个 P 类问题
- 任何一个不属于 P 类的问题
- 任何一个在（输入规模的）指数时间内能够解决的问题

20. CCF NOIP 复赛考试结束后，因（   ）提出的申诉将不会被受理。 
{{ select(20) }}
- 源程序文件名大小写错误
- 源程序保存在指定文件夹以外的位置
- 输出文件的文件名错误
- 只提交了可执行文件，未提交源程序

21. 某系统自称使用了一种防窃听的方式验证用户密码。密码是 $n$ 个数 $s_1, s_2,\dots , s_n$，均为 $0$ 或 $1$。该系统每次随机生成 $n$ 个数 $a_1, a_2, \dots , a_n$，均为 $0$ 或 $1$，请用户回答  $(s_1a_1 + s_2a_2 + \dots + s_na_n)$ 除以 $2$ 的余数。如果多次的回答总是正确，即认为掌握密码。该系统认为，即使问答的过程被泄露，也无助于破解密码——因为用户并没有直接发送密码。  

然而，事与愿违。例如，当 $n = 4$ 时，有人窃听了以下 $5$ 次问答：  
![](http://luogu-ipic.oss-cn-shanghai.aliyuncs.com/youti/13.png)  
就破解出了密码`s1 =___ ，s2 = ___，s3 =___ ，s4 =___`。  
**答案格式为：纯数字用`,`连接**

{{ input(21) }}

22. 现有一只青蛙，初始时在 $n$ 号荷叶上。当它某一时刻在 $k$ 号荷叶上时，下一时刻将等概 率地随机跳到 $1, 2, \dots, k$ 号荷叶之一上，直至跳到 $1$ 号荷叶为止。当 $n = 2$ 时，平均一共跳 $2$ 次；当 $n = 3$ 时，平均一共跳 $2.5$ 次。则当 $n = 5$ 时，平均一共跳_________次。    
![](http://luogu-ipic.oss-cn-shanghai.aliyuncs.com/youti/38.png)

**注意：如果你的答案要求输出分数，请输出 a/b 的形式，且保证为最简分数。**
{{ input(22) }}

23. ```
#include <stdio.h> 
#include <string.h> 
const int SIZE = 100; 
int main() { 
 int n, i, isPlalindrome; 
 char str[SIZE]; 
 scanf("%s", str); 
 n = strlen(str); 
 isPlalindrome = 1; 
 for (i = 0; i < n/2; i++) { 
  if (str[i] != str[n-i-1]) isPlalindrome = 0; 
 } 
 if (isPlalindrome) 
  printf("Yes\n"); 
 else 
  printf("No\n"); 
 return 0; 
} 
```
输入：abceecba   
输出：_________
{{ input(23) }}

24. ```
#include <stdio.h> 
int main() 
{ 
 int a, b, u, v, i, num;  
 scanf("%d%d%d%d", &a, &b, &u, &v); 
 num = 0; 
 for (i = a; i <= b; i++) 
if (((i % u) == 0) || ((i % v) == 0)) 
   num++; 
 printf("%d\n", num); 
 return 0; 
} 
```
输入：1 1000 10 15   
输出：_________
{{ input(24) }}

25. ```
#include <stdio.h> 
const int SIZE = 100; 
int main()  
{ 
 int height[SIZE], num[SIZE], n, ans; 
 int i, j; 
 scanf("%d", &n); 
 for (i = 0; i < n; i++) { 
  scanf("%d", &height[i]); 
  num[i] = 1; 
  for (j = 0; j < i; j++) { 
   if ((height[j] < height[i]) && (num[j] >= num[i]))  
    num[i] = num[j]+1; 
  } 
 } 
 ans = 0; 
 for (i = 0; i < n; i++) { 
  if (num[i] > ans) ans = num[i]; 
 } 
 printf("%d\n", ans); 
 return 0; 
} 
```
输入：   
8   
3 2 5 11 12 7 4 10   
输出：_________ 
{{ input(25) }}

26. ```
#include <stdio.h> 
#include <string.h> 
#define SIZE 100 
int n, m, p, count; 
int a[SIZE][SIZE]; 
void colour(int x, int y) 
{ 
 count++; 
 a[x][y] = 1; 
 if ((x > 1) && (a[x - 1][y] == 0)) 
  colour(x - 1, y); 
 if ((y > 1) && (a[x][y - 1] == 0)) 
  colour(x, y - 1); 
 if ((x < n) && (a[x + 1][y] == 0)) 
  colour(x + 1, y); 
 if ((y < m) && (a[x][y + 1] == 0)) 
  colour(x, y + 1);  
} 
int main() 
{ 
 int i, j, x, y, ans; 
 memset(a, 0, sizeof(a)); 
 scanf("%d%d%d", &n, &m, &p); 
 for (i = 1; i <= p; i++) { 
  scanf("%d%d", &x, &y); 
  a[x][y] = 1; 
 } 
 ans = 0;
for (i = 1; i <= n; i++) 
  for (j = 1; j <= m; j++) 
   if (a[i][j] == 0) { 
    count = 0; 
    colour(i, j); 
    if (ans < count) 
     ans = count; 
   } 
 printf("%d\n", ans); 
 return 0; 
} 
``` 
输入：   
6 5 9   
1 4   
2 3   
2 4   
3 2   
4 1   
4 3   
4 5   
5 4   
6 4  
输出：_________
{{ input(26) }}

27. （序列重排）全局数组变量 $a$ 定义如下： 
```
#define SIZE 100 
int a[SIZE], n; 
```
它记录着一个长度为 $n$ 的序列 $a_1,a_2,\dots,a_n$。 现在需要一个函数，以整数 $p(1 \leq p \leq n)$ 为参数，实现如下功能：将序列 $a$ 的前 $p$ 个数与后 $n - p$ 个数对调，且不改变这 $p$ 个数（或 $n - p$ 个数）之间的相对位置。例如， 长度为 $5$ 的序列 $1, 2, 3, 4, 5$，当 $p = 2$ 时重排结果为 $3, 4, 5, 1, 2$。 

有一种朴素的算法可以实现这一需求，其时间复杂度为 $O(n)$、空间复杂度为 $O(n)$： 
```  
void swap1(int p) {
	int i, j, b[SIZE]; 
	for (i = 1; i <= p; i++)b[(1)] = a[i]; //（2 分） 
	for (i = p + 1; i <= n; i++)
		b[i - p] = a[i]; 
	for (i = 1; i <= n; i++)
		a[i] = b[i]; 
}
```
我们也可以用时间换空间，使用时间复杂度为 $O(n^2)$、空间复杂度为 $O(1)$的算法： 
``` 
void swap2(int p) {
	int i, j, temp; 
	for (i = p + 1; i <= n; i++) {
		temp = a[i]; 
		for (j = i; j >= (2); j--)//（2 分） 
			a[j] = a[j - 1]; (3) = temp; //（2 分） 
	}
}
``` 
事实上，还有一种更好的算法，时间复杂度为 $O(n)$、空间复杂度为 $O(1)$： 
``` 
void swap3(int p) {
	int start1, end1, start2, end2, i, j, temp; 
	start1 = 1; 
	end1 = p; 
	start2 = p + 1; 
	end2 = n; 
	while (true) {
		i = start1; 
		j = start2; 
		while ((i <= end1) && (j <= end2)) {
			temp = a[i]; 
			a[i] = a[j]; 
			a[j] = temp; 
			i++; 
			j++; 
		}
		if (i <= end1)
			start1 = i; 
		else if ((4)) {//（3 分）    
			start1 = (5); //（3 分）    
			end1 = (6); //（3 分） 
			start2 = j; 
		}
		else 
		break; 
	}
}
```
{{ input(27) }}

{{ input(28) }}

{{ input(29) }}

{{ input(30) }}

{{ input(31) }}

{{ input(32) }}

28. （两元序列）试求一个整数序列中，最长的仅包含两个不同整数的连续子序列。如有多 个子序列并列最长，输出任意一个即可。例如，序列 $\texttt{1 1 2 3 2 3 2 3 3 1 1 1 3 1}$ 中， 有两段满足条件的最长子序列，长度均为 $7$，分别用下划线和上划线标出。 
```
#include <stdio.h> 
int main() 
{ 
 const int SIZE = 100; 
 int n, i, j, a[SIZE], cur1, cur2, count1, count2, 
  ans_length, ans_start, ans_end;  //cur1, cur2 分别表示当前子序列中的两个不同整数  //count1, count2 分别表示 cur1, cur2 在当前子序列中出现的次数 
 scanf("%d", &n); 
 for (i = 1; i <= n; i++) 
  scanf("%d", &a[i]); 
 i = 1; 
 j = 1;  //i, j 分别表示当前子序列的首尾，并保证其中至多有两个不同整数 
 while ((j <= n) && (a[j] == a[i])) 
  j++; 
 cur1 = a[i]; 
 cur2 = a[j];  count1 =     (1)    ; //（3 分） 
 count2 = 1; 
 ans_length = j - i + 1; 
 while (j < n) { 
  j++; 
  if (a[j] == cur1) 
   count1++; 
  else if (a[j] == cur2) 
   count2++; 
  else {    if (a[j - 1] ==     (2)    ) { //（3 分） 
    while (count2 > 0) { 
     if (a[i] == cur1) 
      count1--; 
     else 
      count2--; 
     i++; 
    } 
    cur2 = a[j]; 
    count2 = 1; 
   } 
   else { 
    while (count1 > 0) { 
     if (a[i] == cur1)           (3)    ; //（2 分） 
     else           (4)    ; //（2 分） 
     i++;  
    }         (5)    ;   //（3 分） 
    count1 = 1; 
   } 
  } 
  if (ans_length < j - i + 1) { 
   ans_length = j - i + 1; 
   ans_start = i; 
   ans_end = j; 
  } 
 } 
 for (i = ans_start; i <= ans_end; i++) 
  printf("%d ", a[i]); 
 return 0; 
} 
```
{{ input(33) }}

{{ input(34) }}

{{ input(35) }}

{{ input(36) }}

{{ input(37) }}

