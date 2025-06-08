1. 以下哪个是面向对象的高级语言(  ).
{{ select(1) }}
- 汇编语言
- C++ 
- FORTRAN    
- Basic

2. $1 \text{ TB}$ 代表的字节数量是(  ).
{{ select(2) }}
- $2$ 的 $10$ 次方    
-  $2$ 的 $20$ 次方   
-  $2$ 的 $30$ 次方   
-  $2$ 的 $40$ 次方

3. 二进制数 $00100100$ 和 $00010101$ 的和是(  ).
{{ select(3) }}
- 00101000   
- 001010100   
- 01000101   
- 00111001

4. TCP 协议属于哪一层协议(  ).
{{ select(4) }}
- 应用层   
- 传输层    
- 网络层   
- 数据链路层

5. 下列几个 32 位 IP 地址中，书写错误的是(  ).
{{ select(5) }}
- 162.105.128.27   
- 192.168.0.1   
- 256.256.129.1   
- 10.0.0.1

6. 在无向图中，所有顶点的度数之和是边数的(  )倍.
{{ select(6) }}
- 0.5   
- 1   
- 2   
- 4

7. 对长度为 $n$ 的有序单链表，若检索每个元素的概率相等，则顺序检索到表中任一元素的平均检索长度为(  ).
{{ select(7) }}
- $\dfrac{n}{2}$   
-  $\dfrac{n+1}{2}$   
-  $\dfrac{n-1}{2}$   
-  $\dfrac{n}{4}$

8. 编译器的主要功能是(  ).
{{ select(8) }}
- 将一种高级语言翻译成另一种高级语言
- 将源程序翻译成指令
- 将低级语言翻译成高级语言
- 将源程序重新组合

9. 二进制数 $111.101$ 所对应的十进制数是(  ).
{{ select(9) }}
- 5.625   
- 5.5   
- 6.125   
- 7.625

10. 若有变量 `int a, float x, y`, 且 `a=7`，`x=2.5`，`y=4.7`, 则表达式 `x+a%3*(int)(x+y)%2/4` 的值大约是(  ).
{{ select(10) }}
- 2.500000   
- 2.750000   
- 3.500000   
- 0.000000

11. 有以下结构体说明和变量定义，如图所示，指针 $p,q,r$ 分别指向一个链表中的三个续结点。  
![](http://luogu-ipic.oss-cn-shanghai.aliyuncs.com/youti/39.png)

```cpp
struct node {   
 int data;  
 struct node *next;    
} *p,*q,*r;
```

现要将 $q$ 和 $r$ 所指结点的先后位置交换，同时要保持链表的连续，以下程序段中错误的是(   )
{{ select(11) }}
- `q->next = r->next; p-> next = r; r->next = q;`
-  `p->next = r; q->next = r->next; r->next = q;` 
-  `q->next = r->next; r->next = q; p->next = r;` 
-  `r->next = q; q->next = r->next; p->next = r;`

12. 同时查找 $2n$ 个数中的最大值和最小值，最少比较次数为（   ）.
{{ select(12) }}
- $\dfrac{3(n-2)}{2}$   
-  $4n-2$   
-  $3n-2$   
-  $2n-2$

13. 设 $G$ 是有 $6$ 个结点的完全图，要得到一颗生成树，需要从 $G$ 中删去(  )条边.
{{ select(13) }}
- 6
- 9
- 10
- 15

14. 以下时间复杂度不是 $O(n^2)$ 的排序方法是(  ).
{{ select(14) }}
- 插入排序   
- 归并排序   
- 冒泡排序   
- 选择排序

15. 以下程序实现了找第二小元素的算法。输入时 $n$ 个不等的数构成的数组 $S$，输出 $S$ 中第二小的数 $\mathrm{SecondMin}$。在最坏的情况下，该算法需要做（   ）次比较。
```cpp
if ( S[1] < S[2] )
{
	FirstMin	= S[1];
	SecondMin	= S[2];
} else {
	FirstMin	= S[2];
	SecondMin	= S[1];
}
for ( i = 3; i <= n; i++ )
	if ( S[i] < SecondMin )
		if ( S[i] < FirstMin )
		{
			SecondMin	= FirstMin;
			FirstMin	= S[i];
		} else {
			SecondMin = S[i];
		}

```
{{ select(15) }}
- 2n   
- n-1   
- 2n-3   
- 2n-2

16. 若逻辑变量 $A$、$C$ 为真，$B$、$D$ 为假，以下逻辑运算表达式真的有(    ).
{{ select(16) }}
- (B∨C∨D)∨D∧A
- ((- A∧B)∨C)∧-B
- (A∧B)∨(C∧D∨-A)
- A∧(D∨-C)∧B

17. 下列(    )软件属于操作系统软件。
{{ select(17) }}
- Microsoft Word
- Windows XP
- Android
- Mac OS X
- Oracle

18. 在 NOI 比赛中，对于程序设计题，选手提交的答案不得包含下列哪些内容（   ）。
{{ select(18) }}
- 试图访问网络
- 打开或创建题目规定的输入/输出文件之外的其他文件
- 运行其他程序
- 改变文件系统的访问权限
- 读写文件系统的管理信息

19. 以下哪些结构可以用来存储图(    ).
{{ select(19) }}
- 邻接矩阵  
- 栈    
- 邻接表   
- 二叉树

20. 下列各无符号十进制整数中，能用八位二进制表示的数有（    ）。
{{ select(20) }}
- 296   
- 133   
- 256   
- 199

21. 有数字 $1,1,2,4,8,8$ 所组成的不同的四位数的个数是_____.
{{ input(21) }}

22. 如图所示，图中每条边上的数字表示该边的长度，则从 $A$ 到 $E$ 的最短距离是_____.  
![](http://luogu-ipic.oss-cn-shanghai.aliyuncs.com/youti/40.png)
{{ input(22) }}

23. ```
#include <stdio.h>
int main()
{
	int a, b, i, tot, c1, c2;
	scanf( "%d%d", &a, &b );
	tot = 0;
	for ( i = a; i <= b; i++ )
	{
		c1	= i / 10;
		c2	= i % 10;
		if ( (c1 + c2) % 3 == 0 )
			tot++;
	}
	printf( "%d\n", tot );
	return(0);
}
```
输入：7   31  
输出：_________
{{ input(23) }}

24. ```
#include <stdio.h>
int fun( int n, int minNum, int maxNum )
{
	int tot, i;
	if ( n == 0 )
		return(1);
	tot = 0;
	for ( i = minNum; i <= maxNum; i++ )
		tot += fun( n - 1, i + 1, maxNum );
	return(tot);
}


int main()
{
	int n, m;
	scanf( "%d%d ", &n, &m );
	printf( "%d\n", fun( m, 1, n ) );
	return(0);
}
```
输入： 6    3  
输出：________
{{ input(24) }}

25. ```
#include <stdio.h>
#include <string.h>
const int	SIZE	= 100;
const int	LENGTH	= 25;
/*
 * strcmp(a,b) <0:a的字典序小于b
 * strcmp(a,b) =0:a和b一样
 * strcmp(a,b) >0:a的字典序大于b
 */
int main()
{
	char	dict[SIZE][LENGTH + 1];
	int	rank[SIZE];
	int	ind[SIZE];
	int	i, j, n, tmp;
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		rank [i]	= i;
		ind[i]		= i;
		scanf( "%s", dict[i] );
	}
	for ( i = 1; i < n; i++ )
		for ( j = 1; j <= n - i; j++ )
			if ( strcmp( dict[ind[j]], dict[ind[j + 1]] ) > 0 )
			{
				tmp		= ind[j];
				ind[j]		= ind[j + 1];
				ind[j + 1]	= tmp;
			}
	for ( i = 1; i <= n; i++ )
		rank[ind[i]] = i;
	for ( i = 1; i <= n; i++ )
		printf( "%d ", rank[i] );
	printf( "\n" );
	return(0);
}
```
输入：  
7  
aaa  
aba  
bbb  
aaa   
aaa  
ccc  
aa  
输出：______  
{{ input(25) }}

26. ```cpp
#include <cstdio>
const int	SIZE = 100;
int		alive[SIZE];
int		n;
int next( int num )
{
	do
	{
		num++;
		if ( num > n )
			num = 1;
	}
	while ( alive[num] == 0 );
	return(num);
}


int main()
{
	int m, i, j, num;
	scanf( "%d%d", &n, &m );
	for ( i = 1; i <= n; i++ )
		alive[i] = 1;
	num = 1;
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j < m; j++ )
			num = next( num );
		printf( "%d ", num );
		alive[num] = 0;
		if ( i < n )
			num = next( num );
	}
	printf( "\n" );
	return(0);
}
```
输入： 11     3  
输出：_________
{{ input(26) }}

27. （双栈模拟数组）只使用两个栈结构 $\mathrm{stack1}$ 和 $\mathrm{stack2}$，模拟对数组的随机读取。作为栈结构，$\mathrm{stack1}$ 和 $\mathrm{stack2}$ 只能访问栈顶（最后一个有效元素）。栈顶指针 $\mathrm{top1}$ 和 $\mathrm{top2}$ 均指向栈顶元素的下一个位置。

输入第一行包含的两个整数，分别是数组长度 $n$ 和访问次数 $m$，中间用单个空格隔开。

第二行包含 $n$ 个整数，一次给出数组各项（数组下标从 $0$ 到 $a-1$）。第三行包含 $m$ 个整数，需要访问的数组下标。对于每次访问，输出对应的数组元素。
```
#include <stdio.h>
const int	SIZE = 100;
int		stack1[SIZE], stack2[SIZE];
int		top1, top2;
int		n, m, i, j;
void clearStack()
{
	int i;
	for ( i = top1; i < SIZE; i++ )
		stack1[i] = 0;
	for ( i = top2; i < SIZE; i++ )
		stack2[i] = 0;
}


int main()
{
	scanf( "%d,%d", &n, &m );


	for ( i = 0; i < n; i++ )
		scanf( "%d", &stack1[i] );
	top1	= ______ （1）______;
	top2	= ______ （2）______;
	for ( j = 0; j < m; j++ )
	{
		scanf( "%d", &i );
		while ( i < top1 - 1 )
		{
			top1--;
			______( 3 ) ______;
			top2++;
		}
		while ( i > top1 - 1 )
		{
			top2--;
			______( 4 ) ______;
			top1++;
		}
		clearstack();
		printf( "%d\n", stack1[______( 5 ) ______] );
	}
	return(0);
}
```
{{ input(27) }}

{{ input(28) }}

{{ input(29) }}

{{ input(30) }}

{{ input(31) }}

28. 2.（最大矩阵和）给出 $M$ 行 $N$ 列的整数矩阵，就最大的子矩阵和（子矩阵不能为空）。

输入第一行包含两个整数 $M$ 和 $N$，即矩阵的行数和列数。之后 $M$ 行，每行 $N$ 个整数，描述整个矩阵。程序最终输出最大的子矩阵和。（第一空 $2$ 分，其余 $3$ 分，共 $14$ 分）
```
#include <stdio.h>
const int SIZE=100;
int matrix[SIZE+1][SIZE+1];
int rowsum[SIZE+1][SIZE+1];    //rowsum[i][j]记录第i行前j个数的和
int m,n,i,j,first,last,area,ans;
int main(){
   scanf(“%d %d”,&m,&n);
   for(i=1;i<=m;i++)
      for(j=1;j<=n;j++)
         scanf(“%d”,&matrix[i][j]);
ans=matrix     (1)     ;
for(i=1;i<=m;i++)
         (2)      ;
  for(i=1;i<=m;i++)
     for(j=1;j<=n;j++)
         rowsum[i][j]=     (3)     ;
  for(first=1;first<=n;first++)
     for(last=first;last<=n;last++){
             (4)     ;
       for(i=1;i<=m;i++){
           area+=     (5)     ;
           if(area>ans)
             ans=area;
           if(area<0)
             area=0;
       }
     }
  printf(“%d\n”,ans);
  return 0;
}
```
{{ input(32) }}

{{ input(33) }}

{{ input(34) }}

{{ input(35) }}

{{ input(36) }}

