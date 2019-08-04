#include<iostream>
using namespace std;

int main()
{
	void rightmove(int*a,int n,int m);
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	rightmove(a,10,3);
	for(int i=0;i<10;i++)
		cout<<a[i]<<' ';
	system("pause");
	return 0;
}

void rightmove(int*a,int n,int m)
{
	int i,j,k,t;
	for(i=n-m,j=0;i<n;i++,j++)
	{
		t=a[i];
		a[i]=a[j];
		a[j]=i;
	}
	k=m;
	for(i=n-m;i<n;i++)
	{
		for(j=i;j>k;j--)
		{
			t=a[j-1];
			a[j-1]=a[j];
			a[j]=t;
		}
		k++;
	}
}