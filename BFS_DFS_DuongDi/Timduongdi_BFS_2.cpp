//Tim duong di BFS-DFS
#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];
int Free[1001];
int n,m,u,v,Test,s,t;
int Parent[1001];
queue <int> q;
int x,y;

void BFS(int s){
	q.push(s);
	Free[s]=1;
	
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(int v=1;v<=n;v++){
			if(Free[v]==0 && a[u][v]==1){
				Free[v]=1;
				Parent[v]=u;
				q.push(v);
			}
		}
	}
}

void Path(int u, int v){
	BFS(s);
	if(Free[u]==0){
		cout<<"Khong co duong di!";
	}
	else{
		vector <int> path;
		while(t!=s){
			path.push_back(t);
			t = Parent[t];
		}
		path.push_back(s);
		reverse(path.begin(),path.end());
		cout<<"Duong di: ";
		for(int i=0;i<path.size();i++){
			cout<<path[i]<<" ";
		}
	}
}

int main(){
	cin>>Test;
	for(int i=1;i<=Test;i++){
		cin>>n>>m>>s>>t;	
		for(int i=1;i<=n;i++){
			Free[i]=0;
			Parent[i]=0;
			for(int j=1;j<=n;j++){
				a[i][j]==0;
			}
		}
		for(int i=1; i<=m;i++){
			cin>>x>>y;
			a[x][y]=1;
			a[y][x]=1;
		}
		Path(s,t);	
	}
	return 0;
}
