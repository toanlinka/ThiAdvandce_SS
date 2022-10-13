#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n;
char a[101][101];
int Free[101][101];
int Step[101][101];
int dx[]={0,-1,1,0};
int dy[]={-1,0,0,1};
queue <pair<int,int> > q;

int BFS(int x,int y){
	q.push({x,y});
	Free[x][y]=1;
	while(!q.empty()){
		pair<int,int> top = q.front();
		q.pop();
		for(int k=0;k<4;k++){
			while()
			int i1 = top.first + dx[k];
			int j1 = top.second + dy[k];
			
			if(i1>=0 && i1<n && j1>=0 && j1<n && a[i1][j1]!='X' && Free[i1][j1]==0){
				Free[i1][j1]=1;
				q.push({i1,j1});
				Step[i1][j1] = Step[top.first][top.second] + 1;
				if(i1==g_x && j1 ==g_y){
					return Step[i1][j1];
				}
			}
		}
	}
	return -1;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	return 0;
}
