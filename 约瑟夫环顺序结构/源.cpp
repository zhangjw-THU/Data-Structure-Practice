#include<iostream>
using namespace std;

struct node{
	int id;
	int num;
};

int main()
{
	int n,m,j,i,k,l,t;
	cin>>n;
	node*p;
	p=(node*)malloc(n*sizeof(node));
	for(i=0;i<n;i++)
	{
		cin>>p[i].num;
		p[i].id=i+1;
	}
	cin>>m;
	cout<<"node:  ";
	t=0;
	for(i=0,l=n;i<n;i++,l--)
	{
		t=(m+t-1)%l;
		cout<<p[t].id<<"  ";
		m=p[t].num;
		for(j=t+1;j<l;j++)
		{
			p[j-1].id=p[j].id;
			p[j-1].num=p[j].num;
		}
	}
	system("pause");
	return 0;
}