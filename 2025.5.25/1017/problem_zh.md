1. $1 \text{ MB}$ 等于(	)。

{{ select(1) }}
- $10000$ 字节
- $1024$ 字节
-  $1000\times 1000$ 字节
-  $1024\times 1024$ 字节

2. 在 PC 机中，PENTIUM（奔腾）、酷睿、赛扬等 是指(	)。

{{ select(2) }}
- 生产厂家名称
- 硬盘的型号
- CPU 的型号
- 显示器的型号

3. 操作系统的作用是(	)。

{{ select(3) }}
- 把源程序译成目标程序
- 便于进行数据管理
- 控制和管理系统资源
- 实现硬件之间的连接

4. 在计算机内部用来传送、存贮、加工处理的数据或指令都是以(	)形式进行的。
{{ select(4) }}
- 二进制码
- 八进制码
- 十进制码
- 智能拼音码

5. 下列说法正确的是(	)。

{{ select(5) }}
- CPU 的主要任务是执行数据运算和程序控制
- 存储器具有记忆能力，其中信息任何时候都不会丢失
- 两个显示器屏幕尺寸相同，则它们的分辨率必定相同
- 个人用户只能使用 Wifi 的方式连接到 Internet

6. 二进制数 $00100100$ 和 $00010100$ 的和是(	)。
{{ select(6) }}
- $00101000$
- $01100111$
- $01000100$
- $00111000$

7. 与二进制小数 $0.1$ 相等的十六进制数是(	)。
{{ select(7) }}
- 0.8
- 0.4
- 0.2
- 0.1

8. 所谓的“中断”是指(	)。

{{ select(8) }}
- 操作系统随意停止一个程序的运行
- 当出现需要时，CPU 暂时停止当前程序的执行转而执行处理新情况的过程
- 因停机而停止一个程序的运行
- 电脑死机

9. 计算机病毒是(	)。

{{ select(9) }}
- 通过计算机传播的危害人体健康的一种病毒
- 人为制造的能够侵入计算机系统并给计算机带来故障的程序或指令集合
- 一种由于计算机元器件老化而产生的对生态环境有害的物质
- 利用计算机的海量高速运算能力而研制出来的用于疾病预防的新型病毒

10. FTP 可以用于(	)。

{{ select(10) }}
- 远程传输文件
- 发送电子邮件
- 浏览网页
- 网上聊天

11. 下面哪种软件不属于即时通信软件(	)。
{{ select(11) }}
- QQ
- MSN
- 微信
- P2P

12. $6$ 个顶点的连通图的最小生成树，其边数为(	)。
{{ select(12) }}
- 6
- 5
- 7
- 4

13. 链表不具备的特点是(	)。

{{ select(13) }}
- 可随机访问任何一个元素
- 插入、删除操作不需要移动元素
- 无需事物估计存储空间大小
- 所需存储空间与存储元素个数成正比

14. 线性表若采用链表存储结构，要求内存中可用存储单元地址(	)。
{{ select(14) }}
- 必须连续
- 部分地址必须连续
- 一定不连续
- 连续不连续均可

15. 今有一空栈 $S$，对下列待进栈的数据元素序列 $a,b,c,d,e,f$ 依次进行进栈，进栈，出栈，进栈， 进栈，出栈的操作，则此操作完成后，栈 $S$ 的栈顶元素为:

{{ select(15) }}
- f
- c
- a
- b

16. 前序遍历序列与中序遍历序列相同的二叉树为(	)。
{{ select(16) }}
- 根结点无左子树
- 根结点无右子树
- 只有根结点的二叉树或非叶子结点只有左子树的二叉树
- 只有根结点的二叉树或非叶子结点只有右子树的二叉树

17. 如果根的高度为 $1$，具有 $61$ 个结点的完全二叉树的高度为（   ）。
{{ select(17) }}
- 5
- 6
- 7
- 8

18. 下列选项中不属于视频文件格式的是(	)。
{{ select(18) }}
- TXT
- AVI
- MOV
- RMVB

19. 某算法的计算时间表示为递推关系式 $T(n)=T(n-1)+n$（$n$ 为正整数）及 $T(0)=1$，则该算法的时间复杂度为(	)。

{{ select(19) }}
- $O(\log n)$
- $O(n\log n)$
- $O(n)$
- $O(n^{2})$

20. 在 NOI 系列赛事中参赛选手必须使用累承办单位统一提供的设备。下列物品中不允许选手自带的是( )。

{{ select(20) }}
- 鼠标
- 笔
- 身份证
- 准考证

21. 重新排列 $1234$ 使得每一个数字都不在原来的位置上，一共有__种排法。
{{ input(21) }}

22. 一棵结点数为 $2015$ 的二叉树最多有___个叶子结点。
{{ input(22) }}

23. **阅读程序写结果：**  
```
#include <iostream> 
using namespace std;
int main() 
{
    int a, b, c; a = 1;
    b = 2;
    c = 3;
    if(a > b)
        if(a > c)
            cout << a << ' ';
        else
        cout << b << ' '; 
    cout << c << endl;
    return 0;
}
```
输出：____
{{ input(23) }}

24. **阅读程序写结果：**  
```
#include <iostream>
using namespace std;
struct point
{
	int x;
	int y;
};

int main()
{
	int a, b, c;
	struct EX
	{
		int a;
		int b;
		point c;
	} e;

	e.a	= 1;
	e.b	= 2;
	e.c.x= e.a + e.b;
	e.c.y= e.a * e.b;
	cout << e.c.x << ',' << e.c.y << endl;
	return(0);
}
```
{{ input(24) }}

25. **阅读程序写结果：**  
```
#include <iostream>
#include <string> 
using namespace std;

int main()
{
	string str;
	int i;
	int count; count = 0;
	getline( cin, str );
	for ( i = 0; i < str.length(); i++ )
		if ( str[i] >= 'a' && str[i] <= 'z' )
			count++;
	cout << "It has " << count << " lowercases" << endl; return(0);
}
```
输入：NOI2016 will be held in Mian Yang.   
输出：_______ 	

{{ input(25) }}

26. **阅读程序写结果：**  
```cpp
#include <iostream>
#include <string>
using namespace std;

void fun( char *a, char *b )
{
  a = b;
  (*a)++;
}


int main()
{
  char c1, c2, *p1, *p2;
  c1 = 'A';
  c2 = 'a';
  p1 = &c1;
  p2 = &c2;
  fun( p1, p2 );
  cout << c1 << c2 << endl;
  return(0);
}
```
{{ input(26) }}

27. **完善程序：**  
**（打印日历）** 输入月份 $m(1\leq m\leq 12)$，按一定格式打印 $2015$ 年第 $m$ 月的月历。（第三、四空 $2.5$ 分， 其余 $3$ 分）  
例如，$2015$ 年 $1$ 月的月历打印效果如下（第一列为周日）：  
```
S	M	T	W	T	F	S
				1	2	3
4	5	6	7	8	9	10
11	12	13	14	15	16	17
18	19	20	21	22	23	24
25	26	27	28	29	30	31
```
---
```
#include <iostream>
#include <string>
using namespace std;
const int dayNum[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int m, offset, i;
int main()
{
    cin >> m;
    cout << "S\tM\tT\tW\tT\tF\tS" << endl; /* '\t'为 TAB 制表符 */
    ①;
    for (i = 1; i < m; i++)
        offset = ②;
    for (i = 0; i < offset; i++)
        cout << '\t';
    for (i = 1; i <= ③; i++)
    {
        cout << ④;
        if (i == dayNum[m] || ⑤ == 0)
            cout << endl;
        else
            cout << '\t';
    }
    return (0);
}
```
{{ input(27) }}

{{ input(28) }}

{{ input(29) }}

{{ input(30) }}

{{ input(31) }}

28. **完善程序：**  
**（中位数 median）** 给定 $n$（$n$ 为奇数且小于 $1000$）个整数，整数的范围在 $0\sim m(0<m<2^{31})$ 之间，请使用二分法求这 $n$ 个整数的中位数。所谓中位数，是指将这 $n$ 个数排序之后，排在正中间的数。(第五空 $2$ 分，其余 $3$ 分)  

```
#include <iostream>
using namespace std;

const int MAXN = 1000;
int n, i, lbound, rbound, mid, m, count;
int x[MAXN];

int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> x[i];
    lbound = 0;
    rbound = m;
    while (①)
    {
        mid = (lbound + rbound) / 2;
        ②;
        for (i = 0; i < n; i++)
            if (③)
                ④;
        if (count > n / 2)
            lbound = mid + 1;
        else
            ⑤;
        cout << mid << " " << lbound << " " << rbound << " " << count << endl;
    }
    cout << rbound << endl;
    return (0);
}
```
{{ input(32) }}

{{ input(33) }}

{{ input(34) }}

{{ input(35) }}

{{ input(36) }}

