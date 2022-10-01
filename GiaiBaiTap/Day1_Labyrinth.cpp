//link: https://cses.fi/problemset/task/1193
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int dx[]={0,-1,1,0};
int dy[]={-1,0,0,1};
int n,m;
char a[1001][1001];
int Free[1001][1001];
int Step[1001][1001];
string Path[1001][1001];

string path;
queue <pair<int,int> > q;
pair <int, int> A;
pair <int, int> B;

int BFS(int i,int j){
	q.push({i,j});
	a[i][j]='#';
	while(!q.empty()){
		pair<int,int> u = q.front();
		q.pop();
		for(int k=0;k<4;k++){
			int i1 = u.first + dx[k];
			int j1 = u.second + dy[k];
			if(i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1]=='.'){
				Step[i1][j1] = Step[u.first][u.second]+1;
				q.push({i1,j1});
				a[i1][j1]='#';
				
				if(dx[k]==0 && dy[k]==-1){
					Path[i1][j1]=Path[u.first][u.second] + "L";
				}
				
				if(dx[k]==-1 && dy[k]==0){
					Path[i1][j1]=Path[u.first][u.second] + "U";
				}
				
				if(dx[k]==1 && dy[k]==0){
					Path[i1][j1]=Path[u.first][u.second] + "D";
				}
				
				if(dx[k]==0 && dy[k]==1){
					Path[i1][j1]=Path[u.first][u.second] + "R";
				}
				
//				if(i1==B.first && j1 ==B.second){
//					return 0;
//				}
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
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='A'){
				A.first =i;
				A.second=j;
				a[i][j]='.';
			}
			if(a[i][j]=='B'){
				B.first = i;
				B.second =j;
				a[i][j]='.';
			}
		}
	}
	
	BFS(A.first,A.second);
	if(a[B.first][B.second]=='.'){
		cout<<"NO!";
	}
	if(a[B.first][B.second]=='#'){
		cout<<"Yes"<<endl;
		cout<<Step[B.first][B.second]<<endl;
		cout<<Path[B.first][B.second];
//		cout<<path.size()<<endl;
//		cout<<path;
	}
	
	return 0;
}
