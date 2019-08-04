#include<iostream>
using namespace std;
struct list{
	list* next;
	int node;
};

void main()
{
	int i,j,n;
	list*p,*t,*q,*v;
	p=(list*)malloc(sizeof(list));
	q=p;
	cin>>n;
	(*p).node=n;
	for(i=0;i<n;i++)
	{
		t=(list*)malloc(sizeof(list));
		q->next=t;
		q=t;
		cin>>(q->node);
	}
	q->next=NULL;
	q=p->next;
	t=q->next;
	q->next=NULL;
	for(i=0;i<n-1;i++)
	{
		v=t->next;
		t->next=q;
		q=t;
		p->next=t;
		t=v;
	}
	q=p->next;
	for(i=0;i<n;i++)
	{
		cout<<q->node;	
		q=q->next;
	}
	for(i=0;i<=n;i++)
	{
		q=p->next;
		free(p);
		p=q;
	}
	system("pause");
}


