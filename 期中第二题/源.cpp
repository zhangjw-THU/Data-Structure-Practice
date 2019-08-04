#include<iostream>
using namespace std;
void rain(int** &water,int x,int y,int N,int M)
{
	water[x][y]=0;
	for(int i=-1;i<=1;i++)
	{
		for(int j=-1;j<=1;j++)
		{
			int nx=x+i;
			int ny=y+j;
			if(1<=nx&&nx<=N&&1<=ny&&ny<=M&&water[nx][ny]==1)
				rain(water,nx,ny,N,M);
		}
	}
}

int main()
{
	int N,M,num,i,j;
	cin>>N>>M;
	char t;
	int**water;
	water=(int**)malloc((N+2)*sizeof(int*));
	for(i=0;i<N+2;i++)
	{
		water[i]=(int*)malloc((M+2)*sizeof(int));
	}
	cin.get();
	num=0;
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=M;j++)
		{
			t=cin.get();
			if(t=='w')
			{
				water[i][j]=1;
				num++;
			}
			else
			{
				if(t=='.')
					water[i][j]=0;
			}
		}
		cin.get();
	}
	for(i=0;i<N+2;i++)
	{
		water[i][0]=0;
		water[i][M+1]=0;
	}
	for(j=0;j<M+2;j++)
	{
		water[0][j]=0;
		water[N+1][j]=0;
	}
	num=0;
	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
			if(water[i][j]==1)
			{
				rain(water,i,j,N,M);
				num++;
			}
	cout<<num<<endl;
	//system("pause");
	return 0;
}