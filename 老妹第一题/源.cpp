#include<iostream>
using namespace std;
const int MAXN=1000;
const int MAXM=1000;
const int MAX_WEIGHT=150;
struct Graph{
	int edge_time[100][100];
	int edge_bitcoin[100][100];
	int n,m;
};

void CreatGraph(Graph & G) 
{
	cin>>G.n>>G.m;
	for(int i=0;i<G.n;i++)
		for(int j=0;j<G.n;j++)
		{
			if(i==j)
			{
				G.edge_bitcoin[i][j]=0;
			    G.edge_time[i][j]=0;
			}
			else
			{
			    G.edge_bitcoin[i][j]=MAX_WEIGHT;
			    G.edge_time[i][j]=MAX_WEIGHT;
			}
		}
	int x,y,time,bitcoin;
	for(int i=0;i<G.m;i++)
	{
		cin>>x>>y>>time>>bitcoin;
		G.edge_time[x][y]=time;
		G.edge_time[y][x]=time;
		G.edge_bitcoin[x][y]=bitcoin;
		G.edge_bitcoin[y][x]=bitcoin;
	}
}
void Short(Graph G)
{
	int n=G.n;
	int cost_time[1000][1000];
	int cost_bitcoin[1000][1000];
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			cost_time[i][j]=G.edge_time[i][j];
			cost_bitcoin[i][j]=G.edge_bitcoin[i][j];
		}
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(cost_time[i][j]>(cost_time[i][k]+cost_bitcoin[k][j]))
				{
					cost_time[i][j]=cost_time[i][k]+cost_bitcoin[k][j];
				}
				if(cost_bitcoin[i][j]>(cost_bitcoin[i][k]+cost_bitcoin[k][j]))
				{
					cost_bitcoin[i][j]=cost_bitcoin[i][k]+cost_bitcoin[k][j];
				}
			}
	int t;
	int star[1000][2];
//	int cost[1000][1000];
	cin>>t;
	for(i=0;i<t;i++)
		cin>>star[i][0]>>star[i][1];
	for(i=0;i<t;i++)
		cout<<cost_time[star[i][0]][star[i][1]]<<" "<<cost_bitcoin[star[i][0]][star[i][1]]<<endl;
}
void main()
{
	Graph G;
	CreatGraph(G);
	Short(G);
}






