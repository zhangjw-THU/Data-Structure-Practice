/* algo3-12.c ����ҵ��ģ�⡣ʵ���㷨3.6��3.7�ĳ��� */
// #define Qu 4 /* �ͻ������� */
#define Khjg 5 /* �����ڵ���Ŀͻ���ʱ�������ֵ */
#define Blsj 30 /* ÿ���ͻ�����ҵ���ʱ�����ֵ */
#include"c1.h"
#include"C2-5.h"
#include"C3-2.h"
#include"stdio.h"
#include"time.h"
#include"stdlib.h"
#include<iostream>
using namespace std;
int Qu;
/* bo2-6.c ����ʵ���������������(�洢�ṹ��c2-5.h����)��24���������� */
Status MakeNode(Link *p, ElemType e)
{ /* ������pָ���ֵΪe�Ľ�㣬������OK��������ʧ�ܡ��򷵻�ERROR */
	*p = (Link)malloc(sizeof(LNode));
	if (!*p)
		return ERROR;
	(*p)->data = e;
	return OK;
}

void FreeNode(Link *p)
{ /* �ͷ�p��ָ��� */
	free(*p);
	*p = NULL;
}

Status InitList(LinkList *L)
{ /* ����һ���յ��������� */
	Link p;
	p = (Link)malloc(sizeof(LNode)); /* ����ͷ��� */
	if (p)
	{
		p->next = NULL;
		(*L).head = (*L).tail = p;
		(*L).len = 0;
		return OK;
	}
	else
		return ERROR;
}

Status ClearList(LinkList *L)
{ /* ����������L����Ϊ�ձ����ͷ�ԭ����Ľ��ռ� */
	Link p, q;
	if ((*L).head != (*L).tail)/* ���ǿձ� */
	{
		p = q = (*L).head->next;
		(*L).head->next = NULL;
		while (p != (*L).tail)
		{
			p = q->next;
			free(q);
			q = p;
		}
		free(q);
		(*L).tail = (*L).head;
		(*L).len = 0;
	}
	return OK;
}

Status DestroyList(LinkList *L)
{ /* ������������L��L���ٴ��� */
	ClearList(L); /* ������� */
	FreeNode(&(*L).head);
	(*L).tail = NULL;
	(*L).len = 0;
	return OK;
}

Status InsFirst(LinkList *L, Link h, Link s) /* �β�����L,��Ϊ���޸�L */
{ /* hָ��L��һ����㣬��h����ͷ��㣬��s��ָ�������ڵ�һ�����֮ǰ */
	s->next = h->next;
	h->next = s;
	if (h == (*L).tail) /* hָ��β��� */
		(*L).tail = h->next; /* �޸�βָ�� */
	(*L).len++;
	return OK;
}

Status DelFirst(LinkList *L, Link h, Link *q) /* �β�����L,��Ϊ���޸�L */
{ /* hָ��L��һ����㣬��h����ͷ��㣬ɾ�������еĵ�һ����㲢��q���ء� *
  /* ������Ϊ��(hָ��β���)��q=NULL������FALSE */
	*q = (h)->next;
	if (*q) /* ����ǿ� */
	{
		(h)->next = (*q)->next;
		if (!h->next) /* ɾ��β��� */
			(*L).tail = (h); /* �޸�βָ�� */
		(*L).len--;
		return OK;
	}
	else
		return FALSE; /* ����� */
}

Status Append(LinkList *L, Link s)
{ /* ��ָ��s(s->dataΪ��һ������Ԫ��)��ָ(�˴���ָ������,��NULL��β)�� */
	/* һ�������������������L�����һ�����֮��,���ı�����L��βָ��ָ���� */
	/* ��β��� */
	int i = 1;
	(*L).tail->next = s;
	while (s->next)
	{
		s = s->next;
		i++;
	}
	(*L).tail = s;
	(*L).len += i;
	return OK;
}

Position PriorPos(LinkList L, Link p)
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

Status Remove(LinkList *L, Link *q)
{ /* ɾ����������L�е�β��㲢��q���أ��ı�����L��βָ��ָ���µ�β��� */
	Link p = (*L).head;
	if ((*L).len == 0) /* �ձ� */
	{
		*q = NULL;
		return FALSE;
	}
	while (p->next != (*L).tail)
		p = p->next;
	*q = (*L).tail;
	p->next = NULL;
	(*L).tail = p;
	(*L).len--;
	return OK;
}

Status InsBefore(LinkList *L, Link *p, Link s)
{ /* ��֪pָ����������L�е�һ����㣬��s��ָ��������p��ָ���֮ǰ�� */
	/* ���޸�ָ��pָ���²���Ľ�� */
	Link q;
	q = PriorPos(*L, *p); /* q��p��ǰ�� */
	if (!q) /* p��ǰ�� */
		q = (*L).head;
	s->next = *p;
	q->next = s;
	*p = s;
	(*L).len++;
	return OK;
}

Status InsAfter(LinkList *L, Link *p, Link s)
{ /* ��֪pָ����������L�е�һ����㣬��s��ָ��������p��ָ���֮�� */
	/* ���޸�ָ��pָ���²���Ľ�� */
	if (*p == (*L).tail) /* �޸�βָ�� */
		(*L).tail = s;
	s->next = (*p)->next;
	(*p)->next = s;
	*p = s;
	(*L).len++;
	return OK;
}

Status SetCurElem(Link p, ElemType e)
{ /* ��֪pָ�����������е�һ����㣬��e����p��ָ���������Ԫ�ص�ֵ */
	p->data = e;
	return OK;
}


Status ListEmpty(LinkList L)
{ /* ����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
	if (L.len)
		return FALSE;
	else
		return TRUE;
}

int ListLength(LinkList L)
{ /* ������������L��Ԫ�ظ��� */
	return L.len;
}

Position GetHead(LinkList L)
{ /* ������������L��ͷ����λ�� */
	return L.head;
}

Position GetLast(LinkList L)
{ /* ������������L�����һ������λ�� */
	return L.tail;
}

Position NextPos(Link p)
{ /* ��֪pָ����������L�е�һ����㣬����p��ָ����ֱ�Ӻ�̵�λ�� */
	/* ���޺�̣��򷵻�NULL */
	return p->next;
}

Status LocatePos(LinkList L, int i, Link *p)
{ /* ����pָʾ��������L�е�i������λ�ã�������OK��iֵ���Ϸ�ʱ����ERROR */
	/* i=0Ϊͷ��� */
	int j;
	if (i<0 || i>L.len)
		return ERROR;
	else
	{
		*p = L.head;
		for (j = 1; j <= i; j++)
			*p = (*p)->next;
		return OK;
	}
}

Position LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{ /* ������������L�е�1����e���㺯��compare()�ж���ϵ��Ԫ�ص�λ�ã� */
	/* ��������������Ԫ�أ��򷵻�NULL */
	Link p = L.head;
	do
	p = p->next;
	while (p && !(compare(p->data, e))); /* û����β��û�ҵ������ϵ��Ԫ�� */
	return p;
}

Status ListTraverse(LinkList L, void(*visit)(ElemType))
{ /* ���ζ�L��ÿ������Ԫ�ص��ú���visit()��һ��visit()ʧ�ܣ������ʧ�� */
	Link p = L.head->next;
	int j;
	for (j = 1; j <= L.len; j++)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

Status OrderInsert(LinkList *L, ElemType e, int(*comp)(ElemType, ElemType))
{ /* ��֪LΪ��������������Ԫ��e���ǽ��������L�С�������һԪ����ʽ�� */
	Link o, p, q;
	q = (*L).head;
	p = q->next;
	while (p != NULL&&comp(p->data, e)<0) /* p���Ǳ�β��Ԫ��ֵС��e */
	{
		q = p;
		p = p->next;
	}
	o = (Link)malloc(sizeof(LNode)); /* ���ɽ�� */
	o->data = e; /* ��ֵ */
	q->next = o; /* ���� */
	o->next = p;
	(*L).len++; /* ����1 */
	if (!p) /* ���ڱ�β */
		(*L).tail = o; /* �޸�β��� */
	return OK;
}

Status LocateElemP(LinkList L, ElemType e, Position *q, int(*compare)(ElemType, ElemType))
{ /* ����������L�д�����e�����ж�����compare()ȡֵΪ0��Ԫ�أ���qָʾL�� */
	/* ��һ��ֵΪe�Ľ���λ�ã�������TRUE������qָʾ��һ����e�����ж����� */
	/* compare()ȡֵ>0��Ԫ�ص�ǰ����λ�á�������FALSE��������һԪ����ʽ�� */
	Link p = L.head, pp;
	do
	{
		pp = p;
		p = p->next;
	} while (p && (compare(p->data, e)<0)); /* û����β��p->data.expn<e.expn */
	if (!p || compare(p->data, e)>0) /* ����β��compare(p->data,e)>0 */
	{
		*q = pp;
		return FALSE;
	}
	else /* �ҵ� */
	{
		*q = p;
		return TRUE;
	}
}

/* ʹ�����еĶ��л������� */
/* bo3-2.c ������(�洢�ṹ��c3-2.h����)�Ļ�������(9��) */
Status InitQueue(LinkQueue *Q)
{ /* ����һ���ն���Q */
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
	if (!(*Q).front)
		exit(OVERFLOW);
	(*Q).front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue *Q)
{ /* ���ٶ���Q(���ۿշ����) */
	while ((*Q).front)
	{
		(*Q).rear = (*Q).front->next;
		free((*Q).front);
		(*Q).front = (*Q).rear;
	}
	return OK;
}

Status ClearQueue(LinkQueue *Q)
{ /* ��Q��Ϊ�ն��� */
	QueuePtr p, q;
	(*Q).rear = (*Q).front;
	p = (*Q).front->next;
	(*Q).front->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	return OK;
}

Status QueueEmpty(LinkQueue Q)
{ /* ��QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

int QueueLength(LinkQueue Q)
{ /* ����еĳ��� */
	int i = 0;
	QueuePtr p;
	p = Q.front;
	while (Q.rear != p)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status GetHead_Q(LinkQueue Q, QElemType *e) /* ������bo2-6.c���� */
{ /* �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR */
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	*e = p->data;
	return OK;
}

Status EnQueue(LinkQueue *Q, QElemType e)
{ /* ����Ԫ��eΪQ���µĶ�βԪ�� */
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) /* �洢����ʧ�� */
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	(*Q).rear->next = p;
	(*Q).rear = p;
	return OK;
}

Status DeQueue(LinkQueue *Q, QElemType *e)
{ /* �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR */
	QueuePtr p;
	if ((*Q).front == (*Q).rear)
		return ERROR;
	p = (*Q).front->next;
	*e = p->data;
	(*Q).front->next = p->next;
	if ((*Q).rear == p)
		(*Q).rear = (*Q).front;
	free(p);
	return OK;
}

Status QueueTraverse(LinkQueue Q, void(*vi)(QElemType))
{ /* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi()��һ��viʧ��,�����ʧ�� */
	QueuePtr p;
	p = Q.front->next;
	while (p)
	{
		vi(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
typedef LinkList EventList; /* �¼��������ͣ�����Ϊ�������� */
ElemType GetCurElem(Link p)
{ /* ��֪pָ�����������е�һ����㣬����p��ָ���������Ԫ�ص�ֵ */
	return p->data;
}


/* �������õ�����Ҫ����(ȫ��)���㷨3.7 */
EventList ev; /* �¼��� */
Event en; /* �¼� */
Event et; /* ��ʱ���� */
LinkQueue* q=(LinkQueue*)malloc(Qu*sizeof(LinkQueue));;//[Qu]; /* Qu���ͻ����� */
QElemType customer; /* �ͻ���¼ */
int TotalTime=0,CustomerNum=0; /* �ۼƿͻ�����ʱ��,�ͻ���(��ֵΪ0) */
int CloseTime=480; /* ����Ӫҵʱ��(��λ�Ƿ�) */
int n,m;//�������ͷ������

int cmp(Event a,Event b)
{ /* ���¼�a�ķ���ʱ��<��=��>�¼�b�ķ���ʱ�̷ֱ𷵻�-1��0��1 */
	if(a.OccurTime==b.OccurTime)
		return 0;
	else
		return (a.OccurTime-b.OccurTime)/abs(a.OccurTime-b.OccurTime);
}

void OpenForDay()
{ /* ��ʼ������ */
	int i;
	InitList(&ev); /* ��ʼ���¼�����Ϊ�� */
	en.OccurTime=0; /* �趨��һ���ͻ������¼� */
	en.NType=Qu; /* ���� */
	OrderInsert(&ev,en,cmp); /* �����¼��� */
	for(i=0;i<Qu;++i) /* �ÿն��� */
		InitQueue(&q[i]);
}

void Random(int *d,int *i)
{
	*d=rand()%Blsj+1; /* 1��Blsj֮�������� */
	*i=rand()%Khjg+1; /* 1��Khjg֮�������� */
}

int Minimum(LinkQueue Q[]) /* ������̶��е���� */
{
	//int l[Qu];
	int* l=(int*)malloc(Qu*sizeof(int));
	int i,k;
	for(i=0;i<Qu;i++)
		l[i]=QueueLength(Q[i]);
	k=0;
	for(i=1;i<Qu;i++)
		if(l[i]<l[0])
		{
			l[0]=l[i];
			k=i;
		}
		return k;
}

void CustomerArrived()
{ /* ����ͻ������¼���en.NType=Qu */
	QElemType f;
	int durtime,intertime,i;
	++CustomerNum;
	Random(&durtime,&intertime); /* ��������� */
	et.OccurTime=en.OccurTime+intertime; /* ��һ�ͻ�����ʱ�� */
	et.NType=Qu; /* ������ֻ��һ���ͻ������¼� */
	if(et.OccurTime<CloseTime) /* ������δ���ţ������¼��� */
		OrderInsert(&ev,et,cmp);
	i=Minimum(q); /* �󳤶���̶��е����,�ȳ�Ϊ��С����� */
	f.ArrivalTime=en.OccurTime;
	f.Duration=durtime;
	EnQueue(&q[i],f);
	if(QueueLength(q[i])==1)
	{
		et.OccurTime=en.OccurTime+durtime;
		et.NType=i;
		OrderInsert(&ev,et,cmp); /* �趨��i���е�һ���뿪�¼��������¼��� */
	}
}

void CustomerDeparture()
{ /* ����ͻ��뿪�¼���en.NTyPe<Qu */
	int i;
	i=en.NType;
	DeQueue(&q[i],&customer); /* ɾ����i���е���ͷ�ͻ� */
	TotalTime+=en.OccurTime-customer.ArrivalTime; /* �ۼƿͻ�����ʱ�� */
	if(!QueueEmpty(q[i]))
	{ /* �趨��i���е�һ���뿪�¼��������¼��� */
		GetHead_Q(q[i],&customer);
		et.OccurTime=en.OccurTime+customer.Duration;
		et.NType=i;
		OrderInsert(&ev,et,cmp);
	}
}

void Bank_Simulation()
{
	Link p;
	OpenForDay(); /* ��ʼ�� */
	while(!ListEmpty(ev))
	{
		Link head = GetHead(ev);
		DelFirst(&ev,head,&p);
		en.OccurTime = GetCurElem(p).OccurTime;
		en.NType = GetCurElem(p).NType;
		if(en.NType==Qu)
			CustomerArrived(); /* ����ͻ������¼� */
		else
			CustomerDeparture(); /* ����ͻ��뿪�¼� */
	} /* ���㲢���ƽ������ʱ�� */
	//printf("�˿�����:%d, ���й˿͹���ʱ:%d����, ƽ��ÿ�˺�ʱ: %d����\n",CustomerNum,TotalTime,TotalTime/CustomerNum);
}

void main()
{
	int j;
	cout<<"�����봰������";
	cin>>Qu;
	cout<<"��������������";
	cin>>m;
	srand((unsigned)time(NULL));
	int i;
	int total=0,ave;
	for(i=0;i<m;i++)
	{
		TotalTime=0;CustomerNum=0;
		Bank_Simulation();
		total=total+TotalTime/CustomerNum;
	}
	ave=total/m;
	cout<<"����m�εĿͻ�ƽ������ʱ���ƽ��ֵΪ��"<<ave<<"����"<<endl;
	system("pause");
}
