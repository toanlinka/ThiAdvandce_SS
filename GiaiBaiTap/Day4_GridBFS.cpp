#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int R,C,r,c;
int path1,path2,path3;
int x_k,y_k, d_x,d_y,e_x,e_y;
char a[6][100];
int Free[6][100];
int Step[6][100];
queue <pair<int,int> > q;
int dx[]={0,-1,1,0};
int dy[]={-1,0,0,1};

void BFS(int i,int j){
	q.push({i,j});
	Free[i][j]=1;
	while(!q.empty()){
		pair<int,int> top = q.front();
		q.pop();
		for(int k =0;k<4;k++){
			int i1 = top.first + dx[k];
			int j1 = top.second + dy[k];
			if(i1>=1 && i1<=R && j1>=1 && j1<=C && a[i1][j1]!='X' && Free[i1][j1]==0){
				Step[i1][j1]=Step[top.first][top.second]+1;
				q.push({i1,j1});
				Free[i1][j1]=1;
			}
		}
	}
}

int main(){
	cin>>R>>C>>r>>c;
	
	memset(Free,0,sizeof(Free));
	memset(Step,0,sizeof(Step));
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			cin>>a[i][j];
			if(a[i][j]=='a'){
				x_k = i;
				y_k = j;
			}
			if(a[i][j]=='A'){
				d_x = i;
				d_y = j;
			}
			if(a[i][j]=='O'){
				e_x = i;
				e_y = j;
			}	
		}
	}
	BFS(r,c);
	path1 = Step[x_k][y_k];
	memset(Free,0,sizeof(Free));
	memset(Step,0,sizeof(Step));
	BFS(x_k,y_k);
	path2 = Step[d_x][d_y];
	memset(Free,0,sizeof(Free));
	memset(Step,0,sizeof(Step));
	BFS(d_x,d_y);
	path3 = Step[e_x][e_y];
	
	cout<<path1+path2+path3;
	return 0;
}
