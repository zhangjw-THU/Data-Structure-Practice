
typedef struct QE
{
	int ArrivalTime; /* ����ʱ�� */
	int Duration; /* ������������ʱ�� */
}QElemType; /* ����QElemType(���е�����Ԫ������)Ϊ�ṹ������; */

/* c3-2.h �������У������е���ʽ�洢�ṹ */
typedef struct QNode
{
   QElemType data;
   struct QNode *next;
} *QueuePtr;

 typedef struct LinkQ
 {
   QueuePtr front,rear; /* ��ͷ����βָ�� */
 }LinkQueue;
