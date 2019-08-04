
typedef struct QE
{
	int ArrivalTime; /* 到达时刻 */
	int Duration; /* 办理事务所需时间 */
}QElemType; /* 定义QElemType(队列的数据元素类型)为结构体类型; */

/* c3-2.h 单链队列－－队列的链式存储结构 */
typedef struct QNode
{
   QElemType data;
   struct QNode *next;
} *QueuePtr;

 typedef struct LinkQ
 {
   QueuePtr front,rear; /* 队头、队尾指针 */
 }LinkQueue;
