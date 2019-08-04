#include<iostream>
#include<malloc.h>
using namespace std;

struct BiTNode{//结点
	char data;
	BiTNode *lchild,*rchild;
};

void CreateBitree(BiTNode*& T)//构造函数
{
	char ch;
	ch=cin.get();
	if(ch==' ')T=NULL;
	else
	{
		if(!(T=(BiTNode*)malloc(sizeof(BiTNode))))exit(OVERFLOW);
		T->data=ch;
		CreateBitree(T->lchild);
		CreateBitree(T->rchild);
	}
}

void print0(BiTNode*& T)
{
	if(T!=NULL)
	{
		cout<<T->data;
		print0(T->lchild);
		print0(T->rchild);
	}
}
void print1(BiTNode*& T)
{
	if(T!=NULL)
	{
		print1(T->lchild);
		cout<<T->data;
		print1(T->rchild);
	}
}
void  print2(BiTNode*& T)
{
	if(T!=NULL)
	{
		print2(T->lchild);
		print2(T->rchild);
		cout<<T->data;
	}
}
void porder(BiTNode* T)//先续遍历二叉树
{
	BiTNode *St[50],*p;
	int top=-1;
	if(T!=NULL)
	{
		top++;
		St[top]=T;
		while(top>-1)
		{
			p=St[top];
			top--;
			cout<<p->data;
			if(p->rchild!=NULL)
			{
				top++;
				St[top]=p->rchild;
			}
			if(p->lchild!=NULL)
			{
				top++;
				St[top]=p->lchild;
			}

		}
	}
}
void psorder(BiTNode* t)//后续访问二叉树
{
	BiTNode  *St[50],*p;
	int flag,top=-1;
	do
	{
		while(t)
		{
			top++;
			St[top]=t;
			t=t->lchild;
		}
		p=NULL;
		flag=1;
		while(top!=-1&&flag)
		{
			t=St[top];
			if(t->rchild==p)
			{
				cout<<t->data;
				top--;
				p=t;
			}
			else
			{
				t=t->rchild;
				flag=0;
			}
		}

	}
	while(top!=-1);
}
void mporder(BiTNode* t)
{
	BiTNode  *St[50],*p;
	int top=0;
	St[top]=t;
	while(top>-1)
	{
		p=St[top];
		while(p)
		{
			top++;St[top]=p->lchild;
			p=p->lchild;
			
		}
		p=St[top];top--;
		if(top>-1){
			p=St[top];top--;
			cout<<p->data;
			top++;St[top]==p->rchild;
			
		}
	}
}
int level(BiTNode* t,char x,int h)//8.26
{
	int h1;
	if(t==NULL)
		return 0;
	else
	{
		if(t->data==x)
			return h;
	else
	{
		h1=level(t->lchild,x,h+1);
		if(h1!=0)
			return h1;
		else
		{
			return level(t->rchild,x,h+1);
		}
	}
	}

}
void translevel(BiTNode* t)
{
	struct node
	{
		BiTNode* vec[50];
		int f,r;
	};
	node Qu;
	Qu.f=0;
	Qu.r=0;
	if(t!=NULL)
	{
		cout<<t->data;
	}
	Qu.vec[Qu.r]=t;
	Qu.r=Qu.r+1;
	while(Qu.f<Qu.r)
	{
		t=Qu.vec[Qu.f];
		Qu.f++;
		if(t->lchild!=NULL)
		{
			cout<<t->lchild->data;
			Qu.vec[Qu.r]=t->lchild;
			Qu.r++;
		}
		if(t->rchild!=NULL)
		{
			cout<<t->rchild->data;
			Qu.vec[Qu.r]=t->rchild;
			Qu.r++;
		}
	}
	cout<<endl;
}

int main()
{
	BiTNode* T;
	CreateBitree(T);
	cout<<"先"<<endl;
	print0(T);
	porder(T);
	cout<<endl;

	cout<<"中"<<endl;
	print1(T);
	//mporder(T);
	cout<<endl;

	cout<<"后"<<endl;
	print2(T);
	psorder(T);
	cout<<endl;

	cout<<level(T,'D',1);
	cout<<endl;

	translevel(T);
	system("pause");
	return 0;
}