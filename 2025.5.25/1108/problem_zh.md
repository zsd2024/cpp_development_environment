1. GESP 八级样题

从 A 城到 C 城需要经过 B 城，其中 A 到 B 可选高铁和飞机，B 到 C 可以自驾或打的，请问 A 到 C 有几种交通选择（ ）
{{ select(1) }}
- 2
- 4
- 8
- 不知道

2. 下面程序输出的n的值是（ ）。
![](https://cdn.luogu.com.cn/upload/image_hosting/3yudqrb7.png)
{{ select(2) }}
- 4
- 12
- 18
- 24

3. 对 $(a+b)^5$，想求出 $a^3b^2$ 的系数可以使用（ ）。
{{ select(3) }}
- 杨氏三角
- 祖冲之角
- 勾股三角
- 杨辉三角

4. 对于 4 个结点的简单有向图，最少（ ）条边可以形成一条覆盖所有顶点的环。
{{ select(4) }}
- 5
- 4
- 3
- 2

5. 对正整数 $a$ 和 $n$（$n$ 为 $2$ 的正整数次幂），下面求 $a^n$ 值的方法是（ ）。
![](https://cdn.luogu.com.cn/upload/image_hosting/42cji5on.png)
{{ select(5) }}
- 折半
- 二分
- 倍增
- 迭代

6. 平面内，通过一点可以作（ ）条平行于给定直线的直线？
{{ select(6) }}
- 0
- 1
- 2
- 无限多

7. 定义常量 `const double pi=3.14159`。如果一个等边三角形的边长为 4，下列（ ）表达式可以求其面积。
{{ select(7) }}
- `16*sin(pi/3)`
- `16*cos(pi/3)`
- `8*sin(pi/3)`
- `8*cos(pi/3)`

8. 下面程序使用 BFS 遍历一个有 $n$ 个顶点、边权都为 $1$ 的无向图 $G$，下面说法正确的是（ ）。
![](https://cdn.luogu.com.cn/upload/image_hosting/wtizz9mb.png)
{{ select(8) }}
- tl 记录遍历的结点数
- dis 按照贪心法变化
- dis 存储 st 到其他顶点的距离
- 算法复杂度是 $O(n^2)$

9. 下面的冒泡排序中尝试提前结束比较过程，横线处应该填写的代码是（ ）。
![](https://cdn.luogu.com.cn/upload/image_hosting/f0nl7bzg.png)
{{ select(9) }}
- `i = lastExchangeIndex + 1`
- `i = lastExchangeIndex - 1`
- `i = lastExchangeIndex`
- `i = lastExchangeIndex - j`

10. 对数列 $3,4,7,12,19,28,39$ 求和，除简单累加外，还可以用下面（ ）来直接计算。
{{ select(10) }}
- 等差数列求和
- 等比数列求和
- 斐波拉契数列
- 其他某种有规律序列

11. 约定杨辉三角形第 $0$ 行只有 $1$ 个元素是 $1$，第 $1$ 行有 $2$ 个元素都是 $1$，第四行的所有元素之和是？（ ）
{{ select(11) }}
- 8
- 16
- 24
- 32

12. 下列程序的输出是 ( ) 。
![](https://cdn.luogu.com.cn/upload/image_hosting/m8psov16.png)
{{ select(12) }}
- -12
- 0
- 55
- -55

13. 对于具有 $n$ 个元素的二叉排序树（又名二分查找树）进行前序遍历，其时间复杂度是( )？
{{ select(13) }}
- $O(1)$
- $O(log n)$
- $O(n)$
- $O(n^2)$

14. Dijkstra 的算法在实现时一般可以选用（ ）来提高效率？
{{ select(14) }}
- 数组
- 链表
- 堆
- 栈

15. 有关下面代码的说法正确的是（ ）。
![](https://cdn.luogu.com.cn/upload/image_hosting/i516er0n.png)
{{ select(15) }}
- 上述代码构成单向链表。
- 上述代码构成双向链表。
- 上述代码构成循环链表。
- 上述代码构成指针链表。

16. 学校组织班际排球赛，每个班级可以派男女各一个参赛队伍，每队 $5$ 人。班级 A 的每位同学都可以报名，那可以用加法原理来计算 A 班有多少支候选队伍（ ）
{{ select(16) }}
- 正确
- 错误

17. 若 a,x,b 都是 double 类型，则对方程 $a \times x+b=0$ 求解的程序中可以直接用 `x=-b/a` 来求解。（ ）
{{ select(17) }}
- 正确
- 错误

18. 从 $15$ 本不同的书中选 $3$ 本，总共有 $455$ 种方法。（ ）
{{ select(18) }}
- 正确
- 错误

19. 连通图 $G$ 有 $n$ 个顶点 $m$ 条边，须删除 $m-n+1$ 条边后才能变成一棵生成树。（ ）
{{ select(19) }}
- 正确
- 错误

20. 在 C++ 语言中，所有 int 类型的值，经过若干次左移操作（<<）后，它们的值总会变为 $0$。（ ）
{{ select(20) }}
- 正确
- 错误

21. 如果一个四边形的对角线互相平分，并且两条对角线的长度都为 $8$，那么这个四边形的面积一定是 $32$。（ ）
{{ select(21) }}
- 正确
- 错误

22. 最小生成树的权值是指生成树所有边的权值之和最小。（ ）
{{ select(22) }}
- 正确
- 错误

23. 如果一个图中所有边的权重都为正数，则 Floyd 算法可以求出该图中任意两个顶点间的最短路径。（ ）
{{ select(23) }}
- 正确
- 错误

24. 下面是图的深度遍历的代码，则横线处可以填入：`if(vis[x]) return。`
![](https://cdn.luogu.com.cn/upload/image_hosting/c7ujai52.png)
{{ select(24) }}
- 正确
- 错误

25. 下图中 A 到 E 的 Dijkstra 单源最短路可以在第 $2$ 次探索中找到。（ ）
![](https://cdn.luogu.com.cn/upload/image_hosting/qgeb869x.png)
{{ select(25) }}
- 正确
- 错误

