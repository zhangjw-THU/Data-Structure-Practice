#include<iostream>
using namespace std;

struct qlist
{
	int min,max;
};

void merge(int*a,int p,int q,int r)
{
	int i,j,k,n1,n2;
	int *front,*back;
	n1=q-p+1;
	n2=r-q;
	front=(int*)malloc(n1*sizeof(int));
	back=(int*)malloc(n2*sizeof(int));
	for(i=0;i<n1;i++)
	{
		front[i]=a[p+i];
	}
	for(i=0;i<n2;i++)
	{
		back[i]=a[q+i+1];
	}
	i=0;j=0;
	k=p;
	while(i<n1&&j<n2)
	{
		if(front[i]<back[j])
		{
			a[k++]=front[i++];
		}
		else{
			a[k++]=back[j++];
		}
	}
	while(i<n1)
	{
		a[k++]=front[i++];
	}
	while(j<n2)
	{
		a[k++]=back[j++];
	}
	free(front);
	free(back);

}

void mergesort(int*a,int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
} 

int main()
{
	int n,m,al,bl,i,k,e,t;
	int*a,*b;
	cin>>n>>m;
	qlist*c;
	a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		a[i]=0;
	a[-1]=0;
	b=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		b[i]=0;
	b[-1]=0;
	for(i=0,al=0,bl=0;i<n;i++)
	{
		cin>>e;
		if(e>=0)
		{
			a[al++]=e;
		}
		else
		{
			b[bl++]=-e;
		}
	}
	mergesort(a,0,al-1);
	mergesort(b,0,bl-1);
	c=(qlist*)malloc(m*sizeof(qlist));
	for(i=0;i<m;i++)
	{
		cin>>c[i].min>>c[i].max;
	}
	int*an,*bn;
	an=(int*)malloc((a[al-1]+1)*sizeof(int));
	for(i=0;i<a[al-1]+1;i++)
		an[i]=0;
	bn=(int*)malloc((b[bl-1]+1)*sizeof(int));
	for(i=0;i<b[bl-1]+1;i++)
		bn[i]=0;
	
	for(i=0,k=0,t=0;i<=a[al-1];i++)
	{
		if(i==a[k])
		{
			t++;
			an[i]=t;
			k++;
		}
		else
		{
			an[i]=t;
		}
	}
	for(i=0,k=0,t=0;i<=b[bl-1];i++)
	{
		if(i==b[k])
		{
			t++;
			bn[i]=t;
			k++;
		}
		else
		{
			bn[i]=t;
		}
	}
	int l;
	for(i=0;i<m;i++)
	{
		if(c[i].max<-b[bl-1])
		{
			l=0;
			cout<<l;
			continue;
		}
		if(c[i].min>a[al-1])
		{
			l=0;
			cout<<l;
			continue;
		}
		if(c[i].max>a[al-1])
			c[i].max=a[al-1];
		if(c[i].min<-b[bl-1])
			c[i].min=-b[bl-1];
		if(c[i].min==0)
			l=an[c[i].max];
		if(c[i].min>0)
				l=an[c[i].max]-an[c[i].min-1];
		if(c[i].max<0)
		{
			l=bn[-c[i].min]-bn[-c[i].max-1];
		}
		if(c[i].min<0&&c[i].max>0)
		{
			l=an[c[i].max]+bn[-c[i].min];
		}
		cout<<l<<endl;
	}
	system("pause");
	free(a);
	free(b);
	free(c);
	free(an);
	free(bn);
	return 0;
}