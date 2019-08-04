#include<iostream>
using namespace std;
struct node
{
	
	int num;
	int id;
	node* next;
};
int main()
{
	int m,n,i,k,j;
	cin>>n;
	node*p,*q,*t;
	p=(node*)malloc(sizeof(node));
	t=p;
	p->id=1;
	cin>>p->num;
	for(i=0;i<n-1;i++)
	{
		q=(node*)malloc(sizeof(node));
		t->next=q;
		q->id=i+2;
		t=q;
		cin>>t->num;
	}
	t->next=p;
	cin>>m;
	cout<<"code:  ";
	for(i=0;i<n;i++)
	{
		for(j=1;j<m;j++)
		{
			t=p;
			p=p->next;
		}
		cout<<p->id<<" ";
		m=p->num;
		q=p;p=p->next;
		t->next=p;
		free(q);
	}
	system("pause");
	return 0;
}