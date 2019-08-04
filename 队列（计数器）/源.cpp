#include<iostream>
using namespace std;
#define Max 10
struct type{
	int date[Max];
	int front,count;
};
void InitQueue(type *&qu)
{
	qu=(type*)malloc(sizeof(type));
	qu->front=0;
	qu->count=0;
}
int QEmpty(type *qu)
{
	if(qu->count==0)
		return 1;
	else
		return 0;
}

int EnQueue(type *&qu,int x)
{
	if(qu->count==Max)
		return 0;
	else{
		qu->date[(qu->front+qu->count)%Max]=x;
		qu->count++;
		return 1;
	}
}
int QeQueue(type *&qu,int &x)
{
	if(qu->count==0)
		return 0;
	else
	{
		x=qu->date[qu->front];
		qu->front=(qu->front+1)%Max;
		qu->count--;
		return 1;
	}
}
struct SNode
{
	int date;
	SNode *next;
};
struct type2
{
	
	SNode* rear;
};
int EnQuenue(type2* &q,int x)
{
	SNode *s;
	s=(SNode*)malloc(sizeof(SNode));
	s->date=x;
	if(q->rear==NULL)
	{
		q->rear=s;
		q->rear->next=s;
	}
	else{
		s->next=q->rear->next;
		q->rear->next=s;
		q->rear=s;
	}
}

int DeQ(type2* &q,int x)
{
	SNode *p;
	if(q->rear==NULL)
		return 0;
	else{
		p=q->rear->next;
		x=p->date;
		if(p==q->rear)
			q->rear==NULL;
		else
			q->rear=p->next;
		free(p);
		return 1;
	}
}