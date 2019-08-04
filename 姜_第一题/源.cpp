#include <iostream>

using namespace std;

 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 #define ElemType char

 typedef int Status; /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */

 typedef struct LNode /* ������� */
 {
   ElemType data;
   struct LNode *next;
 } LNode,*Link;

 typedef struct LinkL /* �������� */
 {
   Link head,tail; /* �ֱ�ָ�����������е�ͷ�������һ����� */
   int len; /* ָʾ��������������Ԫ�صĸ��� */
 }LinkList;

 Status MakeNode(Link *p, ElemType e)
{ /* ������pָ���ֵΪe�Ľ�㣬������OK��������ʧ�ܡ��򷵻�ERROR */
	*p = (Link)new LNode;
	if (!*p)
		return ERROR;
	(*p)->data = e;
	return OK;
}

void FreeNode(Link *p)
{ /* �ͷ�p��ָ��� */
	delete(*p);
	*p = NULL;
}

Status InitList(LinkList *L)
{ /* ����һ���յ��������� */

	Link p = new LNode; /* ����ͷ��� */
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
{ /* ��֪pָ����������L�е�һ����㣬����p��ָ����ֱ��ǰ����λ�� */
  /* ����ǰ�����򷵻�NULL */
	Link q;
	q = L.head->next;
	if (q == p) /* ��ǰ�� */
		return NULL;
	else
	{
		while (q->next != p) /* q����p��ֱ��ǰ�� */
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
{ /* ����β�ڵ� */

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
{ /* ��֪pָ�����������е�һ����㣬next�ÿ� */
	p->next=q;
	return OK;
}

Status ListEmpty(LinkList L)
{ /* ����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
	if (L.len)
		return FALSE;
	else
		return TRUE;
}

int ListLength(LinkList  * L)
{ /* ������������L��Ԫ�ظ��� */
	return L->len;
}

Link GetLast(LinkList * L)
{ /* ������������L�����һ������λ�� */
	return L -> tail;
}

Link NextPos(Link p)
{ /* ��֪pָ����������L�е�һ����㣬����p��ָ����ֱ�Ӻ�̵�λ�� */
  /* ���޺�̣��򷵻�NULL */
	return p->next;
}

Status LocatePos(LinkList *L, int i, Link *p)
{ /* ����pָʾ��������L�е�i������λ�ã�������OK��iֵ���Ϸ�ʱ����ERROR */

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
{ /*�˺���������Ԥ�ȸ�������ĵ��ʽ��д洢��,��ΪҪ�洢��������һ���ֲ����ͺ��������ͬ��׺�����Ǻ����*/
      char *p=word1;
      char *q=word2;

      Link  use1 =NULL, use2=NULL;
      Link  mark1 =NULL;

      int number =0 ;

      for( int i=0  ; *(p+i)!='\0'; i++)
            /*Ԥ�Ƚ�δ�������ʴ������������*/
      {
              if(!InsTail(first_word,*(p+i)))
                return ERROR;
      }
       for( int i=0 ; *(q+i)!='\0'; i++)
            /*Ԥ�Ƚ�δ�������ʴ������������*/
      {
              if(!InsTail(second_word,*(q+i)))
                return ERROR;
      }

      int Lenth_1 = ListLength(first_word);
      int Lenth_2 = ListLength(second_word);

      if(Lenth_1 >= Lenth_2)
        /*���ݵ��ʳ����ƶ�����ڵ�λ�ã�ʹ�������ʱ��ִ��Աȵ�ĩβ�Ƕ����*/
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
            /*һλһλ���бȽϣ����������ͬ��Ӵ˴�������һ����ĸ�ıȽ�*/
            /*ÿһ�αȽ�ʱҪ��¼��αȽϿ�ʼ��λ�� ֱ���ȽϽ��е�ĩβ*/
          {
              if(use1 == first_word->tail )          /*����β���Ƿ�һ��Ϊ�˱������β��ֻ�����һλ��һ���������������*/
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
        /*ɾ���ڶ�������ĺ����ͬ����*/
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
    /*������ĵ��ʷ�������Ҫ��Ĵ洢��ʽ��*/
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
    /*������Ҫ�����ͬ��׺��ͬռ�ÿռ�Ĵ洢��ʽ��*/
    /*Ѱ�ҹ�ͬ��׺λ�÷�����ͬ��׺�ĳ���*/
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
    InitList(second_word);                /*�����µ�����*/

    if( !Get_in(first_word , second_word ) ) return ERROR;           /*�����뵥��������Ҫ����ʽ�洢*/

    int same_tail_number = Get_Tail_Length( first_word , second_word );        /*���ش�����ͬĩβ����*/

    cout << same_tail_number<<endl;

    return 0;
}


