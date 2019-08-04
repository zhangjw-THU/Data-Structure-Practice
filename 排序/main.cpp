#include<iostream>
using namespace std;

#define MAX 100

struct rec
{
	int key;
	int date;
};

typedef struct rec sqlist [MAX];

//≤Â»Î≈≈–Ú
void insertsort(sqlist r,int n)
{
	int i,j;
	for(i=2;i<=n;i++)
	{
		r[0]=r[i];
		j=i-1;
		while(r[0].key<r[j].key)
		{
			r[j+1]=r[j];
			j--;
		}
		r[j+1]=r[0];
	}
}
//œ£∂˚≈≈–Ú
void shellsort(sqlist r, int n)
{
	int i,j,gap;
	rec temp;
	gap=n/2;
	while(gap>0)
	{
		for(i=gap+1;i<=n;i++)
		{
			j=i-gap;
			while(j>0)
				if(r[j].key>r[j+gap].key)
				{
					temp=r[j];
					r[j]=r[j+gap];
					r[j+gap]=temp;
					j=j-gap;
				}
				else
					j=0;
		}
		gap=gap/2;
	}
}
//√∞≈›
void bubblesort(sqlist r,int n)
{
	int i,j,exchange;
	rec temp;
	for(i=1;i<=n-1;i++)
	{
		exchange=0;
		for(j=n;j>=i+1;j--)
			if(r[j].key<r[j-1].key)
			{
				temp=r[j];
				r[j]=r[j-1];
				r[j-1]=temp;
				exchange=1;
			}
			if(exchange==0)
				return;
	}
}
//√∞≈›≈≈–Ú
void bubblesortone(sqlist r,int n)
{
	int i,j,exchange;
	rec temp;
	for(i=n;i>=2;i--)
	{
		exchange=0;
		for(j=1;j<=i-1;j++)
		{
			if(r[j].key>r[j+1].key)
			{
				temp=r[j];
				r[j]=r[j+1];
				r[j+1]=temp;
				exchange=1;
			}
		}
		if(exchange==0)
			return;
	}
}
//øÏ≈≈–Ú
void quicksort(sqlist r,int s,int t)
{
	int i=s,j=t;
	if(s<t)
	{
		r[0]=r[s];//0µ„√ª”–¥Ê¥Ì£¨◊˜Œ™÷–◊™±‰¡ø”√
		do
		{
			while(j>i&&r[j].key>=r[0].key)
				j--;
			if(i<j)
			{
				r[i]=r[j];
				i++;
			}
			while(i<j&&r[i].key<=r[0].key)
				i++;
			if(i<j)
			{
				r[j]=r[i];
				j--;
			}
		}while(i<j);
		r[i]=r[0];
		quicksort(r,s,j-1);
		quicksort(r,j+1,t);
	}
}
//÷±Ω”—°‘Ò≈≈–Ú
void selectsort(sqlist r,int n)
{
	int i,j,k;
	struct rec temp;
	for(i=1;i<n;i++)
	{
		k=i;
		for(j=i+1;j<=n;j++)
		{
			if(r[j].key<r[k].key)
				k=j;
		}
		if(k!=i)
		{
			temp=r[k];
			r[k]=r[i];
			r[i]=temp;
		}
	}
}
//∂—≈≈–Ú
void sift(sqlist r,int l,int m)
{
	int i,j;
	rec x;
	i=1;
	j=2*i;
	x=r[i];
	while(j<m)
	{
		if(j<m && r[j].key<r[j+1].key)
			j++;
		if(x.key<r[j].key)
		{
			r[i]=r[j];
			i=j;
			j=2*i;
		}
		else
			j=m+1;
	}
	r[i]=x;
}
void heapsort(sqlist r,int n)
{
	int i;
	rec m;
	for(i=n/2;i>=1;i--)
		sift(r,i,n);
		for(i=n;i>=2;i--)
		{
			m=r[i];
			r[i]=r[1];
			r[1]=m;
			sift(r,1,i-1);
		}
}
//πÈ≤¢≈≈–Ú
void merge(sqlist r,int l,int m,int h,sqlist &r2)
{
	int i,j,k;
	k=1;
	i=1;
	j=m+1;

void main()
{
	sqlist r;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>r[i].key;
	//sertsort(r,n);
	//shellsort(r,n);
	//bubblesortone(r,n);
	//quicksort(r,1,n);
	//selectsort(r,n);
	heapsort(r,n);
	for(int i=1;i<=n;i++)
		cout<<r[i].key<<"  ";
	system("pause");
}
