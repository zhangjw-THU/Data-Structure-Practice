#include<iostream>
#include<malloc.h>
#include<string.h>
#include<stdio.h>
using namespace std;

struct tree_node{
	int count;
	tree_node* next[62];
};

void creat_tree(tree_node& root,char* str)
{
	int len=strlen(str);
	tree_node* p=&root;
	tree_node* q;
	int id;
	
	for(int j=0;j<len;j++)
	{
		if(str[j]>=65)
	{
		if(str[j]>=97)
			id=str[j]-61;
		else{
			id=str[j]-55;
		}
	}
	else{
		id=str[j]-30;
	}
		if(p->next[id]==NULL)
		{
			q=(tree_node*)malloc(sizeof(tree_node));
			q->count=1;
			for(int i=0;i<62;i++)
				q->next[i]=NULL;
			p->next[id]=q;
			p=p->next[id];
		}
		else
		{
			p->next[id]->count++;
			p=p->next[id];
		}
	}
}
int findname(tree_node root,char *str)
{
	int len=strlen(str);
	tree_node* p=&root;
	int id;
	for(int j=0;j<len;j++)
	{
		if(str[j]>=65)
	{
		if(str[j]>=97)
			id=str[j]-61;
		else{
			id=str[j]-55;
		}
	}
	else{
		id=str[j]-30;
	}
		p=p->next[id];
		if(p==NULL)
			return 0;
	}
	return p->count;
}
int main()
{
	tree_node root;
	for(int i=0;i<62;i++)
		root.next[i]=NULL;
	root.count=0;
	char s[110];
	int num[60000],i,n;
	
	for(;;)
	{
		//gets(s);
		gets_s(s,111);
		if(strlen(s)==0)
			break;
		creat_tree(root,s);
	}
	for(i=0;;i++)
	{
		//gets(s);
		gets_s(s,111);
		if(strlen(s)==0)
			break;
		n=findname(root,s);
		num[i]=n;
	}
	for(int j=0;j<i;j++)
		cout<<num[j]<<endl;
	system("pause");
	return 0;
}
