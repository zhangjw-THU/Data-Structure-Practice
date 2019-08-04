#include<iostream>
using namespace std;

const int MAX_WEIGHT=150;
struct Graph{
	int edge_time[100][100];
	int edge_bitcoin[100][100];
	int n,m;
};
struct MGraph{
	int **edge_time;
	int **edge_bitcoin;
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
		G.edge_time[x-1][y-1]=time;
		G.edge_time[y-1][x-1]=time;
		G.edge_bitcoin[x-1][y-1]=bitcoin;
		G.edge_bitcoin[y-1][x-1]=bitcoin;
	}
}

int main()
{
	Graph G;
	CreatGraph(G);
	int n=G.n;
	int cost_time[100][100];
	int cost_bitcoin[100][100];
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
				if(cost_time[i][j]>(cost_time[i][k]+cost_time[k][j]))
				{
					cost_time[i][j]=cost_time[i][k]+cost_time[k][j];
				}
				if(cost_bitcoin[i][j]>(cost_bitcoin[i][k]+cost_bitcoin[k][j]))
				{
					cost_bitcoin[i][j]=cost_bitcoin[i][k]+cost_bitcoin[k][j];
				}
			}
	int t;
	int star[100][2];
	cin>>t;
	for(i=0;i<t;i++)
		cin>>star[i][0]>>star[i][1];
	for(i=0;i<t;i++)
		cout<<cost_time[star[i][0]-1][star[i][1]-1]<<" "<<cost_bitcoin[star[i][0]-1][star[i][1]-1]<<endl;

	system("pause");
	return 0;
}






