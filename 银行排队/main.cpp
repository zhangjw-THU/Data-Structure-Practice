/* algo3-12.c 银行业务模拟。实现算法3.6、3.7的程序 */
// #define Qu 4 /* 客户队列数 */
#define Khjg 5 /* 两相邻到达的客户的时间间隔最大值 */
#define Blsj 30 /* 每个客户办理业务的时间最大值 */
#include"c1.h"
#include"C2-5.h"
#include"C3-2.h"
#include"stdio.h"
#include"time.h"
#include"stdlib.h"
#include<iostream>
using namespace std;
int Qu;
/* bo2-6.c 具有实用意义的线性链表(存储结构由c2-5.h定义)的24个基本操作 */
Status MakeNode(Link *p, ElemType e)
{ /* 分配由p指向的值为e的结点，并返回OK；若分配失败。则返回ERROR */
	*p = (Link)malloc(sizeof(LNode));
	if (!*p)
		return ERROR;
	(*p)->data = e;
	return OK;
}

void FreeNode(Link *p)
{ /* 释放p所指结点 */
	free(*p);
	*p = NULL;
}

Status InitList(LinkList *L)
{ /* 构造一个空的线性链表 */
	Link p;
	p = (Link)malloc(sizeof(LNode)); /* 生成头结点 */
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
{ /* 将线性链表L重置为空表，并释放原链表的结点空间 */
	Link p, q;
	if ((*L).head != (*L).tail)/* 不是空表 */
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
{ /* 销毁线性链表L，L不再存在 */
	ClearList(L); /* 清空链表 */
	FreeNode(&(*L).head);
	(*L).tail = NULL;
	(*L).len = 0;
	return OK;
}

Status InsFirst(LinkList *L, Link h, Link s) /* 形参增加L,因为需修改L */
{ /* h指向L的一个结点，把h当做头结点，将s所指结点插入在第一个结点之前 */
	s->next = h->next;
	h->next = s;
	if (h == (*L).tail) /* h指向尾结点 */
		(*L).tail = h->next; /* 修改尾指针 */
	(*L).len++;
	return OK;
}

Status DelFirst(LinkList *L, Link h, Link *q) /* 形参增加L,因为需修改L */
{ /* h指向L的一个结点，把h当做头结点，删除链表中的第一个结点并以q返回。 *
  /* 若链表为空(h指向尾结点)，q=NULL，返回FALSE */
	*q = (h)->next;
	if (*q) /* 链表非空 */
	{
		(h)->next = (*q)->next;
		if (!h->next) /* 删除尾结点 */
			(*L).tail = (h); /* 修改尾指针 */
		(*L).len--;
		return OK;
	}
	else
		return FALSE; /* 链表空 */
}

Status Append(LinkList *L, Link s)
{ /* 将指针s(s->data为第一个数据元素)所指(彼此以指针相链,以NULL结尾)的 */
	/* 一串结点链接在线性链表L的最后一个结点之后,并改变链表L的尾指针指向新 */
	/* 的尾结点 */
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

Status Remove(LinkList *L, Link *q)
{ /* 删除线性链表L中的尾结点并以q返回，改变链表L的尾指针指向新的尾结点 */
	Link p = (*L).head;
	if ((*L).len == 0) /* 空表 */
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
{ /* 已知p指向线性链表L中的一个结点，将s所指结点插入在p所指结点之前， */
	/* 并修改指针p指向新插入的结点 */
	Link q;
	q = PriorPos(*L, *p); /* q是p的前驱 */
	if (!q) /* p无前驱 */
		q = (*L).head;
	s->next = *p;
	q->next = s;
	*p = s;
	(*L).len++;
	return OK;
}

Status InsAfter(LinkList *L, Link *p, Link s)
{ /* 已知p指向线性链表L中的一个结点，将s所指结点插入在p所指结点之后， */
	/* 并修改指针p指向新插入的结点 */
	if (*p == (*L).tail) /* 修改尾指针 */
		(*L).tail = s;
	s->next = (*p)->next;
	(*p)->next = s;
	*p = s;
	(*L).len++;
	return OK;
}

Status SetCurElem(Link p, ElemType e)
{ /* 已知p指向线性链表中的一个结点，用e更新p所指结点中数据元素的值 */
	p->data = e;
	return OK;
}


Status ListEmpty(LinkList L)
{ /* 若线性链表L为空表，则返回TRUE，否则返回FALSE */
	if (L.len)
		return FALSE;
	else
		return TRUE;
}

int ListLength(LinkList L)
{ /* 返回线性链表L中元素个数 */
	return L.len;
}

Position GetHead(LinkList L)
{ /* 返回线性链表L中头结点的位置 */
	return L.head;
}

Position GetLast(LinkList L)
{ /* 返回线性链表L中最后一个结点的位置 */
	return L.tail;
}

Position NextPos(Link p)
{ /* 已知p指向线性链表L中的一个结点，返回p所指结点的直接后继的位置 */
	/* 若无后继，则返回NULL */
	return p->next;
}

Status LocatePos(LinkList L, int i, Link *p)
{ /* 返回p指示线性链表L中第i个结点的位置，并返回OK，i值不合法时返回ERROR */
	/* i=0为头结点 */
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
{ /* 返回线性链表L中第1个与e满足函数compare()判定关系的元素的位置， */
	/* 若不存在这样的元素，则返回NULL */
	Link p = L.head;
	do
	p = p->next;
	while (p && !(compare(p->data, e))); /* 没到表尾且没找到满足关系的元素 */
	return p;
}

Status ListTraverse(LinkList L, void(*visit)(ElemType))
{ /* 依次对L的每个数据元素调用函数visit()。一旦visit()失败，则操作失败 */
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
{ /* 已知L为有序线性链表，将元素e按非降序插入在L中。（用于一元多项式） */
	Link o, p, q;
	q = (*L).head;
	p = q->next;
	while (p != NULL&&comp(p->data, e)<0) /* p不是表尾且元素值小于e */
	{
		q = p;
		p = p->next;
	}
	o = (Link)malloc(sizeof(LNode)); /* 生成结点 */
	o->data = e; /* 赋值 */
	q->next = o; /* 插入 */
	o->next = p;
	(*L).len++; /* 表长加1 */
	if (!p) /* 插在表尾 */
		(*L).tail = o; /* 修改尾结点 */
	return OK;
}

Status LocateElemP(LinkList L, ElemType e, Position *q, int(*compare)(ElemType, ElemType))
{ /* 若升序链表L中存在与e满足判定函数compare()取值为0的元素，则q指示L中 */
	/* 第一个值为e的结点的位置，并返回TRUE；否则q指示第一个与e满足判定函数 */
	/* compare()取值>0的元素的前驱的位置。并返回FALSE。（用于一元多项式） */
	Link p = L.head, pp;
	do
	{
		pp = p;
		p = p->next;
	} while (p && (compare(p->data, e)<0)); /* 没到表尾且p->data.expn<e.expn */
	if (!p || compare(p->data, e)>0) /* 到表尾或compare(p->data,e)>0 */
	{
		*q = pp;
		return FALSE;
	}
	else /* 找到 */
	{
		*q = p;
		return TRUE;
	}
}

/* 使用已有的队列基本操作 */
/* bo3-2.c 链队列(存储结构由c3-2.h定义)的基本操作(9个) */
Status InitQueue(LinkQueue *Q)
{ /* 构造一个空队列Q */
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
	if (!(*Q).front)
		exit(OVERFLOW);
	(*Q).front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue *Q)
{ /* 销毁队列Q(无论空否均可) */
	while ((*Q).front)
	{
		(*Q).rear = (*Q).front->next;
		free((*Q).front);
		(*Q).front = (*Q).rear;
	}
	return OK;
}

Status ClearQueue(LinkQueue *Q)
{ /* 将Q清为空队列 */
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
{ /* 若Q为空队列,则返回TRUE,否则返回FALSE */
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

int QueueLength(LinkQueue Q)
{ /* 求队列的长度 */
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

Status GetHead_Q(LinkQueue Q, QElemType *e) /* 避免与bo2-6.c重名 */
{ /* 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR */
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	*e = p->data;
	return OK;
}

Status EnQueue(LinkQueue *Q, QElemType e)
{ /* 插入元素e为Q的新的队尾元素 */
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) /* 存储分配失败 */
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	(*Q).rear->next = p;
	(*Q).rear = p;
	return OK;
}

Status DeQueue(LinkQueue *Q, QElemType *e)
{ /* 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR */
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
{ /* 从队头到队尾依次对队列Q中每个元素调用函数vi()。一旦vi失败,则操作失败 */
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
typedef LinkList EventList; /* 事件链表类型，定义为有序链表 */
ElemType GetCurElem(Link p)
{ /* 已知p指向线性链表中的一个结点，返回p所指结点中数据元素的值 */
	return p->data;
}


/* 程序中用到的主要变量(全局)。算法3.7 */
EventList ev; /* 事件表 */
Event en; /* 事件 */
Event et; /* 临时变量 */
LinkQueue* q=(LinkQueue*)malloc(Qu*sizeof(LinkQueue));;//[Qu]; /* Qu个客户队列 */
QElemType customer; /* 客户记录 */
int TotalTime=0,CustomerNum=0; /* 累计客户逗留时间,客户数(初值为0) */
int CloseTime=480; /* 银行营业时间(单位是分) */
int n,m;//窗口数和仿真次数

int cmp(Event a,Event b)
{ /* 依事件a的发生时刻<、=或>事件b的发生时刻分别返回-1、0或1 */
	if(a.OccurTime==b.OccurTime)
		return 0;
	else
		return (a.OccurTime-b.OccurTime)/abs(a.OccurTime-b.OccurTime);
}

void OpenForDay()
{ /* 初始化操作 */
	int i;
	InitList(&ev); /* 初始化事件链表为空 */
	en.OccurTime=0; /* 设定第一个客户到达事件 */
	en.NType=Qu; /* 到达 */
	OrderInsert(&ev,en,cmp); /* 插入事件表 */
	for(i=0;i<Qu;++i) /* 置空队列 */
		InitQueue(&q[i]);
}

void Random(int *d,int *i)
{
	*d=rand()%Blsj+1; /* 1到Blsj之间的随机数 */
	*i=rand()%Khjg+1; /* 1到Khjg之间的随机数 */
}

int Minimum(LinkQueue Q[]) /* 返回最短队列的序号 */
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
{ /* 处理客户到达事件，en.NType=Qu */
	QElemType f;
	int durtime,intertime,i;
	++CustomerNum;
	Random(&durtime,&intertime); /* 生成随机数 */
	et.OccurTime=en.OccurTime+intertime; /* 下一客户到达时刻 */
	et.NType=Qu; /* 队列中只有一个客户到达事件 */
	if(et.OccurTime<CloseTime) /* 银行尚未关门，插入事件表 */
		OrderInsert(&ev,et,cmp);
	i=Minimum(q); /* 求长度最短队列的序号,等长为最小的序号 */
	f.ArrivalTime=en.OccurTime;
	f.Duration=durtime;
	EnQueue(&q[i],f);
	if(QueueLength(q[i])==1)
	{
		et.OccurTime=en.OccurTime+durtime;
		et.NType=i;
		OrderInsert(&ev,et,cmp); /* 设定第i队列的一个离开事件并插入事件表 */
	}
}

void CustomerDeparture()
{ /* 处理客户离开事件，en.NTyPe<Qu */
	int i;
	i=en.NType;
	DeQueue(&q[i],&customer); /* 删除第i队列的排头客户 */
	TotalTime+=en.OccurTime-customer.ArrivalTime; /* 累计客户逗留时间 */
	if(!QueueEmpty(q[i]))
	{ /* 设定第i队列的一个离开事件并插入事件表 */
		GetHead_Q(q[i],&customer);
		et.OccurTime=en.OccurTime+customer.Duration;
		et.NType=i;
		OrderInsert(&ev,et,cmp);
	}
}

void Bank_Simulation()
{
	Link p;
	OpenForDay(); /* 初始化 */
	while(!ListEmpty(ev))
	{
		Link head = GetHead(ev);
		DelFirst(&ev,head,&p);
		en.OccurTime = GetCurElem(p).OccurTime;
		en.NType = GetCurElem(p).NType;
		if(en.NType==Qu)
			CustomerArrived(); /* 处理客户到达事件 */
		else
			CustomerDeparture(); /* 处理客户离开事件 */
	} /* 计算并输出平均逗留时间 */
	//printf("顾客总数:%d, 所有顾客共耗时:%d分钟, 平均每人耗时: %d分钟\n",CustomerNum,TotalTime,TotalTime/CustomerNum);
}

void main()
{
	int j;
	cout<<"请输入窗口数：";
	cin>>Qu;
	cout<<"请输入仿真次数：";
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
	cout<<"仿真m次的客户平均逗留时间的平均值为："<<ave<<"分钟"<<endl;
	system("pause");
}
