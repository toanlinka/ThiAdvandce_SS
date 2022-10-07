#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int n,m;
char a[50][50];
bool visited[100][100];
pair<int,int> parent[100][100];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool valid(int x,int y){
	if(x>=0 && x<=n && y>=0 && y<=m){
		return true;
	}
	return false;
}

void inp(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	memset(visited, 0, sizeof(visited));
}

int BFS(int x,int y){
	queue <pair<int,int> > q;
	q.push({x,y});
	visited[x][y]=true;
	while(!q.empty()){
		pair<int,int> top = q.front();
		q.pop();
		for(int k=0;k<4;k++){
			int i1 = top.first + dx[k];
			int j1 = top.second + dy[k];
			if(valid(i1,j1) && a[top.first][top.second]==a[i1][j1] && visited[i1][j1]==false){
				q.push({i1,j1});
				visited[i1][j1]=true;
				parent[i1][j1].first = top.first;
				parent[i1][j1].second = top.second;
			}
			else if(valid(i1,j1) && a[top.first][top.second]==a[i1][j1] && i1!=parent[top.first][top.second].first && j1!=parent[top.first][top.second].second){
				return true;
			}
		}
	}
	return false;
}

int main(){
	inp();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!visited[i][j]){
				if(BFS(i,j)){
					cout<<"Yess";
					return 0;
				}
			}
		}
	}
	cout<<"No";
	return 0;
}
