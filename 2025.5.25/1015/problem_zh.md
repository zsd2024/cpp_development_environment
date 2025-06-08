1. 以下哪个是面向对象的高级语言(      )。
{{ select(1) }}
- 汇编语言
- C++ 
- Fortran
- Basic

2. $1 \text{ TB}$ 代表的字节数是(      )。 

{{ select(2) }}
- $2$ 的 $10$ 次方
- $2$ 的 $20$ 次方
- $2$ 的 $30$ 次方 
- $2$ 的 $40$ 次方

3. 二进制数 $00100100$ 和 $00010101$ 的和是(      )。

{{ select(3) }}
- 00101000
- 001010100 
- 01000101
- 00111001

4. 以下哪一种设备属于输出设备(      )。
{{ select(4) }}
- 扫描仪
- 键盘
- 鼠标
- 打印机

5. 下列对操作系统功能的描述最为完整的是(      )。  

{{ select(5) }}
- 负责外设与主机之间的信息交换
- 负责诊断机器的故障 
- 控制和管理计算机系统的各种硬件和软件资源的使用
- 将没有程序编译成目标程序

6. CPU、存储器、I/O 设备是通过(      )连接起来的。

{{ select(6) }}
- 接口
- 总线 
- 控制线
- 系统文件

7. 断电后会丢失数据的存储器是(      )。

{{ select(7) }}
- RAM
- ROM
- 硬盘
- 光盘

8. 以下哪一种是属于电子邮件收发的协议(      )。

{{ select(8) }}
- SMTP
- UDP
- P2P 
- FTP

9. 下列选项中不属于图像格式的是(      )。

{{ select(9) }}
- JPEG 格式
- TXT 格式
- GIF 格式
- PNG 格式

10. 链表不具有的特点是(      )。
{{ select(10) }}
- 不必事先估计存储空间
- 可随机访问任一元素 
- 插入删除不需要移动元素
- 所需空间与线性表长度成正比

11. 下列各无符号十进制整数中，能用八位二进制表示的数中最大的是(      )。
{{ select(11) }}
- 296
- 133
- 256
- 199

12. 下列几个 $32$ 位 IP 地址中，书写错误的是(      )。

{{ select(12) }}
- 162.105.135.27
- 192.168.0.1
- 256.256.129.1
- 10.0.0.1

13. 要求以下程序的功能是计算：$s=1+\dfrac{1}{2}+\dfrac{1}{3}+\dots+\dfrac{1}{10}$。  
```
#include <iostream>  
using namespace std;  
int main()  
 { 
int n;     
float s;     
s = 1.0; 
for(n = 10; n > 1; n--)       
s = s + 1 / n;     
cout << s << endl;     
return 0;   
} 
```
程序运行后输出结果错误，导致错误结果的程序行是(      )。 

{{ select(13) }}
- `s = 1.0`;
- `for(n = 10; n > 1; n--)`
- `s = s + 1 / n;`
- `cout << s << endl;`

14. 设变量 $x$ 为 float 型且已赋值，则以下语句中能将 $x$ 中的数值保留到小数点后两位，并将第三位四舍五入的是(      )。

{{ select(14) }}
- `x = (x * 100) + 0.5 / 100.0;`
- `x = (x * 100 + 0.5) / 100.0;`   
-  `x = (int)(x * 100 + 0.5)/100.0;` 
-  `x = (x / 100 + 0.5) * 100.0;`

15. 有以下程序:   
```
#include <iostream>
using namespace std;
int main()
{
	int s, a, n;
	s= 0;
	a= 1;
	cin >> n;
	do
	{
	  s+= 1;
	  a-= 2;
	}
	while ( a != n );
	cout << s << endl;
	return(0);
}
```
若要使程序的输出值为 $2$，则应该从键盘给 $n$ 输入的值是(      )。    
{{ select(15) }}
- -1
- -3
- -5
- 0

16. 一棵具有 $5$ 层的满二叉树中结点数为(      )。

{{ select(16) }}
- 31
- 32
- 33
- 16

17. 有向图中每个顶点的度等于该顶点的(      )。

{{ select(17) }}
- 入度
- 出度
- 入度和出度之和
- 入度和出度之差

18. 设有 $100$ 个数据元素，采用折半搜索时，最大比较次数为(      )。

{{ select(18) }}
- 6
- 7
- 8
- 10

19. 若有如下程序段，其中 $s,a,b,c$ 均已定义为整型变量，且 $a,c$ 均已赋值，$c>0$。 
```cpp
s = a;   
for(b = 1; b <= c; b++)   s += 1;   
```

则与上述程序段功能等价的赋值语句是(      )。
{{ select(19) }}
- `s = a + b` 
-  `s = a + c` 
-  `s = s + c` 
-  `s = b + c`

20. 计算机界的最高奖是(      )。

{{ select(20) }}
- 菲尔兹奖
- 诺贝尔奖
- 图灵奖
- 普利策奖

21. 把 $M$ 个同样的球放到 $N$ 个同样的袋子里，允许有的袋子空着不放，问共有多少种不同的放置方法？(用 $K$ 表示)。

例如，$M=7,N=3$ 时，$K=8$；在这里认为 $(5,1,1)$ 和 $(1,5,1)$ 是同一种放置方法。 问：$M=8,N=5$ 时，$K=$______
{{ input(21) }}

22. 如图所示，图中每条边上的数字表示该边的长度，则从A到E的最短距离是__。  
![](http://luogu-ipic.oss-cn-shanghai.aliyuncs.com/youti/14.png)
{{ input(22) }}

23. **阅读程序写结果：**  
```
#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d, ans;
	cin >> a >> b >> c;
	d = a - b;
	a = d + c;
	ans	= a * b;
	cout << "Ans = " << ans << endl; 
        return(0);
}
  
```
输入：2 3 4  
输出：Ans =____
{{ input(23) }}

24. **阅读程序写结果：**  
```
#include <iostream>   
using namespace std;   
int fun(int n)    
{  
if(n == 1)        
return 1;      
if(n == 2)        
return 2;  
return fun(n -2) - fun(n - 1);    
}   
int main()    
{  
int n;      
cin >> n;  
cout << fun(n) << endl;     
 return 0;    
} 
```
输入：7 
输出：__
{{ input(24) }}

25. **阅读程序写结果：**  
```
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string	st;
	int	i, len;
	getline( cin, st );
	len = st.size();
	for ( i = 0; i < len; i++ )
		if ( st[i] >= 'a' && st[i] <= 'z' )
			st[i] = st[i] - 'a' + 'A';
	cout << st << endl;
	return(0);
}



```
输入：Hello, my name is Lostmonkey.  
输出：________________________________

{{ input(25) }}

26. **阅读程序写结果：**  
```
#include <iostream>
using namespace std;
const int SIZE = 100;
int main()
{
	int	p[SIZE];
	int	n, tot, i, cn;
	tot = 0;
	cin >> n;
	for ( i = 1; i <= n; i++ )
		p[i] = 1;
	for ( i = 2; i <= n; i++ )
	{
		if ( p[i] == 1 )
			tot++;
		cn = i * 2;
		while ( cn <= n )
		{
			p[cn] = 0;
			cn += i;
		}
	}
	cout << tot << endl;
	return(0);
}
```
输入：30  
输出：___
{{ input(26) }}

27. **完善程序：**  
**(数字删除)** 下面程序的功能是将字符串中的数字字符删除后输出。请填空。(每空 3 分，共 12 分)    
```
#include <iostream>
using namespace std;
int delnum( char *s )
{
	int i, j;
	j = 0;
	for ( i = 0; s[i] != '\0'; i++ )
		if ( s[i] < '0'   ①  s[i] > '9' )
		{
			s[j] = s[i];
			②;
		}
	return(③);
}


const int SIZE = 30;
int main()
{
	char	s[SIZE];
	int len, i;
	cin.getline( s, sizeof(s) );
	len = delnum( s );
	for ( i = 0; i < len; i++ )
		cout << ④;
	cout << endl;
	return(0);
}
```
{{ input(27) }}

{{ input(28) }}

{{ input(29) }}

{{ input(30) }}

28. （最大子矩阵和）给出 $m$ 行 $n$ 列的整数矩阵，求最大的子矩阵和(子矩阵不能为空)。    
输入第一行包含两个整数 $m$ 和 $n$，即矩阵的行数和列数。之后 $m$ 行，每行 $n$ 个整数，描述整个矩阵。程序最终输出最大的子矩阵和。   
**（最后一空 $4$ 分，其余 $3$ 分，共 $16$ 分）**  
比如在如下这个矩阵中：  
```
4  4  
0 -2 -7 0  
9 2 -6 2  
-4 1 -4 1  
-1 8 0 -2  
```
拥有最大和的子矩阵为： 
```
 9 2  
-4 1  
-1 8  
```
其和为 $15$   
```
3  3  
-2 10 20 
-1 100 -2 
0 -2 -3
``` 
最大子矩阵和为 $128$   
```
4  4  
0 -2 -9 -9 
-9 11 5 7 
-4 -3 -7 -6 
-1  7  7  5 
```
最大子矩阵和为 $26$  
```cpp
#include <iostream>
using namespace std;
const int SIZE = 100;
int matrix[SIZE + 1][SIZE + 1];
int rowsum[SIZE + 1][SIZE + 1]; /* rowsum[i][j]记录第i行前j个数的和 */
int m, n, i, j, first, last, area, ans;
int main()
{
	cin >> m >> n;
	for ( i = 1; i <= m; i++ )
		for ( j = 1; j <= n; j++ )
			cin >> matrix[i][j];
	ans = matrix   ①;
	for ( i = 1; i <= m; i++ )
		②;
		for ( i = 1; i <= m; i++ )
			for ( j = 1; j <= n; j++ )
				rowsum[i][j] = ③;
	for ( first = 1; first <= n; first++ )
		for ( last = first; last <= n; last++ )
		{
			④;
			for ( i = 1; i <= m; i++ )
			{
				area += ⑤;
				if ( area > ans )
					ans = area;
				if ( area < 0 )
					area = 0;
			}
		}
	cout << ans << endl;
	return(0);
}
```

{{ input(31) }}

{{ input(32) }}

{{ input(33) }}

{{ input(34) }}

{{ input(35) }}

