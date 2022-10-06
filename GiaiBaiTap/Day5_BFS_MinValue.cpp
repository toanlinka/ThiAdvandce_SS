//link: https://www.spoj.com/problems/SERGRID/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
int a[100][100];
int Free[100][100];
int Step[100][100];
queue <pair<int,int> > q;
int dx[]={0,-1,1,0};
int dy[]={-1,0,0,1};

int BFS(int x,int y){
	q.push({x,y});
	Free[x][y]=1;
	while(!q.empty()){
		pair<int,int> top = q.front();
		q.pop();
		int value = a[top.first][top.second];
		for(int k=0;k<4;k++){
			int i1 =top.first + dx[k]*value;
			int j1 = top.second +dy[k]*value;
			if(i1>=1 && i1<=n && j1>=1 && j1<=m && Free[i1][j1]==0){
				Step[i1][j1]=Step[top.first][top.second] + 1;
				q.push({i1,j1});
				Free[i1][j1]=1;
				if(i1==n&&j1==m){
					return Step[i1][j1];
				}
			}
		}
	}
	return 0;
}

int main(){
	memset(Free,0,sizeof(Free));
	memset(Step,0,sizeof(Step));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	cout<<"Ket qua: "<<BFS(1,1);
	
	return 0;
}
