#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;

struct node{
	char data;
	node* next;
};

int main()
{
	char s1[600],s2[600],t;
	node* str1,*str2,*p,*q;
	//������Ŀ�����������
	str1=(node*)malloc(sizeof(node));
	str2=(node*)malloc(sizeof(node));
	str1->next=NULL;
	str2->next=NULL;
	int i,j,n1,n2,n;
	for(i=0;(t=getchar())!='\n';i++)
		/*ԭ��Ӧ�û��С�&&i<100",�ж����������Ժ�oj�͹���ȥ��*/
	{
		s1[i]=t;
	}
	//�ж����������Ժ�oj�͹���ȥ�ˣ����Ǿ�ע����
	//if(i==100)
	//	for(;getchar()!='\n';);
	//if(i==0)
	//	return 0;
	for(j=0;(t=getchar())!='\n';j++)
	{
		s2[j]=t;
	}
	//if(j==0)
	//	for(;getchar()!='/n';);
	//if(j==0)
	//	return 0;
	for(;(s1[i-1]==s2[j-1])&&(i>0&&j>0);i--,j--)
	{
		p=str1;
		str1=(node*)malloc(sizeof(node));
		p->data=s1[i-1];
		str1->next=p;
		str2->next=p;
	}
	for(;i>0;i--)
	{
		p=str1;
		str1=(node*)malloc(sizeof(node));
		p->data=s1[i-1];
		str1->next=p;
	}
	for(;j>0;j--)
	{
		p=str2;
		str2=(node*)malloc(sizeof(node));
		p->data=s2[j-1];
		str2->next=p;
	}
	//����������Ľ������
	for(p=str1->next,n1=0;p!=NULL;)
	{
		n1++;
		p=p->next;
	}
	for(p=str2->next,n2=0;p!=NULL;)
	{
		n2++;
		p=p->next;
	}
	//���Ҷ���
	p=str1->next;
	q=str2->next;
	if(n1>n2)
	{
		for(;n1>n2;n1--)
		{
			p=p->next;
		}
	}
	else
	{
		if(n1<n2)
			for(;n1<n2;n2--)
			{
				q=q->next;
			}
	}
	//��ͬ��׺�ĵ�һ���ڵ�
	for(;p!=q;)
	{
		p=p->next;
		q=q->next;
	}
	//�󹫹��Ľ�����
	for(n=0;p!=NULL;p=p->next)
	{
		n++;
	}
	printf("%d\n",n);
	free(str1);
	free(str2);
	system("pause");
	return 0;
}