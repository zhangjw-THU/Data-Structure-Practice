#include<iostream>
using namespace std;

int main()
{
	int n,m,k,i,j;
	cin>>k;
	cin>>m>>n;
	int sum=0,max=0,ni=0,mj=0;
	int **a;//”√”⁄¥Ê∑≈æÿ’Ûa
	int last=0;
	int* col;
	col=(int*)malloc((k-1)*sizeof(int));
	for(i=0;i<k-1;i++)
		col[i]=0;
	a=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		*(a+i)=(int*)malloc(m*sizeof(int));
	if(m<k||n<k)
		return 0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	int r,c;
	if(n<=m)
	{
	for(r=0;r<n-k+1;r++)
	{
		for(i=0;i<k-1;i++)
		{
			for(j=r;j<r+k;j++)
			{
				col[i]+=a[j][i];
			}
			last+=col[i];
		}
		for(i=k-1;i<m;i++)
		{
			int q;
			q=i%(k-1);
			sum=last;
			last=last-col[q];
			for(j=r,col[q]=0;j<r+k;j++)
			{
				col[q]+=a[j][i];
			}
			last=last+col[q];
			sum+=col[q];
			if(sum>max)
			{
				max=sum;
				ni=r;
				mj=i-k+1;
			}
		}
	}
	}
	else
	{
		cout<<"else"<<endl;
		for(r=0;r<m-k+1;r++)
	{
		for(i=0;i<k-1;i++)
		{
			for(j=r;j<r+k;j++)
			{
				col[i]+=a[i][j];
			}
			last+=col[i];
		}
		for(i=k-1;i<n;i++)
		{
			int q;
			q=i%(k-1);
			sum=last;
			last=last-col[q];
			for(j=r,col[q]=0;j<r+k;j++)
			{
				col[q]+=a[i][j];
			}
			last=last+col[q];
			sum+=col[q];
			if(sum>max)
			{
				max=sum;
				mj=r;
				ni=i-k+1;
			}
		}
	}
	}
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
			cout<<a[i+ni][mj+j]<<' ';
		}
		cout<<endl;
	}
	free(col);
	for(i=0;i<n;i++)
		free(a[i]);
	free(a);
	system("pause");
	return 0;
}