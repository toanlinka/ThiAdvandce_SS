#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int dx[]={0,-1,1,0};
int dy[]={-1,0,0,1};
int n,m,k,u,v;
char a[101][101];
int Free[101][101];
int Count[10][100][100];
queue <pair<int,int> > q;

void bfs(int i, int j,int k){
	q.push({i,j});
	a[i][j]='x';
	while(!q.empty()){
		pair<int,int> top = q.front();
		q.pop();
		for(int k =0; k<4;k++){
			int i1 = top.first + dx[k];
			int j1 = top.second + dy[k];
			if(i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1]=='o'){
				q.push({i1,j1});
				a[i1][j1]='x';
			}
		}
	}
}

int main(){
	memset(Free,0,sizeof(Free));
	memset(a,'o',sizeof(a));
	
	for(int i=1;i<=k;i++){
		cin>>u>>v;
		bfs(u,v,i);
	}
	
	return 0;
}
