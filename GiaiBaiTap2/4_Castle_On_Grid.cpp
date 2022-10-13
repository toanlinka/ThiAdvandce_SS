#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n;
int b_x,b_y,g_x,g_y;
char a[101][101];
int Free[101][101];
int Step[101][101];
int dx[]={0,-1,1,0};
int dy[]={-1,0,0,1};
queue <pair<int,int> > q;

int BFS(int x,int y,int g_x, int g_y){
	q.push({x,y});
	Free[x][y]=1;
	while(!q.empty()){
		pair<int,int> top = q.front();
		q.pop();
		for(int k=0;k<4;k++){
			int count = 1;
			while(count<=n){
				int i1 = top.first + dx[k]*count;
				int j1 = top.second + dy[k]*count;
				count++;
				if(a[i1][j1]=='X'||i1<0||i1>=n||j1<0||j1>=n){
					break;
				}
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
	cin>>b_x>>b_y>>g_x>>g_y;
	cout<<BFS(b_x,b_y,g_x,g_y);
	return 0;
}
