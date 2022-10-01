#include <bits/stdc++.h>
using namespace std;
int n,m;
int dx[]={0,-1,1,0};
int dy[]={-1,0,0,1};
char a[1001][1001];
int Free[1001][1001];
queue <pair<int,int> > q;
stack <pair<int,int> > st;


void dfs(int i, int j){
	Free[i][j] =1;
	for(int k=0;k<4;k++){
		int i1 = i+dx[k];
		int j1 = j+dy[k];
		if(i1>=1 && i1<=n && j1>=1 && j1<=m && Free[i1][j1]==0 && a[i1][j1] == 'x'){
			dfs(i1,j1);
		}
	}
}

void dfs2(int i, int j){
	st.push({i,j});
	Free[i][j]=1;	
	while(!st.empty()){
		pair<int,int> top = st.top();
		st.pop();
		for(int k=0;k<4;k++){
			int i1 = top.first +dx[k];
			int j1 = top.second +dy[k];
			if(i1>=1 && i1<=n && j1>=1 && j1<=m && 
			   Free[i1][j1]==0 && a[i1][j1]=='x'){
				Free[i1][j1]=1;
				st.push({i,j});
				st.push({i1,j1});
				break;
			}
		}
	}
}

void bfs(int i, int j){
	q.push({i,j});
	Free[i][j]=1;
	while(!q.empty()){
		pair<int,int> top = q.front();
		q.pop();
		for(int k =0; k<4;k++){
			int i1 = top.first + dx[k];
			int j1 = top.second + dy[k];
			if(i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1]=='x' && Free[i1][j1]==0){
				q.push({i1,j1});
				Free[i1][j1]=1;
			}
		}
	}
}

int main(){
	int x1, y1, x2, y2;
	int slt = 0;
	memset(Free,0,sizeof(Free));
	memset(a,0,sizeof(a));
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(Free[i][j]==0 && a[i][j]=='x'){
				slt++;
				dfs2(i,j);
			}
		}
	}
	cout<<"SLT: "<<slt;
	
	return 0;
}
