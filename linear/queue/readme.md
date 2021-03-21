# 队列简记

#### 简介
队列是一种操作受限的线性表(FIFO),如实现了基本的线性表,那就很容易改造成队列.考虑/linear/base/下面的基本线性表,只需要在insert和delete操作上再一次封装出方法in和out就可以将其作为队列使用.
需要注意的是如果队列是基于连续存储的物理结构实现,这样简单封装的方法时间复杂度为线性阶,如果要优化至常数阶,必须使用循环队列来实现.

#### 循环队列
循环队列的核心在于利用求余运算的性质来复用索引,来保证常数阶的操作下,索引不会超出合法的范围,队列仍能充分利用存储空间.基于链式存储的循环队列通常没有意义.

#### 判空和判满
循环队列的一个问题是,如果不借助额外的手段,队列满和队列空的状态是一致的,最为直观有效的区分方式即用一个变量记录已经使用的空间,根据该变量的值来判断队列是满了还是空的.

#### 双端队列
如果搞定了上面的队列,那双端队列并不是什么难事,双端队列增加了在队头入队和队尾出队的操作,需要注意边界条件.如果是基于链式存储的双端队列,使用双向链表要比单向链表好得多.
