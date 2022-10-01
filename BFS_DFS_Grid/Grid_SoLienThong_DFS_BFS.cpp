//Grid: So lien thong (BFS-DFS)
#include <bits/stdc++.h>
using namespace std;

int n,m;
char a[1001][1001];
int Free[1001][1001];
queue <pair<int,int> > q;

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

void dfs(int i, int j){
	Free[i][j]=1;
	for(int k=0;k<4;k++){
		int i1= i+dx[k];
		int j1= j+dy[k];
		if(i1>=1 && i1<=n && j1>=1 && j1<=m && 
		  a[i1][j1]=='x' && Free[i1][j1]==0){
			dfs(i1,j1);
		}
	}
}

void bfs(int i, int j){
	q.push({i,j});
	Free[i][j]=1;
	
	while(!q.empty()){
		pair <int,int> top = q.front();
		q.pop();
		for(int k = 0; k<4;k++){
			int i1 = top.first +dx[k];
			int j1 = top.second +dy[k];
			if(i1>=1 && i1<=n && j1>=1 && j1<=m && 
			   a[i1][j1]=='x' && Free[i1][j1]==0){
				Free[i1][j1]=1;
				q.push({i1,j1});
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	memset(Free,0,sizeof(Free));
	
	int slt = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='x' && Free[i][j]==0){
				dfs(i,j);
				++slt;
			}
		}
	}
	cout<<"SLT: "<<slt;
	
	return 0;
}
