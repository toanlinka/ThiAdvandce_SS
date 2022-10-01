#include <bits/stdc++.h>
using namespace std;

int Test,m,n,u,v,s;
int a[1001][1001];
int Free[1001];
queue <int> q;

void BFS(int s){
	q.push(s);
	Free[s]=1;
	
	while(!q.empty()){
		u = q.front();
		q.pop();
		
		for(int v=1;v<=n;v++){
			if(Free[v]==0 && a[u][v]==1){
				q.push(v);
				Free[v] = 1;
			}
		}
	}
}

int main(){
	int count =0;
	cin>>Test;
	for(int i=1;i<=Test;i++){
		cin>>n>>m;
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=0;
			}
		}
		
		for(int i=1;i<=n;i++){
			Free[i]=0;
		}
		
		for(int i=1;i<=m;i++){
			cin>>u>>v;
			a[u][v]=1;
			a[v][u]=1;
		}
		 
		for(int i=1;i<=n;i++){
			if(Free[i]==0){
				count++;
				BFS(i);
			}
		}
		
		if(count==1){
			cout<<"YES";
		}
		else{
			cout<<"NO";
		}
		
	}
	return 0;
}
