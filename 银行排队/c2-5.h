 /* c2-5.h ��ͷ���������������� */
 typedef struct LNode/* ������� */
 {
   ElemType data;
   struct LNode *next;
 }*Link,*Position;

 typedef struct LinkL /* �������� */
 {
   Link head,tail; /* �ֱ�ָ�����������е�ͷ�������һ����� */
   int len; /* ָʾ��������������Ԫ�صĸ��� */
 }LinkList;
