#include <iostream>

using namespace std;

 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 #define ElemType char

 typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */

 typedef struct LNode /* 结点类型 */
 {
   ElemType data;
   struct LNode *next;
 } LNode,*Link;

 typedef struct LinkL /* 链表类型 */
 {
   Link head,tail; /* 分别指向线性链表中的头结点和最后一个结点 */
   int len; /* 指示线性链表中数据元素的个数 */
 }LinkList;

 Status MakeNode(Link *p, ElemType e)
{ /* 分配由p指向的值为e的结点，并返回OK；若分配失败。则返回ERROR */
	*p = (Link)new LNode;
	if (!*p)
		return ERROR;
	(*p)->data = e;
	return OK;
}

void FreeNode(Link *p)
{ /* 释放p所指结点 */
	delete(*p);
	*p = NULL;
}

Status InitList(LinkList *L)
{ /* 构造一个空的线性链表 */

	Link p = new LNode; /* 生成头结点 */
	if (p)
	{
		 p->next = NULL;
		(*L).head = (*L).tail = p;
		(*L).head->data = 0;
		(*L).len = 0;
		return OK;
	}
	else
		return ERROR;
}

Link PriorPos(LinkList L, Link p)
{ /* 已知p指向线性链表L中的一个结点，返回p所指结点的直接前驱的位置 */
  /* 若无前驱，则返回NULL */
	Link q;
	q = L.head->next;
	if (q == p) /* 无前驱 */
		return NULL;
	else
	{
		while (q->next != p) /* q不是p的直接前驱 */
			q = q->next;
		return q;
	}
}

void pri( LinkList *L)
{
    Link a = (*L).head;
    while(a!=NULL)
    {
        cout<<a->data;
        a=a->next;
    }

}

Status InsTail(LinkList *L, ElemType m)
{ /* 插入尾节点 */

       Link s ;
       MakeNode( &s , m );
      s->next = NULL;
      (*L).tail->next = s;
      (*L).tail = s;
      (*L).len++;
  // pri(L);
	return OK;
}


Status SetNext(Link p,Link q)
{ /* 已知p指向线性链表中的一个结点，next置空 */
	p->next=q;
	return OK;
}

Status ListEmpty(LinkList L)
{ /* 若线性链表L为空表，则返回TRUE，否则返回FALSE */
	if (L.len)
		return FALSE;
	else
		return TRUE;
}

int ListLength(LinkList  * L)
{ /* 返回线性链表L中元素个数 */
	return L->len;
}

Link GetLast(LinkList * L)
{ /* 返回线性链表L中最后一个结点的位置 */
	return L -> tail;
}

Link NextPos(Link p)
{ /* 已知p指向线性链表L中的一个结点，返回p所指结点的直接后继的位置 */
  /* 若无后继，则返回NULL */
	return p->next;
}

Status LocatePos(LinkList *L, int i, Link *p)
{ /* 返回p指示线性链表L中第i个结点的位置，并返回OK，i值不合法时返回ERROR */

	int j;
	if (i<1 || i>L->len)
		return ERROR;
	else
	{
		*p = L->head;
		for (j = 1; j <= i; j++)
			*p = (*p)->next;
		return OK;
	}
}

Status Creat_New_Save( char * word1,char * word2 ,LinkList * first_word , LinkList * second_word)
{ /*此函数是用来预先根据输入的单词进行存储的,因为要存储，其中有一部分操作和后面的求相同后缀长度是很像的*/
      char *p=word1;
      char *q=word2;

      Link  use1 =NULL, use2=NULL;
      Link  mark1 =NULL;

      int number =0 ;

      for( int i=0  ; *(p+i)!='\0'; i++)
            /*预先将未做处理单词存入各自链表中*/
      {
              if(!InsTail(first_word,*(p+i)))
                return ERROR;
      }
       for( int i=0 ; *(q+i)!='\0'; i++)
            /*预先将未做处理单词存入各自链表中*/
      {
              if(!InsTail(second_word,*(q+i)))
                return ERROR;
      }

      int Lenth_1 = ListLength(first_word);
      int Lenth_2 = ListLength(second_word);

      if(Lenth_1 >= Lenth_2)
        /*根据单词长度移动链表节点位置，使得两单词保持待对比的末尾是对齐的*/
      {
          use2 = NextPos(second_word->head);
          if(! LocatePos( first_word , Lenth_1-Lenth_2 +1 , &use1))
            return ERROR;
      }
      else
      {
          use1 = NextPos(first_word->head);
          if(! LocatePos( second_word , Lenth_2-Lenth_1 +1, &use2))
            return ERROR;
      }

           while(use1 != NULL && use2 != NULL)
            /*一位一位进行比较，如果遇到不同则从此处进行下一个字母的比较*/
            /*每一次比较时要记录这次比较开始的位置 直到比较进行到末尾*/
          {
              if(use1 == first_word->tail )          /*检验尾部是否一样为了避免后面尾部只有最后一位不一样而单拉出来检测*/
              {
                  if(use1->data != use2->data)
                    return OK;
                  else
                 {
                  number = 1;
                 }
              }

              mark1 = use1;
              number = 0;
               while(use1 != NULL && use2 != NULL)
               {
                  if( use1->data != use2->data)
                  break;
                  use1 = NextPos(use1);
                  use2 = NextPos(use2);
                  number++;
               }
               if(use1 != NULL && use2 != NULL)
               {
                use1 = NextPos(use1);
                use2 = NextPos(use2);
               }
          }

          Link the_tail ,later , to_del;
          LocatePos(second_word , Lenth_2-number , &the_tail);
          later = the_tail->next;
          SetNext(the_tail , mark1);

    for(int i=0 ; i<number ; i++)
        /*删除第二个链表的后边相同部分*/
    {
          to_del = later;
          later = later->next ;
          delete to_del;
    }

    second_word->tail = first_word->tail;

    return OK;
}

Status Get_in( LinkList * first_word , LinkList * second_word )
{
    /*将输入的单词放入题中要求的存储格式中*/
    char first[30] , second[30];
    cin>>first;

    cin>>second;

    if(Creat_New_Save(first , second , first_word , second_word))
        return OK;
    else
        return ERROR;

}

int Get_Tail_Length( LinkList *first_word , LinkList * second_word)
{
    /*在题中要求的相同后缀共同占用空间的存储形式下*/
    /*寻找共同后缀位置返回相同后缀的长度*/
    int Lenth_1 = first_word -> len;
    int Lenth_2= second_word -> len;
    int number = 0;
    Link my_1 =NULL, my_2 =NULL;

    if(Lenth_1 >= Lenth_2)
      {
          my_2 = NextPos(second_word-> head);
          LocatePos( first_word , Lenth_1-Lenth_2+1 , &my_1);
          number = ListLength(second_word);

      }
      else
      {
          my_1 = NextPos(second_word-> head);
          LocatePos( second_word , Lenth_2-Lenth_1 +1, &my_2);
          number = ListLength(first_word);
      }

    while(my_1 != my_2 && my_1 != NULL && my_2 != NULL)
    {
        my_1 = NextPos( my_1 );
        my_2 = NextPos( my_2 );
        number--;
    }

    return number;
}


int main()
{

    LinkList *first_word =new LinkList , *second_word = new LinkList;

    InitList(first_word);
    InitList(second_word);                /*构造新的链表*/

    if( !Get_in(first_word , second_word ) ) return ERROR;           /*将输入单词以题中要求形式存储*/

    int same_tail_number = Get_Tail_Length( first_word , second_word );        /*返回待求相同末尾长度*/

    cout << same_tail_number<<endl;

    return 0;
}


