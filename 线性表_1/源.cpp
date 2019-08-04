#include<iostream>
using namespace std;

struct qlist
{
	int min,max;
	int num;
};

int main()
{
	int n,m,i,k;
	int* nl;
	qlist*ml;
	cin>>n>>m;
	nl=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		cin>>nl[i];
	}
	ml=(qlist*)malloc(m*sizeof(qlist));
	for(i=0;i<m;i++)
	{
		cin>>ml[i].min>>ml[i].max;
		ml[i].num=0;
	}
	for(i=0;i<n;i++)
	{
		for(k=0;k<m;k++)
		{
			if(nl[i]>=ml[k].min&&nl[i]<=ml[k].max)
				ml[k].num++;
		}
	}
	for(i=0;i<m;i++)
		cout<<ml[i].num<<endl;
	free(nl);
	free(ml);
	system("pause");
	return 0;
}
