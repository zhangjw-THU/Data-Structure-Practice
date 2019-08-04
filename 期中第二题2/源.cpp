#include <stdlib.h>
#include <stdio.h>
const int MAX_N = 50;
const int MAX_M = 50;
int M, N;
char field[MAX_N][MAX_M];
void dfs(int x, int y){
	field[x][y] = '.';
	for(int dx=-1; dx<=1; dx++){
 for(int dy=-1; dy<=1; dy++){
 int nx = dx+x, ny = dy+y;
 if(0<=nx && nx<N && 0<=ny && ny<M && field[nx][ny] == 'w'){
 dfs(nx, ny);
 }
 }
	}
}
void solve(){
	int res = 0;
	for(int i=0; i<N; i++){
 for(int j=0; j<M; j++){
 if(field[i][i] == 'w'){
 dfs(i, j);
 res++;
 }
 }
	}
	printf("%d\n", res);
}
int main(){
	scanf("%d %d", &N, &M);
	getchar();
	for(int i=0; i<N; i++)
	{
 for(int j=0; j<M; j++){
	  field[i][j]=getchar();
 }
 getchar();
	}
	solve();
	system("pause");
	return 0;
}