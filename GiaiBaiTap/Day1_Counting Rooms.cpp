#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int dx[]={0,-1,1,0};
int dy[]={-1,0,0,1};
int n,m;
char a[1001][1001];
int Free[1001][1001];
queue <pair<int,int> > q;

void BFS(int i,int j){
	q.push({i,j});
	a[i][j]='#';
	while(!q.empty()){
		pair<int,int> u = q.front();
		q.pop();
		for(int k=0;k<4;k++){
			int i1 = u.first + dx[k];
			int j1 = u.second + dy[k];
			if(i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1]=='.'){
				q.push({i1,j1});
				a[i1][j1]='#';
			}
		}
	}
	
}

int main(){
	memset(Free,0,sizeof(Free));
	cin>>n>>m;
	int slt =0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='.'){
				BFS(i,j);
				slt++;
			}
		}
	}
	cout<<slt;
	
	return 0;
}
