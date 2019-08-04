#include<iostream>
using namespace std;
void sort(char*a,int n)
{
	int i,j,k;
	char t;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
		
}
int main()
{
	int n,m;
	cin>>n>>m;
	cin.get();
	char*a,*b;
	char q;
	a=(char*)malloc(n*sizeof(char));
	b=(char*)malloc(m*sizeof(char));
	int  i,j,k;
	
	for(i=0;i<n;i++)
	{
		a[i]=cin.get();
	}
	sort(a,n);
	cin.get();
	for(i=0;i<m;i++)
	{b[i]=cin.get();
	}
	sort(b,m);
	cin.get();
	q=cin.get();
	int il,jl;
	il=0;jl=0;
	if(q=='j')
	{
		char s;
		cout<<"交集:";
		for(i=0,s=0;i<n;i++)
		{
			for(j=jl;j<m;j++)
			{
				if(a[i]==b[j])
				{
					if(s!=a[i])
					{
					cout<<a[i];
					jl=j;
					s=a[i];
					break;
					}
				}
			}
		}
	}
	else{
		if(q=='b')
		{
			char s;
			cout<<"并集:";
			for(i=0,j=0,s=NULL;i<n&&j<m;)
			{
				if(a[i]<b[j])
				{
					if(s!=a[i])
					{
					cout<<a[i];
					s=a[i];
					
					}i++;
				}
				else{
					if(a[i]==b[j])
					{
						if(s!=a[i])
						{
						cout<<a[i];
						
						
						s=a[i];
						}i++;j++;
					}
					else{
						if(s!=b[j])
						{
						cout<<b[j];
						
						s=b[j];
						}j++;
					}
				}
			}
			for(;i<n;i++)
			{
				if(s!=a[i])
				{
					cout<<a[i];
					s=a[i];
				}
			}
			for(;j<m;j++)
			{
				if(s!=b[j])
				{
					cout<<b[j];
					s=b[j];
				}
			}
		}
		else{
			if(q=='c')
			{
				char s;
				cout<<"差集：";
				for(s=NULL,i=0;i<n;i++)
				{
					int t=0;
					for(j=0;j<m;j++)
					{
						if(a[i]==b[j])
						{
							t=1;
						}
					}
					if(t==0)
					{
						if(s!=a[i])
						{
						cout<<a[i];
						s=a[i];
						}
					}
				}
			}
		}
	}
	cout<<endl;
	system("pause");
	return 0;
}
